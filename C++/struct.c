#include <stdio.h>
struct student
{
    char name[50] ;
    int age;
};
typedef struct teacher{
    int teacher_id ;
    char teacher_name[50];
    int age;
}teacherinfo;
int main(){
    printf("hello world");
    struct student student1;
    teacherinfo teacher1 ;
    teacher1.teacher_id=111;
    teacher1.age=10;
    printf("");
    return 0;
}