/**
 * @file student.h
 * @brief Header file defining the student structure and related functions.
 */

#ifndef STUDENT_H
#define STUDENT_H

/**
 * @struct student
 * @brief Structure representing a student with various attributes.
 *
 * The student structure contains pointers to strings representing
 * the student's name, age, grade, and GPA.
 */
struct student
{
	char *student_name;	 /**< Pointer to the student's name string. */
	char *student_age;	 /**< Pointer to the student's age string. */
	char *student_grade; /**< Pointer to the student's grade string. */
	char *student_gpa;	 /**< Pointer to the student's GPA string. */
};

/**
 * @brief Set the name of a student.
 *
 * This function allocates memory for the name and copies the provided string.
 *
 * @param s Pointer to the student structure.
 * @param name Pointer to the string containing the name.
 */
void set_student_name(struct student *s, const char *name);

/**
 * @brief Get the name of a student.
 *
 * This function returns a pointer to the name of the student.
 *
 * @param s The student structure.
 * @return Pointer to the name of the student.
 */
char *get_student_name(struct student s);

/**
 * @brief Set the age of a student.
 *
 * This function allocates memory for the age and copies the provided string.
 *
 * @param s Pointer to the student structure.
 * @param age Pointer to the string containing the age.
 */
void set_student_age(struct student *s, const char *age);

/**
 * @brief Get the age of a student.
 *
 * This function returns a pointer to the age of the student.
 *
 * @param s The student structure.
 * @return Pointer to the age of the student.
 */
char *get_student_age(struct student s);

/**
 * @brief Set the grade of a student.
 *
 * This function allocates memory for the grade and copies the provided string.
 *
 * @param s Pointer to the student structure.
 * @param grade Pointer to the string containing the grade.
 */
void set_student_grade(struct student *s, const char *grade);

/**
 * @brief Get the grade of a student.
 *
 * This function returns a pointer to the grade of the student.
 *
 * @param s The student structure.
 * @return Pointer to the grade of the student.
 */
char *get_student_grade(struct student s);

/**
 * @brief Set the GPA of a student.
 *
 * This function allocates memory for the GPA and copies the provided string.
 *
 * @param s Pointer to the student structure.
 * @param gpa Pointer to the string containing the GPA.
 */
void set_student_gpa(struct student *s, const char *gpa);

/**
 * @brief Get the GPA of a student.
 *
 * This function returns a pointer to the GPA of the student.
 *
 * @param s The student structure.
 * @return Pointer to the GPA of the student.
 */
char *get_student_gpa(struct student s);

struct student *create_struct_student(char *user_input);

#endif // STUDENT_H
