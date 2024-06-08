#include <iostream>

using namespace std;

// Class Declaration
class DramaSeries{
	private:
		string title;
		string genre;
		int episode;
		
	public:
		// This is a constructor
		DramaSeries(string newTitle, string newGenre, int newEpisode){
			title = newTitle;
			genre = newGenre;
			episode = newEpisode;
		}
		
		// This method displays the title, genre and number of episodes.
		void displayDetails() {
			cout << "Series Title: " << title << endl;
			cout << "Series Genre: " << genre << endl;
			cout << "Series Number of Episodes: " << episode << endl;
		}	
};
