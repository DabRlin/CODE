#include <stdio.h>
void mac(int a[],int b);
int main(){
    int array[5]={1,2,3,4,5};
    for (int i = 0; i < 4; i++)
    {
        printf("%d",array[i]);
    }
     int *point = array;
     for (int  j = 0; j < 5; j++)
     {
        printf("%d\n",*(point+j));
     }
     printf("%d",sizeof(array));
     mac(array,sizeof(array)/sizeof(array[0]));
    return 0;
}
void mac(int a[],int b){
    int max = a[0];
    for (int i = 1; i < b; i++)
    {
        if (a[i]>=max)
        {
            max = a[i];
        }
    }
    printf("%d",max);
}