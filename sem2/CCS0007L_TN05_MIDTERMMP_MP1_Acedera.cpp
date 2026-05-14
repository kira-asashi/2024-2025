#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Student{
int studentID;
char firstName[50];
char lastName[50];
float GPA;
};

Student students[100];  

void addStudent(Student students[], int &numStudents){
cout << "Enter student ID: ";
cin >> students[numStudents].studentID;
cin.ignore();
cout << "Enter first name: ";
cin.getline(students[numStudents].firstName, 50);
cout << "Enter last name: ";
cin.getline(students[numStudents].lastName, 50);
cout << "Enter GPA: ";
cin >> students[numStudents].GPA;
cin.ignore();
cout << "\n";
numStudents++;
}

void displayStudents(const Student students[], int numStudents){
if(numStudents == 0){
    cout << "No students listed." << endl;
    cout << "\n";
    return;
}

    cout << left;
    cout << setw(25) << "Student Name" << " | " << setw(14) << "Student ID No." << " | " << "GPA" << endl;
for (int i = 0; i < numStudents; i++){
    cout << setw(15) << students[i].firstName << " " << setw(9) << students[i].lastName << " | " << setw(14) << students[i].studentID << " | " << setw(3) << fixed << setprecision(2) << students[i].GPA << endl;
}
} 

float calculateAverageGPA(const Student students[], int numStudents){
float totalGPA = 0;
for (int i = 0; i < numStudents; i++)
    {totalGPA += students[i].GPA;}
    return totalGPA / numStudents;
}

void findStudentsByLastName(const Student students[], int numStudents, const char lastName[]){
bool found = false;
for (int i = 0; i < numStudents; i++){
    if (strcmp(students[i].lastName, lastName) == 0){
        cout << left;
        cout << setw(25) << "Student Name" << " | " << setw(14) << "Student ID No." << " | " << "GPA" << endl;
        cout << setw(15) << students[i].firstName << " " << setw(9) << students[i].lastName << " | " << setw(14) << students[i].studentID << " | " << setw(3) << fixed << setprecision(2) << students[i].GPA << endl;
        found = true;
    }
}
if(!found)
cout << "No students with the last name \"" << lastName << "\" listed.\n" << endl;
}

int main(){
int choice;
int numStudents = 0;
do {
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Calculate Average GPA" << endl;
    cout << "4. Find Students by Last Name" << endl;
    cout << "5. Exit" << endl;
    cout << "\nEnter choice: ";
    cin >> choice;
    cout << "\n";
    switch (choice){
        case 1:
            addStudent(students, numStudents);
            break;
        case 2:
            displayStudents(students, numStudents);
            break;
        case 3:
            numStudents>0 ? cout << "Average GPA of Listed Students: " << calculateAverageGPA(students, numStudents) << endl : cout << "No students listed.";
            cout << endl;
            break;
        case 4:
            char lastName[50];
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "\n";
            findStudentsByLastName(students, numStudents, lastName);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
    }
} while (choice != 5);
return 0;
}