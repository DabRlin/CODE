#include <stdio.h>
#include <string.h>
typedef struct Person
{
    char name[40];
    int age;
}person;

int main(){
    person person1;
    int len = strlen(person1.name);
    strcpy(person1.name,"Alice");
    char five[9]=" love";
    strcat(person1.name,five);
    printf("%s\n%s",person1.name,five);
    return 0;
}