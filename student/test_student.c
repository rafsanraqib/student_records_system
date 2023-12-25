/**
 * @file test_student.c
 * @brief Unit tests for the student functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @def ASSERT(condition)
 * @brief Assertion macro to simplify test result printing.
 *
 * This macro checks the given condition and prints "Passed" if true,
 * or "Failed" otherwise.
 *
 * @param condition The condition to check.
 */
#define ASSERT(condition)   \
    if (!(condition))       \
    {                       \
        printf("Failed\n"); \
    }                       \
    else                    \
    {                       \
        printf("Passed\n"); \
    }

/**
 * @brief Run unit tests for the student functions.
 *
 * This function contains several tests for the student functions.
 * It checks the functionality of set and get functions for student attributes.
 */
void run_tests()
{
    struct student s;

    // Test 1: set_student_name and get_student_name
    const char name1[] = "John";
    set_student_name(&s, name1);
    printf("Test 1: ");
    ASSERT(strcmp(get_student_name(s), name1) == 0);

    // Test 2: set_student_name and get_student_name
    const char name2[] = "Alice";
    set_student_name(&s, name2);
    printf("Test 2: ");
    ASSERT(strcmp(get_student_name(s), name2) == 0);

    // Add more tests as needed
}

/**
 * @brief Main function to execute the unit tests.
 *
 * This function calls the run_tests function and prints the test results.
 *
 * @return 0 on successful completion.
 */
int main()
{
    run_tests();

    return 0;
}
