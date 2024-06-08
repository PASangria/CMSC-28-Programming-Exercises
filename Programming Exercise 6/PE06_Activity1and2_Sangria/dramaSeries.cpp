// Program Creator: Prescious Apple D. Sangria
// Course: CMSC 28
// Program Description: This program displays the title, genre, and number of episodes of a drama series.

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


int main() {
	DramaSeries series1("While You Were Sleeping", "Romance", 16);
	series1.displayDetails();
	
	return 0;
}

