CREATE ROLE root;

\c student_records;

CREATE TABLE IF NOT EXISTS students (
	student_id serial PRIMARY KEY,
	student_name VARCHAR(50) NOT NULL,
	student_age VARCHAR(10) NOT NULL,
	student_grade VARCHAR(10) NOT NULL, 
	student_gpa VARCHAR(10) NOT NULL
);

INSERT INTO students(student_name, student_age, student_gpa, student_grade) VALUES
	('Ahmed Rafsan Raqib', '26', '4.55', '12'),
	('Luka Modric', '38', '4.22', '13'),
	('John Doe', '14', '4.22','12');

GRANT SELECT ON TABLE students TO rafsan;




