#include <stdio.h>
#include <string.h>
struct student
{
    int age ;
    char name[35];
};

int main(){
    struct student student1;
    student1.age = 10;
    char ame[100] = "cjemjpm";
    strcpy(student1.name,ame);
    printf("%s  %d",student1.name,student1.age);
    return 0;
}