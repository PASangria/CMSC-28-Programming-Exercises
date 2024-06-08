#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class Student : public Person {
private:
    string studentNum;
    
public:
	string course;
    string department;
    string college;
    // Constructors
    Student(){};
    
    // Setters
    void setStudentNum(string newStudentNum){
    	studentNum = validateStudentNum(newStudentNum);
	}
    void setCourse(string newCourse){
    	course = validateInput(newCourse, "Course");
	}
    void setDepartment(string newDepartment){
    	department = validateInput(newDepartment, "Department");
	}
    void setCollege(string newCollege){
    	college = validateInput(newCollege, "College");
	}

    // Getters
    string getStudentNum(){
    	return studentNum;
	}
    string getCourse(){
    	return course;
	}
    string getDepartment(){
    	return department;
	}
    string getCollege(){
    	return college;
	}
	
	// Ensure that the student number follows the formatting of UPMindanao ID's except that the first 4 digits could also be not a year.
	string validateStudentNum(string studentNum){
		int valid = 0;
		
		do {
			if (studentNum.length() == 10) {
				valid = 0;
		        for (int i = 0; i < 10; ++i) {
		        	if ((i == 4) && (studentNum[i] == '-')){
		        		valid++;
					} else if (isdigit(studentNum[i])){
						valid++;
					}
       			}
       			if (valid == 10){
       				return studentNum;
				}
    		}
			cout << "Please enter a valid student number with the format XXXX-XXXXX with X being any digit." << endl;
			cout << "Enter Student Number: ";
			getline(cin, studentNum);
		} while (valid != 10);
	}

};

#endif // STUDENT_H

