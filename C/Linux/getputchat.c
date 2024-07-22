#include <stdio.h>

int main() {
    char ch;

    // 从键盘读取一个字符并输出到屏幕
    printf("Enter a character: ");
    ch = getchar();
    printf("You entered: ");
    putchar(ch);

    return 0;
}
