#include <stdio.h>

void swap(int *a, int *b);

struct Student
{
    char name[20];
    int age;
};

int main (){
    struct Student student1={"Alice",5};
    struct Student *point1 = &student1;
    
    printf("Person's name: %s\n",point1->name);
    printf("Person's age : %d\n",point1->age);

    int arr [5] = {1,2,3,4,5};
    int *point = arr;
    for (int i = 0; i < 5; i++)
    {
        printf("%d",*(point + i));
    }
    
    return 0;
}

void swap (int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}