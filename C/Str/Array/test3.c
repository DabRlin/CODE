#include <stdlib.h>
#include <stdio.h>
int main(){
    int num=8;
    int *arpt = (int*)malloc(num*sizeof(int));
    //判断使用== 而不是使用赋值 =
    if (arpt == NULL)
    {
        printf("内存分配失败");
        return 1;
    }
    for (int i = 0; i < num; i++)
    {
        *(arpt+i)=i+1;
    }
    for (int j = 0; j < num; j++)
    {
        printf("%d ",*(arpt+j));
    }
    
    
    return 0;
}