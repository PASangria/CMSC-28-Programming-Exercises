#include <iostream>

using namespace std;

// Function Prototypes
void displayProgramInfo();
void getUserInput(float* x, float* y, float* z);
float findHighest(float x, float y, float z);
float findLowest(float x, float y, float z);
void displayInfo(float x, float y, float z, float highest, float lowest, float difference);

// Main function
int main(){
	// Variable declarations
    float x, y, z, highest, lowest, difference;
    
    // Display program information
    displayProgramInfo();
    
    // Get user input
    getUserInput(&x, &y, &z);
    
    // Find the highest and lowest values
    highest = findHighest(x, y, z);
    lowest = findLowest(x, y, z);
    
    // Calculate difference between highest and lowest
    difference = highest - lowest;
    
    // Display collected data
    displayInfo(x, y,z, highest, lowest, difference);
    
    return 0;
}

// Function to display program information
void displayProgramInfo() {
    cout << "Program Name: Find the highest number.\n";
    cout << "Program Description: Asks three numbers from users and determines the highest and lowest number. It also ouputs their difference. \n";
    cout << "Program Creator: Prescious Apple D. Sangria\n";
    cout << "Date done: April 27, 2024\n";
    cout << "Subject: CMSC28\n";
}

// Function to get user input utilizing pass variable by reference
// Parameters:  float* x - first number, float* y = second number, float* z = third number
void getUserInput(float* x, float* y, float* z){
	cout << "----------------------------------------------------------\n";
	cout << "Enter first number: ";
	cin >> *x;
	cout << "Enter second number: ";
	cin >> *y;
	cout << "Enter third number: ";
	cin >> *z;
	cout << endl;
}

// Function to find the highest number
// Parameters = float x - first number, float y - second number, float z - third number
// Return = float highest - highest value among the numbers given.
float findHighest(float x, float y, float z){
	float highest = x;
	if (y > highest){
		highest = y;
	} 
	if (z > highest) {
		highest = z;
	}
	
	return highest;
}

// Function to find the lowest number
// Parameters = float x - first number, float y - second number, float z - third number
// Return = float lowest - lowest value among the numbers given.
float findLowest(float x, float y, float z){
	float lowest = x;
	if (y < lowest){
		lowest = y;
	} 
	if (z < lowest) {
		lowest = z;
	}
	
	return lowest;
}

// Function to display collected data
// Parameters = float x - first number, float y - second number, float z - third number
// 				float highest - highest value among the numbers given.
//				float lowest - lowest value among the numbers given.
//				float difference(range) - difference between the highest and lowest value.
void displayInfo(float x, float y, float z, float highest, float lowest, float difference) {
	cout << "----------------------------------------------------------\n";
	cout << "Data collected: \n";
	cout << "----------------------------------------------------------\n";
	cout << "First number: " << x << endl;
	cout << "Second number: " << y << endl;
	cout << "Third number: " << z << endl;
	cout << "Highest number: " << highest << endl;
	cout << "Lowest number: " << lowest << endl;
	cout << "Range: " << difference << endl;
	cout << "----------------------------------------------------------\n";
}
