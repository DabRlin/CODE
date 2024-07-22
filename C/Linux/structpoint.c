#include <stdio.h>
typedef struct Persons {
    char name[50];
    int age;
    float height;
} Person;

int main(){
    Person persons[2] = {{"Alice", 30, 5.7}, {"Bob", 25, 6.0}};

    Person *personPtr = persons;
for (int i = 0; i < 2; i++) {
    printf("Name: %s, Age: %d, Height: %.1f\n", personPtr->name, personPtr->age, personPtr->height);
    personPtr++;
}
return 0;
}