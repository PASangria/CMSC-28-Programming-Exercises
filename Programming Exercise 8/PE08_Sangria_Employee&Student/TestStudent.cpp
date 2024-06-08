#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	// variable declarations
    string fname, lname, gender, emailAdd, cpNumber, studentNum, course, department, college;
    Student student;
    // Program Description
    cout << "This program serves as a test environment for the Student class, which is a child class derived from the Person class." ;
	cout << "It allows the user to create an instance of the Student class and set attributes such as first name, last name, gender, email address, cellphone number, student number, course, department, and college.";
	cout << "After setting these attributes, the program displays the details of the student.";
	cout << "This test program verifies the functionality of the Student class and its inherited methods from the Person class." << endl;
    cout << "Programmed by: Prescious Apple D. Sangria" << endl;
    cout << "===========================================================================================================" << endl;
    
    // Asking user for input and setting its values accordingly.
    cout << "Please input the following accordingly: \n" << endl;
    cout << "First Name: ";
    getline(cin, fname);
    student.setfname(fname);
    
    cout << "Last Name: ";
    getline(cin, lname);
    student.setlname(lname);
     
    cout << "Gender: ";
    getline(cin, gender);
    student.setgender(gender);
    
    cout << "Email Address: ";
    getline(cin, emailAdd);
    student.setEmailAdd(emailAdd);
    
    cout << "Cellphone Number: ";
    getline(cin, cpNumber);
	student.setCpNumber(cpNumber); 
    
    cout << "Student Number: ";
    getline(cin, studentNum);
    student.setStudentNum(studentNum);
    
    cout << "Course: ";
    getline(cin, course);
    student.setCourse(course);
    
    cout << "Department: ";
    getline(cin, department);
    student.setDepartment(department);
    
    cout << "College: ";
    getline(cin, college);
    student.setCollege(college);
    

    // Getting and displaying values
    cout << "\n\n";
    cout << "===========================================================================================================" << endl;
    cout << "Receiver: " << endl;
    cout << student.getFname() << " " << student.getLname() << endl;
    cout << student.getGender() << endl;
    cout << student.getEmailAdd() << endl;
    cout << student.getCpNumber() << endl;
    cout << "\n\n";
	
    // Output
    cout << "Hi, " << student.getFname() << " " << student.getLname() << "!" << endl;
	cout << "\nWelcome to University of the Philippines-Mindanao and congratulations! ";
	cout << "We are pleased to inform you that you are admitted in the " << student.getCourse();
	cout << " under the " << student.getDepartment() << ".";
	cout << " Your Student number is " << student.getStudentNum() << "." << endl;
	cout << "\n\n";
	
	cout << "To be part of the UP Mindanao community, please reply to this email on or before June 05, 2024." << endl;
	cout << "\n";
	
	cout << "Sincerely," << endl;
	cout << "Univeristy of the Philippines - Office of Admissions";

    return 0;
}

