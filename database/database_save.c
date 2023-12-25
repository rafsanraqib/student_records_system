#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database_save.h"
#include <../../usr/include/postgresql/libpq-fe.h>

#define BUDGET_DATABASE_URL "postgresql://rafsan:rafsan97@localhost:5432/budget_records";
#define DATABASE_PORT_NO 5432;

void do_exit(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

PGconn *setup_database()
{
    PGconn *conn = PQconnectdb("user=rafsan dbname=student_records");

    if (PQstatus(conn) == CONNECTION_BAD)
    {
        fprintf(stderr, "Connection to database failed: %s\n",
                PQerrorMessage(conn));
        do_exit(conn);
    }

    return conn;
}

void save_student(PGconn *conn, struct student *student_)
{

    const char *paramValues[4] = {student_->student_name, student_->student_age, student_->student_gpa, student_->student_grade};

    PGresult *res = PQexecParams(conn,
                                 "INSERT INTO students (student_name, student_age, student_gpa, student_grade) VALUES ($1, $2, $3, $4);",
                                 4,
                                 NULL,
                                 paramValues,
                                 NULL,
                                 NULL,
                                 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "Query execution failed: %s\n", PQerrorMessage(conn));
        PQclear(res);
        do_exit(conn);
    }

    PQclear(res);
    PQfinish(conn);
};

char *database_get_students(PGconn *conn)
{
    char *sql = "SELECT * from students;";

    PGresult *res = PQexec(conn, sql);
    // Check if the query was successful
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "Query execution failed: %s", PQresultErrorMessage(res));
        PQclear(res);
        PQfinish(conn);
        return NULL;
    }

    int rows = PQntuples(res);
    char *student_data = (char*) malloc(2000); // Increased size to accommodate larger data
    student_data[0] = '\0';

    for (int i = 0; i < rows; i++)
    {
        strcat(student_data, PQgetvalue(res, i, 1));
        strcat(student_data, ",");
        strcat(student_data, PQgetvalue(res, i, 2));
        strcat(student_data, ",");
        strcat(student_data, PQgetvalue(res, i, 3));
        strcat(student_data, "\n");
    };

    return student_data;
};
