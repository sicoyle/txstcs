/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#ifndef Song_h
#define Song_h

#include <string>

using namespace std;

class Song
{
	private:
	string artist;
	string title;
	int 	size;	// disk space

	public:
	//Accessors
	string getTitle()  { return title; }
	string getArtist() { return artist; }
	int getSize()      { return size;}

	//Mutators
	void setTitle(string t) {title = t;}
	void setArtist(string a) {artist = a;}
	void setSize(int s) {size = s;}

	//Overload
	//????????????
	//helpers
	int blobSize();
	//Constructors
	Song();
	Song(string title, string artist, int size);

	
	const bool operator == (const Song &s);
};
#endif


















/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
/*#ifndef Song_h
#define Song_h

#include <string>

using namespace std;

class Song
{
	private:
	char artist [256];
	char title[256];
	int size;

	public:
	Song();
	Song(char *, char *, int);

	//Accessors
	const char * getTitle() const {return title;}
	const char * getArtist() const {return artist;}
	int getSize() const {return size;}

	//Mutators
	void setTitle(char * t) {title = t;}
	void setArtist(char * a) {artist = a;}
	void setSize(int s) {size = s;}

	//Overload
	//????????????

	//Constructors
	Song();
	Song(string title, string artist, int size);

	//bool operator < (const Song 
};
#endif
*/
