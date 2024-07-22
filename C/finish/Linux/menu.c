#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

extern void finish_with_error(MYSQL *con);
extern MYSQL *connect_database();
extern int admin_login(MYSQL *con, const char *login_name, const char *password);
extern int student_login(MYSQL *con, const char *login_name, const char *password);

extern void add_student(MYSQL *con, const char *name, const char *login_name, const char *password, const char *class);
extern void delete_student(MYSQL *con, int student_id);
extern void update_student(MYSQL *con, int student_id, const char *name, const char *class);
extern void query_students(MYSQL *con);

extern void select_course(MYSQL *con, int student_id, int course_id);
extern void query_selected_courses(MYSQL *con, int student_id);
extern void query_grades(MYSQL *con, int student_id);

void admin_menu(MYSQL *con)
{
    int choice;
    while (1)
    {
        printf("\nAdmin Menu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Query Students\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // 示例：add_student(con, "John Doe", "john", "password123", "Class A");
            break;
        case 2:
            // 示例：delete_student(con, 1);
            break;
        case 3:
            // 示例：update_student(con, 1, "John Doe", "Class B");
            break;
        case 4:
            query_students(con);
            break;
        case 0:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

void student_menu(MYSQL *con, int student_id)
{
    int choice;
    while (1)
    {
        printf("\nStudent Menu:\n");
        printf("1. Select Course\n");
        printf("2. Query Selected Courses\n");
        printf("3. Query Grades\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // 示例：select_course(con, student_id, 101);
            break;
        case 2:
            query_selected_courses(con, student_id);
            break;
        case 3:
            query_grades(con, student_id);
            break;
        case 0:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

int main()
{
    MYSQL *con = connect_database();

    char login_name[100];
    char password[100];
    int user_type;

    printf("Enter login name: ");
    scanf("%s", login_name);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Select user type (1 for Admin, 2 for Student): ");
    scanf("%d", &user_type);

    if (user_type == 1)
    {
        if (admin_login(con, login_name, password))
        {
            printf("Login successful. Welcome, Admin!\n");
            admin_menu(con);
        }
        else
        {
            printf("Login failed. Invalid login name or password.\n");
        }
    }
    else if (user_type == 2)
    {

        if (student_login(con, login_name, password))
        {
            printf("Login successful. Welcome, Student!\n");

            // 获取学生ID，用于后续功能调用
            char query[256];
            snprintf(query, sizeof(query), "SELECT student_id FROM students WHERE user_id=(SELECT user_id FROM users WHERE login_name='%s')", login_name);

            if (mysql_query(con, query))
            {
                finish_with_error(con);
            }

            MYSQL_RES *result = mysql_store_result(con);
            if (result == NULL)
            {
                finish_with_error(con);
            }

            MYSQL_ROW row = mysql_fetch_row(result);
            int student_id = atoi(row[0]);
            mysql_free_result(result);

            student_menu(con, student_id);
        }
        else
        {
            printf("Login failed. Invalid login name or password.\n");
        }
    }
    else
    {
        printf("Invalid user type selected.\n");
    }

    mysql_close(con);
    return 0;
}
