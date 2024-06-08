// Author: Prescious Apple D. Sangria
// BSCS-1
// Program Description:
//      This program utilizes the Book.h header and has a main function that uses all the attributes and methods found on the Book.h header.

// Headers
#include <iostream>
#include "Book.h"

using namespace std;

// Main Function
int main() {
    // Variable Declarations
    string newTitle, newAuthor, newISBN, newPublisher;
    
    // Prompt user to input data for the first book
    cout << "Using the constructor to store data for the first book." << endl;
    cout << "New Book: " << endl;
    
    // Get user input for book details
    cout << "Title: ";
    getline(cin, newTitle);
    cout << "Author: ";
    getline(cin, newAuthor);
    cout << "ISBN: ";
    getline(cin, newISBN);
    cout << "Publisher: ";
    getline(cin, newPublisher);
    
    // Create a Book object using the constructor and set the publisher
    Book book1(newTitle, newAuthor, newISBN);
    book1.setPublisher(newPublisher);
    
    // Display the data of the first book
    cout << "\n\nNew Book Data" << endl;
    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;
    cout << "Publisher: " << book1.getPublisher() << endl;   
    
    // Prompt user to modify the values of the first book
    cout << "\n\nUsing the setter method to modify the values of the first book" << endl;
    
    // Get user input for new book details
    cout << "New Book: " << endl;
    cout << "Title: ";
    getline(cin, newTitle);
    cout << "Author: ";
    getline(cin, newAuthor);
    cout << "ISBN: ";
    getline(cin, newISBN);
    cout << "Publisher: ";
    getline(cin, newPublisher);
    
    // Set new values to the attributes of the first book
    book1.setTitle(newTitle);
    book1.setAuthor(newAuthor);
    book1.setISBN(newISBN);
    book1.setPublisher(newPublisher);
    
    // Display the modified data of the first book
    cout << "\n\nNew Book Data" << endl;
    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;
    cout << "Publisher: " << book1.getPublisher() << endl;
    
    return 0;
}

