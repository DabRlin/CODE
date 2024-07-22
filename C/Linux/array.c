#include <stdio.h>
int main (){
    int i[10]={10,11,14,15,55};
    for (int j = 0; j < sizeof(i)/sizeof(i[0]-1); j++)
    {
        printf("%d ",i[j]);
    }
    

    return 0;
}