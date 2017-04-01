/****************************************************
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
	std::cout << "new song: " << t << ", by " << a << " MEM: " << s << endl;
}

//Accessors
//string Song::getTitle() const {return title;}
//string Song::getArtist() const {return artist;}
//i/nt Song::getSize() const {return size;}

//Mutators
//void Song::setTitle(string t) {title = t}
//void Song::setArtist(string a) {artist = a}
//void Song::setSize(int s) {size = s}



