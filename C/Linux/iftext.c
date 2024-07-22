#include<stdio.h>
int main (){
    int i = 1;
    for (int i = 0; i < 50; i++)
    {
        if ( i % 2 == 0  )
        {
            printf("%d是偶数\n",i);
        }
        else if (i == 1)
        {
            printf("捕获到1");
        }
        
        else
        {
            printf("%d是奇数\n",i);
        }
        
    }
    return 0;
}