FROM postgres:latest

# Set environment variables for PostgreSQL
ENV POSTGRES_DB student_records
ENV POSTGRES_USER rafsan
ENV POSTGRES_PASSWORD mypassword

# Copy the SQL script to initialize the database
COPY init.sql /docker-entrypoint-initdb.d/

COPY . /student_records

WORKDIR /student_records/

# Install necessary dependencies for the C program
RUN apt-get update && apt-get install -y gcc && apt-get install -y make

RUN apt-get install -y libpq-dev
