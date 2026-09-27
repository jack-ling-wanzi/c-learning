/* J. David Blackstone 编写的 tinyhttpd，针对现代 Linux 进行了微调与注释 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#

#define PORT 4000
#define BACKLOG 10
#define MAXLINE 1024
#define SERVER_STRING "Server: tinyhttpd/0.1.0\r\n"

/* 函数声明 */
void *accept_request(void *);
void bad_request(int);
void cat(int, FILE *);
void cannot_execute(int);
void error_die(const char *);
void execute_cgi(int, const char *, const char *, const char *);
int get_line(int, char *, int);
void headers(int, const char *);
void not_found(int);
void serve_file(int, const char *);
int startup(u_short *);
void unimplemented(int);

/* ------------------------------------------------------
 * 处理客户端连接的线程入口函数 (对应多线程并发)
 * ------------------------------------------------------ */
void *accept_request(void *client_sock) {
    int client = *(int *)client_sock;
    char buf[MAXLINE];
    int numchars;
    char method[255];
    char url[255];
    char path[512];
    size_t i, j;
    struct stat st;
    int cgi = 0; /* 是否为 CGI 程序的标志 */
    char *query_string = NULL;

    /* 1. 读取 HTTP 请求的第一行，例如 "GET /index.html HTTP/1.1" */
    numchars = get_line(client, buf, sizeof(buf));
    i = 0; j = 0;
    /* 提取请求方法 (GET/POST) */
    while (!isspace((unsigned char)buf[i]) && (i < sizeof(method) - 1)) {
        method[i] = buf[i];
        i++;
    }
    method[i] = '\0';

    /* 如果既不是 GET 也不是 POST，返回未实现 */
    if (strcasecmp(method, "GET") && strcasecmp(method, "POST")) {
        unimplemented(client);
        close(client);
        return NULL;
    }

    /* POST 请求默认开启 CGI 处理 */
    if (strcasecmp(method, "POST") == 0) {
        cgi = 1;
    }

    /* 跳过空格，提取 URL */
    i = 0;
    while (isspace((unsigned char)buf[i]) && (i < sizeof(buf))) i++;
    while (!isspace((unsigned char)buf[i]) && (i < sizeof(url) - 1) && (i < sizeof(buf))) {
        url[i] = buf[i];
        i++;
    }
    url[i] = '\0';

    /* 如果是 GET 请求且 URL 中带有 '?'，说明有查询参数，按 CGI 处理 */
    if (strcasecmp(method, "GET") == 0) {
        query_string = url;
        while (*query_string != '?' && *query_string != '\0') query_string++;
        if (*query_string == '?') {
            cgi = 1;
            *query_string = '\0';
            query_string++; /* query_string 指向参数部分 */
        }
    }

    /* 2. 构建本地文件路径。URL 前缀拼接为当前目录 */
    sprintf(path, "htdocs%s", url);

    /* 如果 URL 以 '/' 结尾，默认访问 index.html */
    if (path[strlen(path) - 1] == '/') {
        strcat(path, "index.html");
    }

    /* 检查文件是否存在 */
    if (stat(path, &st) == -1) {
        /* 如果文件不存在，把剩余的 HTTP 请求头读完并丢弃 */
        while ((numchars > 0) && strcmp("\n", buf)) {
            numchars = get_line(client, buf, sizeof(buf));
        }
        not_found(client);
    } else {
        /* 如果是个目录，且没有以 '/' 结尾，或者是个可执行文件，开启 CGI */
        if ((st.st_mode & S_IFMT) == S_IFDIR) {
            strcat(path, "/index.html");
        }
        if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH)) {
            cgi = 1;
        }
        if (!cgi) {
            /* 静态文件服务 */
            serve_file(client, path);
        } else {
            /* 读取剩余请求头，交给 CGI 执行 */
            while ((numchars > 0) && strcmp("\n", buf)) {
                numchars = get_line(client, buf, sizeof(buf));
            }
            execute_cgi(client, path, method, query_string);
        }
    }

    close(client);
    return NULL;
}

/* ------------------------------------------------------
 * 执行 CGI 脚本 (核心动态处理逻辑，也是未来CTF渗透的常见突破口)
 * ------------------------------------------------------ */
