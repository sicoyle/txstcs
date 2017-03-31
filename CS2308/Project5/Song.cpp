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
	std::cout << "new song: " << t << ", by " << a << endl;
}
