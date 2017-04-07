/****************************************************
Name: Samantha Coyle
Date: 4/6/2017
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef Song_h
#define Song_h

#include <string>
#include <fstream>

using namespace std;

class Song
{
	private:
		char artist[256];
		char title[256];
		int size;
		int pos;
	public:
		Song();
		Song(char*, char*, int, int);
		void setSongArtist(char*);
		void setSongTitle(char*);
		void setSongSize(int);
		void setSongPos(int);
		const char* getSongArtist() const;
		const char* getSongTitle() const;
		int getSongSize() const;
		bool operator >(const Song &s);
		bool operator <(const Song &s);
		bool operator ==(const Song &s);
		bool operator !=(const Song &sBlank);
};
#endif
