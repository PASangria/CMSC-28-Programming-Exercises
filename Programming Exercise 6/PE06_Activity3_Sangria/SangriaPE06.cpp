// A program created by Prescious Apple D. Sangria
// BSCS-1
// Programming Exercise 06 - Activity 3

// Program Description:
// This program utilizes object-oriented programming to manage movie details using setter and getter methods.
// It incorporates two classes, Person.h and Movie.h, to represent people involved in a movie and the movie itself.

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Movie.h"

using namespace std;

int main() {
    // Variable Declarations
    string title, synopsis, mpaa_rating, genre;
    string fname, lname, gender;
    int g_size, d_size, a_size;
    
    // Instances
    Movie movie1;
    Person director;
    Person actor;
    
    // Program Introduction
    cout << "This program will prompt you to enter details about a movie." << endl;
    cout << "You will be asked for the movie's title, synopsis, MPAA rating, genres, directors, and actors." << endl;
    cout << "Programmed by: Prescious Apple D. Sangria" << endl;
    cout << "==========================================================================================" << endl;
    
    // Input Section
    
    // Movie Title Input
    cout << "Enter Movie Title: ";
    getline(cin, title);
    movie1.setTitle(title);
    
    // Synopsis Input
    cout << "\nEnter Synopsis: ";
    getline(cin, synopsis);
    movie1.setSynopsis(synopsis);

    // MPAA Rating Input
    cout << "\nWhat is its MPAA Rating: ";
    getline(cin, mpaa_rating);
    movie1.setMPAARating(mpaa_rating);
    
    // Genre Input
    cout << "\nHow many genres does it have? ";
    cin >> g_size;
    movie1.setGenreSize(g_size);
    cin.ignore();
    cout << "\nWhat is/are the genre/s: " << endl;
    for (int i = 0; i < g_size; i++){
        cout << "Genre: ";
        getline(cin, genre);
        movie1.addGenre(genre);
    }
    
    // Director Input
    cout << "\nHow many director/s does it have? ";
    cin >> d_size;
    movie1.setDirectorSize(d_size);
    cin.ignore();
    cout << "\n\nWho is/are the director/s: " << endl;
    for (int i = 0; i < d_size; i++){
        // Director's First Name Input
        cout << "First Name: ";
        getline(cin, fname);
        director.setfname(fname);
        
        // Director's Last Name Input
        cout << "Last Name: ";
        getline(cin, lname);
        director.setlname(lname);
        
        // Director's Gender Input
        cout << "Gender: ";
        getline(cin, gender);
        director.setgender(gender);
        
        // Assigning Director Details to Movie
        movie1.addDirector(director);
    }
    
    // Actor Input
    cout << "\nHow many actor/s does it have? ";
    cin >> a_size;
    movie1.setActorSize(a_size);
    cin.ignore();
    cout << "\n\nWho is/are the actor/s: " << endl;
    for (int i = 0; i < a_size; i++){
        // Actor's First Name Input
        cout << "First Name: ";
        getline(cin, fname);
        actor.setfname(fname);
        
        // Actor's Last Name Input
        cout << "Last Name: ";
        getline(cin, lname);
        actor.setlname(lname);
        
        // Actor's Gender Input
        cout << "Gender: ";
        getline(cin, gender);
        actor.setgender(gender);
        
        // Assigning Actor Details to Movie
        movie1.addActor(actor);
    } 
	
	// Display section 
	
	// Displaying the inputs through getter methods
	cout << "==========================================================================================" << endl;
    cout << "\t\t\t\tMOVIE DETAILS" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Title: " << movie1.getTitle() << endl;
    cout << "\nSynopsis: " << movie1.getSynopsis() << endl;
    cout << "\nMPAA Rating: " << movie1.getMPAARating() << endl;
    
    // A loop to retrieve genre and display
    cout << "\nGenre/s: ";
    for (int i = 0; i < g_size; i++){
    	cout << movie1.getGenre(i);
	}
	
	 // A loop to retrieve director's info and display
    cout << "\n\nDirector/s: " << endl << endl;
    for (int i = 0; i < d_size; i++){
    	cout << "Director " << i+1 << ": " << endl ;
    	cout << movie1.getDirector(i);
	}
	
	// A loop to retrieve actor's info and display
    cout << "\nActor/s or Actress/es: " << endl << endl;
    for (int i = 0; i < a_size; i++){
    	cout << "Actor/Actress " << i+1 << ": " << endl;
    	cout << movie1.getActor(i);
    }

	return 0;
}	
