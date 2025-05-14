**🎓 University Management System **

This is a console-based University Management System built using C++ and connected to a MySQL database. It allows basic operations like adding, viewing, updating, searching, and deleting student records.

---

## 📌 Features

- Add new student records
- Display all student data
- Search student by ID
- Update student subject
- Delete student by ID
- MySQL database connectivity using MySQL C API

---

## 🛠 Tech Stack

- **Language:** C++
- **Database:** MySQL (via MySQL Server)
- **Connector:** MySQL Connector/C 6.1
- **Compiler:** Dev C++

---

## 🗃 Database Setup

1. Start your MySQL server (via XAMPP or standalone MySQL).
2. Create the database and table using the following SQL script (also in `student_table.sql`):

```sql
CREATE DATABASE mydb;

USE mydb;

CREATE TABLE student (
    Id INT PRIMARY KEY,
    Name VARCHAR(100),
    Subject VARCHAR(100),
    CGPA FLOAT
);


