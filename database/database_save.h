#ifndef DATABASE_SAVE_H
#define DATABASE_SAVE_H

#include <../../usr/include/postgresql/libpq-fe.h>
#include "../student/student.h"

void do_exit(PGconn *con);
PGconn *setup_database();
void save_student(PGconn *conn, struct student *student);
char *database_get_students(PGconn *conn);

#endif
