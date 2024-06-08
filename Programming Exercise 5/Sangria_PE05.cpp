// Author: Prescious Apple D. Sangria
// 1-BSCS
// Programming Exercise 05

// Program Description:
// This program takes an array of user input and calculates basic statistics on it such as finding the min and max numbers, average, standard deviation. and variance.

#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void displayProgramInfo();
int getUserInput(double dataValues[], int size);
double getLargestValue(double dataValues[], int size);
double getSmallestValue(double dataValues[], int size); 
double getAverage(double dataValues[], int size);
double getVariance(double dataValues[], double average, int size); 
double getStandardDeviation(double variance); 
void displayOutput(double largestValue, double smallestValue, double average, double standardDeviation, double variance);

// Main Function
int main() {
    // Variable Declaration and Initialization
	int size = 10;
    double dataValues[size], largestValue, smallestValue, average, variance, standardDeviation;

    //Display info function
    displayProgramInfo();

    // User-input function
    size = getUserInput(dataValues, size);

    // Statistic functions
    largestValue = getLargestValue(dataValues, size);
    smallestValue = getSmallestValue(dataValues, size);
    average =	getAverage(dataValues, size);
    variance = getVariance(dataValues, average, size);
    standardDeviation = getStandardDeviation(variance);

    // Output display function
    displayOutput(largestValue, smallestValue, average, standardDeviation, variance);
}

// Function: displayProgramInfo
// Description: Displays programmer info and program description
void displayProgramInfo() {
    cout << "Programming Exercise 5\n";
    cout << "Submitted by: Prescious Apple D. Sangria\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "This program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
}

// Function: getUserInput
// Description: Prompts user to input a maximum of 10 numbers or stops receiving input when user enters 0.
//             Stores each input in the array
// Parameters: double dataValues[] - passed as a reference and used to store user input values.
//			   int size - initialized as 10 in the main function, used to ensure a maximum of 10 values will be received.
// Return: int size - the number of elements filled in the array, which is the index of the last element entered.
//                   If the user enters 0 to stop inputting numbers, the function returns the index at that point.
//                   If the maximum number of elements (10) is reached without encountering 0, the function returns 10.
int getUserInput(double dataValues[], int size) {
    int index = 0;
    string tempValues[size];
    // This ensures that it will loop through until a maximum of 10 valid numbers is inputted.
    do {
        cout << "Input a number: ";
        cin >> tempValues[index];
        if (tempValues[index] == "0") {
            return index;
        } else {
            bool valid = true;
            int dotCount = 0, hyphenCount = 0; 
            // Checking if the input is valid
            for (int i = 0; i < tempValues[index].length(); i++) {
                char c = tempValues[index][i];
                // Accepts a valid number if there is no or strictly one decimal point
                // Accepts a number with '-' if and only if there is only one and it is at the beginning of the string input
                // Exits the loop if one of the characters in the string input is not a digit or a decimal point
                if (c == '.') {
                    dotCount++;
                    if (dotCount > 1 || (tempValues[index].length() == 1 && tempValues[index] == ".")) {
                        valid = false;
                        break;
                    }
                } else if (c == '-') {
                    hyphenCount++;
                    if (hyphenCount > 1 || (tempValues[index].length() == 1 && tempValues[index] == "-") || (hyphenCount == 1 && tempValues[index][0] != '-')) {
                        valid = false;
                        break;
                    }
                }
				 else if (!isdigit(c) && c != '-') { 
                    valid = false;
                    break;
                }
            }
            // Accepts an input and stores as a double after the validity checking from the former loop
            if (valid && dotCount <= 1 && hyphenCount <= 1) { 
                dataValues[index] = atof(tempValues[index].c_str()); 
                index++;
            } else {
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        }
    } while (index < size);
    return 10;
}

// Function: getLargestValue
// Description: Loops through the array and identifies the number with the highest value.
// Parameters: double dataValues[] - an array containing user inputted values.
//			   int size - number of elements in the array.
// Return: double largestValue = the number with the highest value from the dataValues[] array.
double getLargestValue(double dataValues[], int size) { 
    double largestValue = dataValues[0];
    for (int index=0; index < size; index++) { 
        if (dataValues[index] > largestValue) { 
            largestValue = dataValues[index];
        }
    }
    return largestValue;
}

// Function: getSmallestValue
// Description: Loops throught the array and identifies the number with the lowest value.
// Parameters: double dataValues[] - an array containing user inputted values.
//			   int size - number of elements in the array.
// Return: double smallestValue - the number with the lowest value from the dataValues[] array.
double getSmallestValue(double dataValues[], int size) { 
    double smallestValue = dataValues[0];
    for (int index=0; index < size; index++) { 
        if (dataValues[index] < smallestValue) { 
            smallestValue = dataValues[index];
        }
    }
    return smallestValue;
}

// Function: getAverage
// Description: Finds the mean of the dataValues.
// Parameters: double dataValues[] - an array containing user-inputted values.
// 			   int size - number of elements in the array.
// Return: double average - the sum of all elements in the dataValues array divided by the total number of elements of the same array.
double getAverage(double dataValues[], int size) { 
    double sum = 0;
    for (int i=0; i < size; i++) { 
        sum += dataValues[i];
    }
    return sum/size;
}

// Function: getVariance
// Description: finds the variance of the dataValues array
// Parameters: double dataValues[] - an array containing the user-inputted values
//			   double average - the average of the dataValues array
//			   int size - number of elements of the dataValues array
// Return: double variance - the sum of the squared difference of average and each data from the dataValues array divided to the total number
//							 elements of the same array. This utilizes population variance formula.
double getVariance(double dataValues[], double average, int size) { 
    double sum = 0;
    for (int i=0; i < size; i++) { 
        sum += (average - dataValues[i])*(average - dataValues[i]);
    }
    return sum/(size);
}

// Function: getStandardDeviation
// Description: finds the standard deviation of the dataValues array
// Parameter: double variance - the calculated variance of the dataValues array
// Return: double standardDeviation - the square root of the variance variable
double getStandardDeviation(double variance) {
    return sqrt(variance);
}

// Function: displayOutput
// Description: Displays the calculated statistical values to the console.
// Parameters: double largestValue - The largest value in the data set.
//             double smallestValue - The smallest value in the data set.
//             double average - The average value of the data set.
//             double standardDeviation - The standard deviation of the data set.
//             double variance - The variance of the data set.
void displayOutput(double largestValue, double smallestValue, double average, double standardDeviation, double variance) {
    cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Statistical Computations: " << endl;
    cout << "Largest Value: " << largestValue << endl;
    cout << "Smallest Value: " << smallestValue << endl;
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << standardDeviation << endl;
    cout << "Variance: " << variance << endl;
}