void execute_cgi(int client, const char *path, const char *method, const char *query_string) {
    char buf[MAXLINE];
    int cgi_output[2];
    int cgi_input[2];
    pid_t pid;
    int status, i, numchars;
    char c;

    /* 创建匿名管道：父进程向子进程传数据，子进程向父进程传结果 */
    if (pipe(cgi_output) < 0 || pipe(cgi_input) < 0) {
        cannot_execute(client);
        return;
    }

    if ((pid = fork()) < 0) {
        cannot_execute(client);
        return;
    }

    if (pid == 0) { /* 子进程：执行 CGI */
        dup2(cgi_output[1], STDOUT_FILENO); /* 标准输出重定向到管道读端 */
        dup2(cgi_input[0], STDIN_FILENO);   /* 标准输入重定向到管道写端 */
        close(cgi_output[0]);
        close(cgi_input[1]);

        /* 设置环境变量 QUERY_STRING (经典的 GET 传参方式) */
        if (strcasecmp(method, "GET") == 0) {
            char env[255];
            sprintf(env, "QUERY_STRING=%s", query_string ? query_string : "");
            putenv(env);
            execl(path, path, NULL); /* 执行 CGI 程序 */
        }
    } else { /* 父进程：处理输入输出 */
        close(cgi_output[1]);
        close(cgi_input[0]);

        /* POST 请求：把 body 写入 CGI 的 stdin */
        if (strcasecmp(method, "POST") == 0) {
            /* 跳过 HTTP 头 (找到空行 \r\n) */
            while ((numchars > 0) && strcmp("\n", buf)) {
                numchars = get_line(client, buf, sizeof(buf));
            }
            while ((numchars > 0)) {
                write(cgi_input[1], buf, numchars);
                numchars = get_line(client, buf, sizeof(buf));
            }
        }
        
        /* 发送给浏览器 HTTP 状态码 */
        headers(client, "200 OK");
        
        /* 读取 CGI 执行结果并返回给浏览器 */
        while (read(cgi_output[0], &c, 1) > 0) {
            write(client, &c, 1);
        }
        
        close(cgi_output[0]);
        close(cgi_input[1]);
        waitpid(pid, &status, 0);
    }
}

/* 辅助函数：读取一行数据 */
int get_line(int sock, char *buf, int size) {
    int i = 0;
    char c = '\0';
    int n;
    while ((i < size - 1) && (c != '\n')) {
        n = recv(sock, &c, 1, 0);
        if (n > 0) {
            if (c == '\r') {
                n = recv(sock, &c, 1, MSG_PEEK); /* 窥视下一个字符 */
                if ((n > 0) && (c == '\n')) {
                    recv(sock, &c, 1, 0); /* 确认是 \r\n，消耗掉 */
                } else {
                    c = '\n'; /* 只有 \r，补个 \n */
                }
            }
            buf[i] = c;
            i++;
        } else {
            c = '\n'; /* 连接断开了 */
        }
    }
    buf[i] = '\0';
    return i;
}

/* 发送 HTTP 响应头 */
void headers(int client, const char *filename) {
    char buf[1024];
    (void)filename; /* 这里没用到 filename，防止编译警告 */
    strcpy(buf, "HTTP/1.0 200 OK\r\n");
    send(client, buf, strlen(buf), 0);
    strcpy(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    strcpy(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
}

/* 静态文件服务：把文件读出来发到 socket */
void serve_file(int client, const char *filename) {
    FILE *resource = NULL;
    int numchars = 1;
    char buf[MAXLINE];

    /* 把请求头读完 */
    while ((numchars > 0) && strcmp("\n", buf)) {
        numchars = get_line(client, buf, sizeof(buf));
    }

    resource = fopen(filename, "r");
    if (resource == NULL) {
        not_found(client);
    } else {
        headers(client, filename);
        cat(client, resource); /* 核心：把文件内容输出到 socket */
    }
    fclose(resource);
}

/* 文件传输：从 FILE 流拷贝到 socket */
void cat(int client, FILE *resource) {
    char buf[1024];
    while (fgets(buf, sizeof(buf), resource) != NULL) {
        send(client, buf, strlen(buf), 0);
    }
}

/* 错误处理函数组 */
void error_die(const char *sc) {
    perror(sc);
    exit(1);
}

void not_found(int client) {
    char buf[1024];
    sprintf(buf, "HTTP/1.0 404 NOT FOUND\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><TITLE>Not Found</TITLE>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>The server could not fulfill your request.</P>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(client, buf, strlen(buf), 0);
}

void unimplemented(int client) {
    char buf[1024];
    sprintf(buf, "HTTP/1.0 501 Method Not Implemented\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><HEAD><TITLE>Method Not Implemented\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</TITLE></HEAD>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>HTTP request method not supported.\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(client, buf, strlen(buf), 0);
}

/* ------------------------------------------------------
 * 主函数：Socket 初始化与主循环
 * ------------------------------------------------------ */
int main(void) {
    int server_sock = -1;
    u_short port = PORT;
    int client_sock = -1;
    struct sockaddr_in client_name;
    socklen_t client_name_len = sizeof(client_name);
    pthread_t newthread;

    server_sock = startup(&port);
    printf("httpd running on port %d\n", port);

    while (1) {
        /* 阻塞等待客户端连接 */
        client_sock = accept(server_sock, (struct sockaddr *)&client_name, &client_name_len);
        if (client_sock == -1) {
            error_die("accept");
        }
        /* 为每个连接创建一个新线程处理 */
        if (pthread_create(&newthread, NULL, accept_request, &client_sock) != 0) {
            perror("pthread_create");
        }
    }
    close(server_sock);
    return 0;
}

/* 初始化 Socket 并开始监听 */
int startup(u_short *port) {
    int httpd = 0;
    struct sockaddr_in name;

    httpd = socket(PF_INET, SOCK_STREAM, 0);
    if (httpd == -1) error_die("socket");
    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_port = htons(*port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(httpd, (struct sockaddr *)&name, sizeof(name)) < 0)
        error_die("bind");
    if (*port == 0) {
        socklen_t namelen = sizeof(name);
        if (getsockname(httpd, (struct sockaddr *)&name, &namelen) == -1)
            error_die("getsockname");
        *port = ntohs(name.sin_port);
    }
    if (listen(httpd, 5) < 0) error_die("listen");
    return httpd;
}