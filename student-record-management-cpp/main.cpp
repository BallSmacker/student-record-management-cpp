#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Student {
	int id;
	string name;
	int age;
	float cgpa;
};
Student s;

void addStudent() {
	ofstream outFile("students.txt", ios::app);
	cout << "\nEnter ID: ";
	cin >> s.id;
	
	cin.ignore();
	cout << "Enter Name: ";
	getline(cin, s.name);
	
	cout << "Enter Age: ";
	cin >> s.age;
	
	cout << "Enter CGPA: ";
	cin >> s.cgpa;
	
	outFile << s.id << "," << s.name << "," << s.age << "," << s.cgpa << endl;
	outFile.close();
    cout << "\nStudent added (temporarily).\n";
}

void viewStudents() {
	ifstream inFile("students.txt");
	
	if (!inFile){
		cout << "\nNo records found.\n";
		return;
	}
	
	cout << "\n--- Student Details ---\n";
	while (inFile >> s.id) {
		inFile.ignore();
		getline(inFile, s.name, ',');
		inFile >> s.age;
		inFile.ignore();
		inFile >> s.cgpa;
		inFile.ignore();
		
		cout << "ID: " << s.id << endl;
		cout << "Name :" << s.name << endl;
		cout << "Age :" << s.age << endl;
		cout << "CGPA :" << s.cgpa << endl;
		cout << "---------------------\n";
	}
	inFile.close();
}

void searchStudent() {
     ifstream inFile("students.txt");
    int searchId;
    bool found = false;

    if (!inFile) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    while (inFile >> s.id) {
        inFile.ignore();
        getline(inFile, s.name, ',');
        inFile >> s.age;
        inFile.ignore();
        inFile >> s.cgpa;
        inFile.ignore();

        if (s.id == searchId) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "CGPA: " << s.cgpa << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "\nStudent not found.\n";
    }
}

void updateStudent() {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");

    int updateId;
    bool found = false;

    if (!inFile) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\nEnter Student ID to update: ";
    cin >> updateId;

    while (inFile >> s.id) {
        inFile.ignore();
        getline(inFile, s.name, ',');
        inFile >> s.age;
        inFile.ignore();
        inFile >> s.cgpa;
        inFile.ignore();

        if (s.id == updateId) {
            found = true;

            cout << "\nEnter new details:\n";
            cout << "New ID: ";
            cin >> s.id;

            cin.ignore();
            cout << "New Name: ";
            getline(cin, s.name);

            cout << "New Age: ";
            cin >> s.age;

            cout << "New CGPA: ";
            cin >> s.cgpa;
        }

        outFile << s.id << "," << s.name << "," << s.age << "," << s.cgpa << endl;
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent updated successfully.\n";
    else
        cout << "\nStudent not found.\n";
}


void deleteStudent() {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");

    int deleteId;
    bool found = false;

    if (!inFile) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    while (inFile >> s.id) {
        inFile.ignore();
        getline(inFile, s.name, ',');
        inFile >> s.age;
        inFile.ignore();
        inFile >> s.cgpa;
        inFile.ignore();

        if (s.id == deleteId) {
            found = true;
            continue;  // skip writing this record
        }

        outFile << s.id << "," << s.name << "," << s.age << "," << s.cgpa << endl;
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully.\n";
    else
        cout << "\nStudent not found.\n";
}


int main() {
    int choice;

    do {
        cout << "\n====== STUDENT RECORD SYSTEM ======\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

