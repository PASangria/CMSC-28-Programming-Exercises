#include <iostream>
using namespace std;

// Class representing a book
class Book {
	private:
		string title;
		string author;
		string ISBN;
		string publisher;
		
	public:
		// Constructor
		Book(string title, string author, string ISBN){
			this->title = title;
			this->author = author;
			this->ISBN = ISBN;
		}
		
		// Getter methods
		string getTitle(){
			return title;
		}
		string getAuthor(){
			return author; 
		}
		string getISBN(){
			return ISBN;
		}
		string getPublisher(){
			return publisher;
		}
		
		// Setter methods
		void setTitle(string bktitle){
			title = bktitle;
		}
		void setAuthor(string bkauthor){
			author = bkauthor;
		}
		void setISBN(string bkisbn){
			ISBN = bkisbn;
		}
		void setPublisher(string bkpublisher){
			publisher = bkpublisher;
		}
};
