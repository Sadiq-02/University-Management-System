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

**Output Screenshots **

![Screenshot 2025-05-14 215918](https://github.com/user-attachments/assets/058dc40a-0747-4fe6-909e-195efff75711)


![Screenshot 2025-05-14 220029](https://github.com/user-attachments/assets/86d581b0-143f-4607-90cd-115c74377f64)


![Screenshot 2025-05-14 220124](https://github.com/user-attachments/assets/a290a2c8-557f-4aaa-b8ff-c0d2b6d58718)


