#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./student/student.h"
#include "./database/database_save.h"

int main()
{
	while (1)
	{
		char user_input[200];
		PGconn *conn = setup_database();

		printf("============ Welcome to Student Record Management System ===============\n");
		printf("1. Add a new Student\n");
		printf("2. Show all Students\n");
		printf("3. Exit Program\n");
		fgets(user_input, sizeof(user_input), stdin);

		if (strcmp(user_input, "1\n") == 0)
		{
			printf("Enter Student Infomation(name,age,gpa,grade): ");
			fgets(user_input, sizeof(user_input), stdin);

			struct student *s1 = create_struct_student(user_input);

			save_student(conn, s1);
			free(s1);
		}
		else if (strcmp(user_input, "2\n") == 0)
		{
			char *res = database_get_students(conn);
			printf("\n%s\n", res);
			free(res);
		}

		else if (strcmp(user_input, "3\n") == 0)
		{
			PQfinish(conn);
			break;
		}
	}
}
