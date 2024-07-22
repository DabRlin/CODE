#include <stdio.h>
int main(){
    int i;
    scanf("%d",&i);
    int j = i%2;
    switch (j)
    {
    case 0:
        printf("输入的数字为偶数");
        break;
    
    default:
        printf("输入数字为奇数");
        break;
    }
    return 0;
}