#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con);

void add_student(MYSQL *con, const char *name, const char *login_name, const char *password, const char *class) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO users (login_name, password, user_type) VALUES ('%s', '%s', 'student')", login_name, password);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    int user_id = mysql_insert_id(con);

    snprintf(query, sizeof(query), "INSERT INTO students (name, user_id, class) VALUES ('%s', %d, '%s')", name, user_id, class);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Student added successfully.\n");
}

void delete_student(MYSQL *con, int student_id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM students WHERE student_id=%d", student_id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    snprintf(query, sizeof(query), "DELETE FROM users WHERE user_id=(SELECT user_id FROM students WHERE student_id=%d)", student_id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Student deleted successfully.\n");
}

void update_student(MYSQL *con, int student_id, const char *name, const char *class) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE students SET name='%s', class='%s' WHERE student_id=%d", name, class, student_id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Student updated successfully.\n");
}

void query_students(MYSQL *con) {
    if (mysql_query(con, "SELECT * FROM students")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}
