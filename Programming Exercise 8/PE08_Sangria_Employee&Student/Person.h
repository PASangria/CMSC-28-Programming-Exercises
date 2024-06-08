#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string fname;
    string lname;
    string gender;
    
public:
	string emailAdd;
    string cpNumber;
    
    // Constructors
    Person(){};
    
    // Setters
    void setlname(string lastName) {
        lname = validateInput(lastName, "last name");
    }

    // Setter method for first name
    void setfname(string firstName) {
        fname = validateInput(firstName, "first name");
    }

    // Setter method for gender
    void setgender(string newGender) {
        gender = validateGender(newGender);
    }
    
    // Setter method for email address
    void setEmailAdd(string newEmailAdd){
        emailAdd = validateEmail(newEmailAdd);
    }
    
    // Setter method for cellphone number
    void setCpNumber(string newcpNumber){
        cpNumber = validateCPNumber(newcpNumber);
    }

    // Getters
    string getFname(){
        return fname;    
    }
    string getLname(){
        return lname;
    }
    string getGender(){
        return gender;
    }
    string getEmailAdd(){
        return emailAdd;
    }
    string getCpNumber(){
        return cpNumber;
    }
    
    // Method to validate input of string variable. This is to ensure that the program will not accept empty input
    string validateInput(string input, string attribute){
        do {
            if (input == "") {
                cout << "Please input " << attribute << endl;
                cout << "Enter " << attribute << ": ";
                getline(cin, input);
            }
        } while (input == "");
        return input;
    }
    
    // Method to ensure that there is a uniform and correct value of the gender limiting to male and female.
    string validateGender(string input){
    	if (input != "Male" && input != "Female"){
    		do {
    			cout << "Please only choose from the following: " << endl;
    			cout << "[1] Male	[2] Female" << endl;
    			cout << "Choice (type the number only): ";
				getline(cin, input);
				if (input == "1"){
					return "Male";
				} else if (input == "2") {
					return "Female";
				}
			}  while (input != "1" && input != "2");
		} else {
			return input;
		}
	}
	
	// Method to ensure a valid email address will be accepted. That is it must contain a '@' and '.' where '.' does not precede '@'.
	// Numerical beginnings is also deemed invalid
	string validateEmail(std::string email) {
	    int valid = 0;
	
	    do {
	        int atPos = email.find('@');
	        int dotPos = email.find('.');
	
	        if (!((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z')) || atPos == string::npos || dotPos == string::npos || atPos > dotPos || dotPos >= email.length() - 1) {
	            std::cout << "Please input a valid email address." << std::endl;
	            std::cout << "Enter email address: ";
	            std::getline(std::cin, email);
	            valid = 0;
	        } else {
	            valid = 1;
	        }
	    } while (valid == 0);
	
		return email;
	}
	
	
	// Method to ensures that only Phlippine cellphone number format is accepted
	string validateCPNumber(string cpNumber){
    	while (!((cpNumber.length() == 11 && cpNumber.substr(0, 2) == "09") || (cpNumber.length() == 13 && cpNumber.substr(0, 5) == "+639"))) {
	        cout << "Please input a valid Philippine phone number (either starts with 09 with length 11 or +639 with length 13)." << std::endl;
	        cout << "Enter Cellphone Number: ";
	        getline(cin, cpNumber);
		}
    	return cpNumber;
    }
};

#endif // PERSON_H

