#include <stdio.h>
#include "Person.h"
#include "Grade.h"

using namespace std;

int main(){
	int age;
	char gender;
	string subject;
	int grade;
	
	Person student1;
	Grades grade1;
	
	cout << "\nInput age: ";
	cin >> age;
	student1.setage(age);
	
	cout << "Input gender: ";
	cin >> gender;
	student1.setgender(gender);
	 
	cin.ignore();
	cout << "Input subject: ";
	getline(cin, subject);
	grade1.setSubject(subject);
	
	cout << "Input grade: ";
	cin >> grade;
	grade1.setGrade(grade);
	
	cout << "\n\nStudent Data" << endl;
	cout << "Age: " << student1.getage() << endl;
	cout << "Gender: " << student1.getgender() << endl;
	cout << "Subject: " << grade1.getSubject() << endl;
	cout << "Grade: " << grade1.getGrade() << endl;
	cout << "Grade Status: " << grade1.getGradeStatus() << endl;
	return 0;
}
