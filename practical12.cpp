//Write a C++ program for implementation of a direct access file -
//Insertion and deletion of a record from a direct access file. 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold record information
struct Record {
    int recordNumber;
    string data;
};

// Function to insert a record into the direct access file
void insertRecord(int recordNumber, const string& data) {
    ofstream outFile("direct_access_file.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    // Write record information to the file
    outFile << recordNumber << " " << data << endl;

    cout << "Record inserted successfully!" << endl;

    outFile.close();
}

// Function to delete a record from the direct access file
void deleteRecord(int recordNumber) {
    // Create a temporary file to copy records except the one to be deleted
    ifstream inFile("direct_access_file.txt");
    ofstream tempFile("temp_direct_access_file.txt");
    if (!inFile || !tempFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    Record record;
    bool found = false;
    while (inFile >> record.recordNumber >> record.data) {
        if (record.recordNumber != recordNumber) {
            tempFile << record.recordNumber << " " << record.data << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    // Replace the original file with the temporary file
    remove("direct_access_file.txt");
    rename("temp_direct_access_file.txt", "direct_access_file.txt");

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int recordNumber;
                string data;
                cout << "Enter record number: ";
                cin >> recordNumber;
                cout << "Enter data: ";
                cin.ignore(); // Ignore newline character
                getline(cin, data);
                insertRecord(recordNumber, data);
                break;
            }
            case 2: {
                int recordNumber;
                cout << "Enter record number to delete: ";
                cin >> recordNumber;
                deleteRecord(recordNumber);
                break;
            }
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 3);

    return 0;
}
