#include<stdio.h>
int main(){
    int i=1, j = 1;
    while (i <= 9)
    {
        j = 1;
        while (j <= i)
    {
        printf("%d*%d=%d ",j,i,i*j);
        j++;
    }
    printf("\n");
        i++;
    }
    return 0;
}