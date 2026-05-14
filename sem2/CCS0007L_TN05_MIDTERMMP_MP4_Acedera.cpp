#include <iostream>
#include <cstring>
using namespace std;

struct Employee{
    int employeeID;
    char Name[100];
    float salary;
};

Employee employees[100];
int numEmployees = 0;

void addEmployee(Employee employees[], int &numEmployees){
   if (numEmployees >= 100) {
        cout << "Error: Maximum number of employees reached." << endl;
        return;
    }
    
    cout << "Enter employee ID: ";
    cin >> employees[numEmployees].employeeID;
    cin.ignore();
    cout << "Enter employee name: ";
    cin.getline(employees[numEmployees].Name, 100);
    cout << "Enter employee salary: ";
    cin >> employees[numEmployees].salary;
    cin.ignore();
    numEmployees++;
}

void displayEmployees(const Employee employees[], int numEmployees){
    cout << "Employee ID | Employee Name | Salary" << endl;
    if (numEmployees == 0)
        cout << "No employees to display. Please input data first" << endl;
    for (int i = 0; i < numEmployees; i++)
        cout << employees[i].employeeID << " | " << employees[i].Name << " | " << employees[i].salary << endl;
}

void findEmployeeByID(const Employee employees[], int numEmployees, int employeeID){
    bool found = false;
    for (int i = 0; i < numEmployees; i++){
        if (employees[i].employeeID == employeeID){
            cout << "Employee ID | Employee Name | Salary" << endl;
            cout << employees[i].employeeID << " | " << employees[i].Name << " | " << employees[i].salary << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Employee not found" << endl;
}

float calculateAverageSalary(const Employee employees[], int numEmployees){
    float totalSalary = 0;
    for (int i = 0; i < numEmployees; i++)
        totalSalary += employees[i].salary;
    return totalSalary / numEmployees;
}

int main(){
    int choice;
    do{
        cout << "1. Add an employee" << endl;
        cout << "2. Display all employees" << endl;
        cout << "3. Search for an employee by ID" << endl;
        cout << "4. Calculate average salary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                addEmployee(employees, numEmployees);
                break;
            case 2:
                displayEmployees(employees, numEmployees);
                break;
            case 3:
                int employeeID;
                cout << "Enter employee ID: ";
                cin >> employeeID;
                findEmployeeByID(employees, numEmployees, employeeID);
                break;
            case 4:
                cout << "Average Salary: " << calculateAverageSalary(employees, numEmployees) << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}