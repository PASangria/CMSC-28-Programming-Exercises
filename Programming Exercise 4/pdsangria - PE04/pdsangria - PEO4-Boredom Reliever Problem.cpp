#include <iostream>

using namespace std;

// Function prototypes2
void displayProgramInfo();
void getUserInput(int* num);
string toBinary(int num);
void displayInfo(int num, string binaryNum);
	
// Main function
int main() {
	// Variable declarations
	int num;
	string binaryNum;
	
	// Display program information
	displayProgramInfo();
	
	// Getting user input
	getUserInput(&num);
	
	// Converting from decimal to binary
	binaryNum = toBinary(num);
	
	// Displaying the data
	displayInfo(num, binaryNum);
}

// Function to display program information
void displayProgramInfo() {
    cout << "Program Name: Convert an decimal integer to binary.\n";
    cout << "Program Description: Asks user an integer and converts it to binary.\n";
    cout << "Program Limitation: This program can only convert positive integers and only up to 2147483647 because of the data type used(int).\n";
    cout << "Program Creator: Prescious Apple D. Sangria\n";
    cout << "Date done: April 27, 2024\n";
    cout << "Subject: CMSC28\n";
    cout << "-------------------------------------------\n";
}

// Function get user input by utilizing pass by reference
// Parameter:  int* num - a pointer to the address of num
void getUserInput(int* num) {
	cout << "Decimal Integer to Binary\n";
	cout << "-------------------------------------------\n";
	cout << "Enter an integer: ";
	cin >> *num;
	cout << endl;
}

// Function to convert from decimal integer to binary
// Parameter: int num - the number the user inputted
// Return: string - the binary conversion of num
string toBinary(int num) {
	// Uses string instead to cater binary conversion with a greater value of 2147483647 (limit of an integer)
    string binary;
    do {
        binary = char('0' + num % 2) + binary;
        num /= 2;
    } while (num != 0);
    return binary;
}

// Function to display data
// Parameter: int num - the number the user inputted, int binaryNum - the binary conversion of num
void displayInfo(int num, string binaryNum) {
	cout << "-------------------------------------------\n";
	cout << "Conversion\n";
	cout << "Decimal Integer: " << num << endl;
	cout << "Binary: " << binaryNum << endl;
	cout << "-------------------------------------------\n";
}
