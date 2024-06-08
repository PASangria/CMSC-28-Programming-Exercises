#include <iostream>
#include "Employees.h"

using namespace std;

int main() {
    string fname, lname, gender, emailAdd, cpNumber, empNum, position, officeUnit;
    double salary;
    Employees employee;
    
    // Program Description
	cout << "This program serves as a test environment for the Employees class, which is a child class derived from the Person class. ";
	cout << "It allows the user to create an instance of the Employees class and set attributes such as first name, last name, gender, ";
	cout << "email address, cellphone number, employee number, position, office/unit, and salary. ";
	cout << "After setting these attributes, the program displays the details of the employee. ";
	cout << "This test program verifies the functionality of the Employees class and its inherited methods from the Person class." << endl;

    cout << "Programmed by: Prescious Apple D. Sangria" << endl;
    cout << "====================================================================================================" << endl;
    cout <<"\nPlease input the following accordingly.\n" << endl;
    
    // Asking for user input and setitng it accordingly
    cout << "First Name: ";
    getline(cin, fname);
    employee.setfname(fname);
    
    cout << "Last Name: ";
    getline(cin, lname);
    employee.setlname(lname);
    
    cout << "Gender: ";
    getline(cin, gender);
    employee.setgender(gender);
    
    cout << "Email Address: ";
    getline(cin, emailAdd);
    employee.setEmailAdd(emailAdd);
     
    cout << "Cellphone Number: ";
    getline(cin, cpNumber);
    employee.setCpNumber(cpNumber);
    
    cout << "Employee Number: ";
    getline(cin, empNum);
    employee.setEmpNum(empNum);
    
    cout << "Position: ";
    getline(cin, position);
    employee.setPosition(position);
    
    cout << "Office Unit: ";
    getline(cin, officeUnit);
    employee.setOfficeUnit(officeUnit);
    
    employee.setSalary(-999);
    

    // Getting and displaying values
    cout << "\n\n";
    cout << "==========================================================================" <<  endl;
    
	cout << "Subject: Congratulations! You are hired!\n" << endl;
	cout << "Dear " << employee.getFname() << " " << employee.getLname() << ",\n" << endl;
	cout << "I am pleased to inform you that you have been selected for the position of " << employee.getPosition() << " at " << employee.getOfficeUnit() << ". ";
	cout << "Congratulations on your new role!\n" << endl;
	cout << "Here are the details of your employment: \n" <<  endl;
	cout << "Full Name: " << employee.getFname() << " " << employee.getLname() << endl;
	cout << "Gender: " << employee.getGender() << endl;
	cout << "Email Address: " << employee.getEmailAdd() << endl;
	cout << "Contact Number: " << employee.getCpNumber() << endl;
	cout << "Employee Number: " << employee.getEmpNum() << endl;
	cout << "Position: " << employee.getPosition() << endl;
	cout << "Office Unit: " << employee.getOfficeUnit() << endl;
	cout << "Salary: Php" << employee.getSalary() << endl;
	
	cout << "\nWe are confident that you will bring valuable skills and contributions to our team. Your first day of work will be on June 05, 2024, and you will report to Ms. Hanna." << endl;
	cout << "\nPlease let us know if you have any questions or need further information. We look forward to welcoming you to our team!" << endl;
	
	cout << "Best Regards, " << endl;
	cout << "Stephanie Tsu" << endl;
	cout << "ABC Company" << endl;
	cout << "09123456789" << endl;
    return 0;
}

