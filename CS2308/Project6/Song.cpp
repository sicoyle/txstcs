/*****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include "Song.h"

using namespace std;

//Default constructor
Song::Song()
{
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

//Constructor with parameters
Song::Song(string t, string a, int s)
{
	setTitle(t);
	setArtist(a);
	setSize(s);
}

//Operator to check for equal songs
bool Song::operator == (const Song & rs)
{
	if((title != rs.title) && (artist != rs.artist) && (size != rs.size))
		return false;
	else
		return true;
}

//Operator to check for greater than
bool Song::operator > (const Song & rs)
{
	if(title > rs.title)
		return title > rs.title;

	else if(artist > rs.artist)
		return artist > rs.artist;

	else if(size > rs.size)
		return size > rs.size;

	else
		return false;
}

//Operator to check for less than
bool Song::operator < (const Song & rs)
{
	if(title < rs.title)
		return title < rs.title;

	else if(artist < rs.artist)
		return artist < rs.artist;

	else if(size < rs.size)
		return size < rs.size;

	else
		return false;
}
