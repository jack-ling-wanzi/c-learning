#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("用法: %s <文件名>\n", argv[0]);
        return 1;
    }

    // 关键：必须用 "rb" 二进制模式，否则在 Windows 下遇到 0x1A 会提前停止
    FILE *fp = fopen(argv[1], "rb");//file 是什么，rb是什么
    if (!fp) {
        perror("打开文件失败");//perror什么意思
        return 1;
    }

    unsigned char header[8] = {0};//即{0,0,0,0,0,0,0,0}对吗？
    size_t read_bytes = fread(header, 1, 8, fp);//fread什么意思
    fclose(fp);

    if (read_bytes < 8) {
        printf("文件长度不足 8 字节\n");
        return 1;
    }

    printf("文件 %s 的前 8 个字节(十六进制): ", argv[1]);
    for (int i = 0; i < 8; i++) {
        printf("%02x ", header[i]);
    }
    printf("\n");

    return 0;
}