#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr;
    ptr = (int*)malloc(10*sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = i;
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d",ptr[j]);
    }
    

    return 0;
}