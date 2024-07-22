#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con);

void select_course(MYSQL *con, int student_id, int course_id) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO enrollments (student_id, course_id) VALUES (%d, %d)", student_id, course_id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Course selected successfully.\n");
}

void query_selected_courses(MYSQL *con, int student_id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM enrollments WHERE student_id=%d", student_id);

    if (mysql_query(con, query)) {
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

void query_grades(MYSQL *con, int student_id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM grades WHERE enrollment_id IN (SELECT enrollment_id FROM enrollments WHERE student_id=%d)", student_id);

    if (mysql_query(con, query)) {
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
