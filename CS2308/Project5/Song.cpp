/******************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include "Song.h"

//Delete this
#include <iostream>

using namespace std;

//Constructors
Song::Song()
{
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

Song::Song(string t, string a, int s)
{
	setTitle(t);
	setArtist(a);
	setSize(s);
	cout << "Song Constructor!!\nSong::Song(" << t << ", " << a << ", " << s << ");" << endl;
}

int Song::blobSize() {
	return getTitle().size() + getArtist().size() + 2 + sizeof(int);
}
//Accessors
//string Song::getTitle() const {return title;}
//string Song::getArtist() const {return artist;}
//i/nt Song::getSize() const {return size;}

//Mutators
//void Song::setTitle(string t) {title = t}
//void Song::setArtist(string a) {artist = a}
//void Song::setSize(int s) {size = s}

/*
const bool Song::operator == (const Song &s2)
{
	bool status;

	if(!(title == s2.title && artist == s2.artist && size == s2.size))
		status =  -1;
	else
		status = 0;

	return status;
}
*/


























/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
/*#include <string>
#include "Song.h"

//Delete this
#include <iostream>

using namespace std;

//Constructors
Song::Song()
{
	strcpy(title, "EMPTY");
	strcpy(artist, "EMPTY");
	size = 0;
}

Song::Song(char * c_stringT, char * c_stringA, int s)
{
	strcpy(title, c_stringT);
	strcpy(artist, c_stringA);
	size = s;
	std::cout << "new song: " << title << ", by " << artist << " MEM: " << size << endl;
}

//Mutators
void Song::setTitle(char * t) {strcpy(title, t)}
void Song::setArtist(char * a) {strcpy(artist, a)}
void Song::setSize(int s) {size = s}

//Accessors
const char * Song::getTitle() const {return title;}
const char * Song::getArtist() const {return artist;}
const int Song::getSize() const {return size;}

*/

