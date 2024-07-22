#include<stdio.h>
main(){
    int c , count = 0 ;
    // c=getchar();
    while((c = getchar()) != EOF){
        putchar(c);
        putchar(c);
        count++;
    }
    printf("\n%d",count);
}