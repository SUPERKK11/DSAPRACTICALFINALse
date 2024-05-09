//Write a C++ program for implementation of Sequential Access File to 
//maintain the data of students and allow an user to add, search, delete 
//and display information of the student
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    string name;
    int age;
    string rollNo;
};

// Function to add student information to the file
void addStudent() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student roll number: ";
    cin >> student.rollNo;

    // Write student information to the file
    outFile << student.name << " " << student.age << " " << student.rollNo << endl;

    cout << "Student information added successfully!" << endl;

    outFile.close();
}

// Function to search for a student by roll number
void searchStudent() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    string rollNo;
    cout << "Enter roll number to search: ";
    cin >> rollNo;

    Student student;
    bool found = false;
    while (inFile >> student.name >> student.age >> student.rollNo) {
        if (student.rollNo == rollNo) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Student found:" << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Roll Number: " << student.rollNo << endl;
    } else {
        cout << "Student not found!" << endl;
    }

    inFile.close();
}

// Function to delete student information by roll number
void deleteStudent() {
    // Implement this function if needed
    cout << "Delete student function not implemented yet!" << endl;
}

// Function to display all student information
void displayStudents() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    Student student;
    cout << "Student Information:" << endl;
    cout << setw(20) << left << "Name" << setw(10) << "Age" << setw(15) << "Roll Number" << endl;
    cout << "-------------------------------------------" << endl;
    while (inFile >> student.name >> student.age >> student.rollNo) {
        cout << setw(20) << left << student.name << setw(10) << student.age << setw(15) << student.rollNo << endl;
    }

    inFile.close();
}

int main() {
    char choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cin.ignore(); // Ignore newline character
                addStudent();
                break;
            case '2':
                searchStudent();
                break;
            case '3':
                deleteStudent();
                break;
            case '4':
                displayStudents();
                break;
            case '5':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != '5');

    return 0;
}
