#include <stdio.h>
#include <string.h>

void check_password() {
    // 定义一个只有4个字节的缓冲区 (数组)
    char buffer[4] = "ABC"; 
    // 紧挨着它定义一个"验证开关"，假设0是拒绝，1是放行
    // 在内存中，这两个变量在栈上通常是挨着的！
    int auth_flag = 0; 

    printf("请输入密码 (多输入几个字符看看会发生什么): ");
    // 危险的写法，不检查长度！模拟黑客提供超长字符串
    scanf("%s", buffer); 
    
    // 打印内存地址，你将看到 buffer 和 auth_flag 挨得有多近
    printf("Buffer 的地址: %p\n", buffer);
    printf("auth_flag 的地址: %p\n", &auth_flag);

    // 黑客的目标是修改 auth_flag！
    if (auth_flag == 0) {
        printf("\n[!] 验证失败！程序拒绝访问！\n");
    } else {
        printf("\n[+] 警告！验证被绕过！系统授予最高权限！\n");
    }
}

int main() {
    check_password();
    return 0;
}