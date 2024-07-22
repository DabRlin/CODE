#include <stdio.h>
int main(){
    int num = 10;
    int *point = &num;
    printf("%d %p %p %d",num, &num,point,*point);
    return 0;
}