// A class representing a person with attributes like first name, last name, and gender.

#include <iostream> 
#include <string>  

using namespace std;

class Person {
private:
    string lname; // Last name of the person
    string fname; // First name of the person
    string gender; // Gender of the person

public:
    // Constructor
    Person() {}

    // Setter method for last name
    void setlname(string lastName) {
        lname = validateInput(lastName, "last name");
    }

    // Setter method for first name
    void setfname(string firstName) {
        fname = validateInput(firstName, "first name");
    }

    // Setter method for gender
    void setgender(string newGender) {
        gender = validateInput(newGender, "gender");
        cout << endl;
    }

    // Getter method for last name
    string getlname() {
        return lname;
    }

    // Getter method for first name
    string getfname() {
        return fname;
    }

    // Getter method for gender
    string getgender() {
        return gender;
    }
    
    // Method to validate input for attributes like first name, last name, and gender
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
};

