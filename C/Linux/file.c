#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // 打开文件以写入
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 写入字符到文件
    fputs("mojap", fp);
    fputc('B', fp);
    fputc('C', fp);

    // 关闭文件
    fclose(fp);

    // 打开文件以读取
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 读取并显示文件内容
    printf("File content: ");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // 关闭文件
    fclose(fp);

    return 0;
}
