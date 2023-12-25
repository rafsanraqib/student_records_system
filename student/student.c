/**
 * @file student.c
 * @brief Functions to manage student information.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

/**
 * @brief Set the name of a student.
 *
 * This function sets the name of a student by allocating memory
 * for the name and copying the provided string.
 *
 * @param s Pointer to the student structure.
 * @param name Pointer to the string containing the name.
 */
void set_student_name(struct student *s, const char *name)
{
	s->student_name = strdup(name);
}

/**
 * @brief Get the name of a student.
 *
 * This function returns a pointer to the name of the student.
 *
 * @param s The student structure.
 * @return Pointer to the name of the student.
 */
char *get_student_name(struct student s)
{
	return s.student_name;
}

/**
 * @brief Set the age of a student.
 *
 * This function sets the age of a student by allocating memory
 * for the age and copying the provided string.
 *
 * @param s Pointer to the student structure.
 * @param age Pointer to the string containing the age.
 */
void set_student_age(struct student *s, const char *age)
{
	s->student_age = strdup(age);
}

/**
 * @brief Get the age of a student.
 *
 * This function returns a pointer to the age of the student.
 *
 * @param s The student structure.
 * @return Pointer to the age of the student.
 */
char *get_student_age(struct student s)
{
	return s.student_age;
}

/**
 * @brief Set the grade of a student.
 *
 * This function sets the grade of a student by allocating memory
 * for the grade and copying the provided string.
 *
 * @param s Pointer to the student structure.
 * @param grade Pointer to the string containing the grade.
 */
void set_student_grade(struct student *s, const char *grade)
{
	s->student_grade = strdup(grade);
}

/**
 * @brief Get the grade of a student.
 *
 * This function returns a pointer to the grade of the student.
 *
 * @param s The student structure.
 * @return Pointer to the grade of the student.
 */
char *get_student_grade(struct student s)
{
	return s.student_grade;
}

/**
 * @brief Set the GPA of a student.
 *
 * This function sets the GPA of a student by allocating memory
 * for the GPA and copying the provided string.
 *
 * @param s Pointer to the student structure.
 * @param gpa Pointer to the string containing the GPA.
 */
void set_student_gpa(struct student *s, const char *gpa)
{
	s->student_gpa = strdup(gpa);
}

/**
 * @brief Get the GPA of a student.
 *
 * This function returns a pointer to the GPA of the student.
 *
 * @param s The student structure.
 * @return Pointer to the GPA of the student.
 */
char *get_student_gpa(struct student s)
{
	return s.student_gpa;
}

struct student *create_struct_student(char *user_input)
{
	struct student *s = malloc(sizeof(struct student));
	char *token;
	int counter = 0;
	token = strtok(user_input, ",");

	while (token != NULL)
	{
		if (counter == 0)
		{
			s->student_name = token;
		}
		else if (counter == 1)
		{
			s->student_age = token;
		}
		else if (counter == 2)
		{
			s->student_gpa = token;
		}
		else if (counter == 3)
		{
			s->student_grade = token;
		}
		counter++;
		token = strtok(NULL, ",");
	};

	return s;
}
