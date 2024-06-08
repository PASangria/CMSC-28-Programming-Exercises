// A class representing a movie with attributes like title, synopsis, MPAA Rating, list of genres, directors and actor/actresses.
// Director and actor attributes are linked to the class Person

#include <iostream> 
#include <string>   
#include "Person.h" // Included to use the Person class

using namespace std;

class Movie {
private:
    string title; // Title of the movie
    string synopsis; // Synopsis of the movie
    string mpaa_rating; // MPAA rating of the movie
    string* genre; // Array to store genres of the movie
    Person* director; // Array to store directors of the movie
    Person* actor; // Array to store actors of the movie
    int genre_size; // Size of the genre array
    int director_size; // Size of the director array
    int actor_size; // Size of the actor array

public:
    // Constructor
    Movie() {}
    
    // Destructor
    ~Movie() {
        delete[] genre;
        delete[] director;
        delete[] actor;
    }
        
    // Setter method for movie title
    void setTitle(string movieTitle) {
        title = validateInput(movieTitle, "movie title");
    }

    // Setter method for movie synopsis
    void setSynopsis(string movieSynopsis) {
        synopsis = validateInput(movieSynopsis, "movie synopsis");
    }

    // Setter method for MPAA rating
    void setMPAARating(string newMPAARating) {
    	// A loop to ensure that only valid MPAA Ratings will be accepted
    	do {
		    if (newMPAARating != "G" && newMPAARating != "PG" && newMPAARating != "PG-13" && newMPAARating != "R" && newMPAARating != "NC-17") {
		        cout << "Please just input either G, PG, PG-13, R, or NC-17" << endl;
		        cout << "Enter MPAA Rating: ";
		        getline(cin, newMPAARating);
		    }
		} while (newMPAARating != "G" && newMPAARating != "PG" && newMPAARating != "PG-13" && newMPAARating != "R" && newMPAARating != "NC-17");
    	mpaa_rating = newMPAARating;
    }

    // Setter method for genre size
    void setGenreSize(int g_size) {
        genre_size = g_size;
        genre = new string[genre_size];
    }

    // Method to add genre to the genre array
    void addGenre(string newGenre) {
        for (int i = 0; i < genre_size; ++i) {
            if (genre[i].empty()) {
                genre[i] = validateInput(newGenre, "genre");
                break;
            }
        }
    }

    // Setter method for director size
    void setDirectorSize(int d_size) {
        director_size = d_size;
        director = new Person[director_size];
    }

    // Method to add director to the director array
    void addDirector(Person newDirector) {
        for (int i = 0; i < director_size; ++i) {
            if (director[i].getfname().empty()) {
                director[i] = newDirector;
                break;
            }
        }
    }

    // Setter method for actor size
    void setActorSize(int a_size) {
        actor_size = a_size;
        actor = new Person[actor_size];
    }

    // Method to add actor to the actor array
    void addActor(Person newActor) {
        for (int i = 0; i < actor_size; ++i) {
            if (actor[i].getfname().empty()) {
                actor[i] = newActor;
                break;
            }
        }
    }

    // Getter method for movie title
    string getTitle() {
        return title;
    }

    // Getter method for movie synopsis
    string getSynopsis() {
        return synopsis;
    }

    // Getter method for MPAA rating
    string getMPAARating() {
        return mpaa_rating;
    }

    // Method to display genres of the movie
    string getGenre(int i) {
            if (i == genre_size - 1) {
               return genre[i];
            }
            else {
                return genre[i] + ", ";
            }
        }

    // Method to display directors of the movie
    string getDirector(int i) {
    	string directorInfo;
        directorInfo += "Name: " + director[i].getfname() + " " + director[i].getlname() + "\n";
        directorInfo += "Gender: " + director[i].getgender() + "\n\n";
        return directorInfo;    
    }

    // Method to display actors of the movie
    string getActor(int i) {
        string actorInfo;
        actorInfo += "Name: " + actor[i].getfname() + " " + actor[i].getlname() + "\n";
        actorInfo += "Gender: " + actor[i].getgender() + "\n\n";
        return actorInfo;
    }
    
    // Method to validate input for attributes like title, synopsis, MPAA rating, and genre
    string validateInput(string input, string attribute) {
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

