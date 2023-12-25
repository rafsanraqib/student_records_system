# Makefile
# This Makefile is used to compile and run the student program and tests.

# Compiler
CC=gcc

# Default target: Build both student and tests
all: student_module student_test_module test

# Build the studene program
student_module: ./student/student.c
	$(CC) -o main  main.c ./student/student.c ./database/database_save.c -I /opt/homebrew/opt/postgresql@15/include/ -L /opt/homebrew/opt/postgresql@15/lib -lpq

# Run the student program
run: 
	./main

# Clean up compiled files
clean: 
	rm -f main test_student

# Build the test program
student_test_module:./student/student.c ./student/test_student.c
	$(CC) -o test_student ./student/student.c ./student/test_student.c

# Run the test program
test: test_student
	./test_student
