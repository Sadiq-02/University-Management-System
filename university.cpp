#include <iostream>
#include <mysql.h>
#include <errmsg.h>
#include <windows.h>
#include <sstream>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "##########";  //Enter your MySQL password here
const char* DB = "mydb";

class University {
private:
    int Id;
    string Name, Subject;
    float CGPA;
public:
    University() : Id(0), Name(""), Subject(""), CGPA(0.0) {}

    void setId(int id) { Id = id; }
    void setName(string name) { Name = name; }
    void setSubject(string subject) { Subject = subject; }
    void setGrade(float cgpa) { CGPA = cgpa; }

    int getId() { return Id; }
    string getName() { return Name; }
    string getSubject() { return Subject; }
    float getGrade() { return CGPA; }
};

// Insert function
void insertS(MYSQL* conn, University u) {
    int id;
    string name, subject;
    float cgpa;

    cout << "Enter Id: ";
    cin >> id;
    u.setId(id);
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);
    u.setName(name);

    cout << "Enter Subject: ";
    getline(cin, subject);
    u.setSubject(subject);

    cout << "Enter CGPA: ";
    cin >> cgpa;
    u.setGrade(cgpa);

    stringstream ssId, ssCgpa;
    ssId << u.getId();
    ssCgpa << u.getGrade();

    string query = "INSERT INTO student (Id, Name, Subject, CGPA) VALUES ('" + ssId.str() + "', '" + u.getName() + "', '" + u.getSubject() + "', '" + ssCgpa.str() + "')";

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Inserted Successfully." << endl;
    }

    Sleep(3000);
}

// Show all records
void showRecord(MYSQL* conn) {
    string query = "SELECT * FROM student";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num; i++) {
                    cout << " " << row[i];
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(5000);
}

// Search by ID
void searchS(MYSQL* conn) {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    stringstream ss;
    ss << id;

    string query = "SELECT * FROM student WHERE Id = '" + ss.str() + "'";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                int num = mysql_num_fields(res);
                for (int i = 0; i < num; i++) {
                    cout << " " << row[i];
                }
                cout << endl;
            } else {
                cout << "No student found." << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(5000);
}

// Update student subject
void updateS(MYSQL* conn, University u) {
    int id;
    cout << "Enter Id: ";
    cin >> id;
    cin.ignore();

    string subject;
    cout << "Enter New Subject: ";
    getline(cin, subject);
    u.setSubject(subject);

    stringstream ss;
    ss << id;

    string query = "UPDATE student SET Subject = '" + u.getSubject() + "' WHERE Id = '" + ss.str() + "'";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Updated Successfully." << endl;
    }

    Sleep(3000);
}

// Delete student
void deleteS(MYSQL* conn) {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    stringstream ss;
    ss << id;

    string query = "DELETE FROM student WHERE Id = '" + ss.str() + "'";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Deleted." << endl;
    }

    Sleep(3000);
}

int main() {
    University u;
    MYSQL* conn;
    conn = mysql_init(NULL);

    mysql_ssl_set(conn, NULL, NULL, NULL, NULL, NULL);

    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, CLIENT_SSL_DISABLED)){
    cout << "Error: " << mysql_error(conn) << endl;
    return 1;
    } else {
    cout << "Logged in!" << endl;
    }
    Sleep(3000);

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "Welcome to University Management System" << endl;
        cout << "***************************************" << endl;
        cout << "1. Insert Student Data" << endl;
        cout << "2. Show Student Data" << endl;
        cout << "3. Search Student Data" << endl;
        cout << "4. Update Student Data" << endl;
        cout << "5. Delete Student Data" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> val;
        cout << endl;

        switch (val) {
            case 1:
                insertS(conn, u);
                break;
            case 2:
                showRecord(conn);
                break;
            case 3:
                searchS(conn);
                break;
            case 4:
                updateS(conn, u);
                break;
            case 5:
                deleteS(conn);
                break;
            case 0:
                exit = true;
                cout << "Good Luck!" << endl;
                Sleep(3000);
                break;
            default:
                cout << "Invalid Input" << endl;
                Sleep(1000);
        }
    }

    mysql_close(conn);
    return 0;
}
