#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    string position;
    string type;
    string startDate;
    double basicSalary;
    double hourlyWage;
    double totalHours;
    int leaveDays;
    double overtimeHours;
};

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

int findEmployeeById(int id) {
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

void insertEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Employee limit reached!\n";
        return;
    }

    Employee emp;
    cout << "\nEnter Employee ID: ";
    cin >> emp.id;

    if (findEmployeeById(emp.id) != -1) {
        cout << "Employee ID already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, emp.name);

    cout << "Enter Position (Teacher, Administrator, Janitor, Librarian): ";
    getline(cin, emp.position);

    cout << "Enter Employee Type (Full-time, Part-time, Contract): ";
    getline(cin, emp.type);

    cout << "Enter Start Date	: ";
    getline(cin, emp.startDate);

    cout << "Enter Basic Salary: $";
    cin >> emp.basicSalary;

    cout << "Enter Hourly Wage: $";
    cin >> emp.hourlyWage;

    cout << "Enter Total Working Hours: ";
    cin >> emp.totalHours;

    cout << "Enter Leave Days Taken: ";
    cin >> emp.leaveDays;

    cout << "Enter Overtime Hours: ";
    cin >> emp.overtimeHours;

    employees[employeeCount++] = emp;

    cout << "Employee inserted successfully!\n";
}

void updateEmployee() {
    int id;
    cout << "\nEnter Employee ID to Update: ";
    cin >> id;

    int index = findEmployeeById(id);
    if (index == -1) {
        cout << "Employee not found!\n";
        return;
    }

    cout << "Updating data for " << employees[index].name << ":\n";

    Employee& emp = employees[index];
    cout << "Enter New Name: ";
    cin.ignore();
    getline(cin, emp.name);

    cout << "Enter New Position: ";
    getline(cin, emp.position);

    cout << "Enter New Employee Type: ";
    getline(cin, emp.type);

    cout << "Enter New Start Date: ";
    getline(cin, emp.startDate);

    cout << "Enter New Basic Salary: $";
    cin >> emp.basicSalary;

    cout << "Enter New Hourly Wage: $";
    cin >> emp.hourlyWage;

    cout << "Enter New Total Working Hours: ";
    cin >> emp.totalHours;

    cout << "Enter New Leave Days Taken: ";
    cin >> emp.leaveDays;

    cout << "Enter New Overtime Hours: ";                          
    cin >> emp.overtimeHours;

    cout << "Employee updated successfully!\n";
}

double calculateSalary(Employee emp) {
    double bonus = 0;

    if (emp.leaveDays == 0) bonus = 150;
    else if (emp.leaveDays == 1) bonus = 100;
    else if (emp.leaveDays == 2) bonus = 50;

    double dailyWage = emp.basicSalary / 30.0;
    double overtimePay = emp.overtimeHours * dailyWage * 2.0;

    double grossSalary = emp.basicSalary + bonus + overtimePay;

    if (emp.leaveDays > 4 && emp.overtimeHours > 0) {
        grossSalary -= grossSalary * 0.01;
    }

    double tax = grossSalary * 0.02;
    double netSalary = grossSalary - tax - 10;

    return netSalary;
}

void viewEmployees() {
    if (employeeCount == 0) {
        cout << "\nNo employees found!\n";
        return;
    }

    cout << "\n--- Employee Records ---\n";
    for (int i = 0; i < employeeCount; ++i) {
        Employee& emp = employees[i];
        cout << "\nID: " << emp.id;
        cout << "\nName: " << emp.name;
        cout << "\nPosition: " << emp.position;
        cout << "\nType: " << emp.type;
        cout << "\nStart Date: " << emp.startDate;
        cout << "\nBasic Salary: $" << fixed << setprecision(2) << emp.basicSalary;
        cout << "\nHourly Wage: $" << emp.hourlyWage;
        cout << "\nTotal Working Hours: " << emp.totalHours;
        cout << "\nLeave Days: " << emp.leaveDays;
        cout << "\nOvertime Hours: " << emp.overtimeHours;

        double salary = calculateSalary(emp);
        cout << "\nNet Salary: $" << fixed << setprecision(2) << salary;
        cout << "\n-----------------------------\n";
    }
}

void showMenu() {
    int choice;
    do {
        cout << "\n---- School Staff Management System ----";
        cout << "\n1. Insert Employee";
        cout << "\n2. Update Employee";
        cout << "\n3. View All Employees";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertEmployee(); break;
            case 2: updateEmployee(); break;
            case 3: viewEmployees(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 4);
}

int main() {
    showMenu();
    return 0;
}
