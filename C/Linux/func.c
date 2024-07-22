#include <stdio.h>
void hello();
int add (int a ,int b);
int main (){
    hello();
    int i = 1, f=3;
    printf("%d",add(i,f));
    return 0;
}

void hello(){
    printf("hello world !");
}
int add(int a , int b){
    return a + b;
}