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
	string artist, title;
	int size;

	public:
	//Accessors
	string getTitle() const {return title;}
	string getArtist() const {return artist;}
	int getSize() const {return size;}

	//Mutators
	void setTitle(string t) {title = t;}
	void setArtist(string a) {artist = a;}
	void setSize(int s) {size = s;}

	//Overload
	//????????????

	//Constructors
	Song();
	Song(string title, string artist, int size);

	//Constructors
//	Song();
	//{
		//setTitle("EMPTY");
		//setArtist("EMPTY");
	//	setSize(0);
	//};

	//Song(string title, string artist, int size);
	//{
	//	setTitle(t);
	//	setArtist(a);
	//	setSize(s);
	//};

};
#endif
