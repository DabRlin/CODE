#include <stdio.h>
#include <string.h>

int main() {
    // 示例数据
    int num = 10;
    char input_string[] = "The number is 20";
    char buffer[100];

    // 使用 printf 输出到控制台
    printf("Printing using printf: The number is %d\n", num);

    // 使用 scanf 从控制台读取数据
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);

    // 使用 sprintf 将格式化数据写入字符串
    sprintf(buffer, "Formatted string: The number is %d", num);
    printf("Using sprintf: %s\n", buffer);

    // 使用 sscanf 从字符串中按格式读取数据
    int parsed_num;
    sscanf(input_string, "The number is %d", &parsed_num);
    printf("Using sscanf: Parsed number from string: %d\n", parsed_num);

    return 0;
}
