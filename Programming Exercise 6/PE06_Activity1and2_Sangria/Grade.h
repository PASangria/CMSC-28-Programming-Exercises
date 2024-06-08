#include <iostream>

using namespace std;

class Grades{
	private:
		string subject;
		int grade;
		string gradeStatus;

		
	public:
		Grade(){}
		
	void setSubject(string newSubject){
		subject = newSubject;
	}
	
	void setGrade(int newGrade) {
		int status = 1;
		do{
            if (newGrade >= 0 && newGrade <= 100) {
                grade = newGrade;
                setGradeStatus(grade);
            } else {
            	cout << "Invalid grade. Please enter grade from 0 to 100." << endl;
                cout << "Input grade: ";
            	cin >> newGrade;
            	grade = newGrade;
            	setGradeStatus(grade);
            }
        } while (newGrade < 0 || newGrade > 100);
	}
	
	void setGradeStatus(int grade){
		if (grade >= 60){
				gradeStatus = "Pass";
			}
			else {
				gradeStatus = "Fail";
			}
	}
	
	string getSubject(){
		return subject;
	}
	
	int getGrade(){
		return grade;
	}
	
	string getGradeStatus(){
		return gradeStatus;
	}
};
