/****************************************************
Name: Samantha Coyle
Date: 4/6/2017
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "Song.h"

using namespace std;

//Default constructor to initialize title, artist, and size
Song::Song()									
{
	strcpy(artist, "Empty");
	strcpy(title, "Empty");
	size = 0;
	pos = 0;
}

//Other constructor for Song with parameters
Song::Song(char *cArtist, char *cTitle, int cSize, int cpos)			// Constructor with parameters
{
	strcpy(artist, cArtist);
	strcpy(title, cTitle);
	size = cSize;
	pos = cpos;
}

//Deep copy artist variable as string
void Song :: setSongArtist(char *songArtist) {strcpy(artist, songArtist);}

//Deep copy title variable as string
void Song :: setSongTitle(char *songTitle) {strcpy(title, songTitle);}

//Set size of song object
void Song :: setSongSize(int songSize){size = songSize;}

//Set the position of the song
void Song :: setSongPos(int songNum){pos = songNum;}

//Gets the song's artist from the object
const char* Song :: getSongArtist() const {return artist;}

//Gets the song's title from the object
const char* Song :: getSongTitle() const {return title;}

//Gets the song's size from the object
int Song :: getSongSize() const {return size;}

//Overload operator to check song titles for greater than
bool Song :: operator > (const Song &s1)
{
	//Variable to check if title is greater
	bool check = false;

	if(*title > *s1.title)
		check = true;

	return check;
}

//Overload operator to check songe titles for less than
bool Song::operator < (const Song &s1)
{
	//Variable to check if title is less than
	bool check = false;

	if(*title < *s1.title)
		check = true;

	return check;
}

//Overload operator to check if songs are equal
bool Song :: operator == (const Song &s1)
{
	//Variable to check if title is greater
	bool check = false;

	if(*title == *s1.title)
		check = true;

	return check;
}

//Overload operator to check if songs are not equal
bool Song :: operator != (const Song &sBlank)
{
	//Variable to check if title is greater
	bool check = false;

	if(*title != *sBlank.title)
		check = true;

	return check;
}
