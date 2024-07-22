#include<stdio.h>
int main(){
    for (int i = 1; i <= 9; i++)
    {int f = 1;
        for (f = 1; f <= i; f++)
        {
            printf("%d*%d=%d ",i,f,i*f);
        }
        printf("\n");
    }
    return 0;
}