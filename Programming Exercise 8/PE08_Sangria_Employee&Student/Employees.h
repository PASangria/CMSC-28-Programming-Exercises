#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Employees : public Person {
private:
    string empNum;
    
public:
	string position;
    string officeUnit;
    double salary;
    
    // Constructors
    Employees() {};
    
    // Setters
    void setEmpNum(string newEmpNum){
        empNum = validateInput(newEmpNum, "Employee Number");
    }
    void setPosition(string newPosition){
        position = validateInput(newPosition, "Position");
    }
    void setOfficeUnit(string newOfficeUnit){
        officeUnit = validateInput(newOfficeUnit, "Office Unit");
    }
    
    void setSalary(double newSalary){
        salary = validateSalaryInput(newSalary);
    }

    // Getters
    string getEmpNum() const {
        return empNum;
    }
    string getPosition() const {
        return position;
    }
    string getOfficeUnit() const {
        return officeUnit;
    }
    double getSalary() const {
        return salary;
    }
    
    // This method ensures that only positive and valid numerical values will be inputted as a salary.
	double validateSalaryInput(double value) {
	    do {
	    	cout << "Salary: ";
	        if (!(cin >> value) || value < 0) {
	            cin.clear();
	            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	            cout << "Please input a valid salary amount." << std::endl;
	        } else {
	           	return value;
			}
		} while (true);
	}
};

#endif // EMPLOYEES_H

