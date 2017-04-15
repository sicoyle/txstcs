/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>

using namespace std;

class Song
{
	private:
		string artist;
		string title;
		int 	size;

	public:
		//Constructors
		Song();
		Song(string, string, int);

		//Destructor
		~Song(){};
	
		//Accessors
		string getTitle()  {return title;}
		string getArtist() {return artist;}
		int getSize()      {return size;}

		//Mutators
		void setTitle(string t) {title = t;}
		void setArtist(string a) {artist = a;}
		void setSize(int s) {size = s;}

		//Overload
		bool operator == (const Song &);
		bool operator > (const Song &);
		bool operator < (const Song &);
};
