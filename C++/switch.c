#include <stdio.h>
int main(){
    int number;
    printf("请输入一个数字");
    scanf("%d",&number);
    switch (number)
    {
    case 1:
        printf("这个数字是1");
        break;
    default:
        printf("这个数字不是1");
        break;
    }
    return 0;
}