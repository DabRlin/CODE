#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    int num = 12345;
    float fnum = 67.89;

    // 使用 sprintf 将数据格式化为字符串
    sprintf(buffer, "Integer: %d, Float: %.1f", num, fnum);
    printf("Formatted string: %s\n", buffer);
    strcpy(buffer,"Integer: 100, Float: 1000");
    // 使用 sscanf 从字符串中按格式读取数据
    int parsed_num;
    float parsed_fnum;
    sscanf(buffer, "Integer: %d, Float: %f", &parsed_num, &parsed_fnum);
    printf("Parsed values: Integer = %d, Float = %.2f\n", parsed_num, parsed_fnum);

    return 0;
}
