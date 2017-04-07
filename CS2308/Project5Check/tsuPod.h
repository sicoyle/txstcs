/****************************************************
Name: Samantha Coyle
Date: 4/6/2017
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef TsuPod_h
#define TsuPod_h

#include "Song.h"
#include <string>
#include <fstream>

using namespace std;

//Declare a class for tsupod including private and public members
class TsuPod
{
	private:
		Song song;
		int maxSize;
		fstream myio;

		//Number of consumed songs
		int cSongs;

	public:
		TsuPod();
		TsuPod(int, int);
		int initialize();
		int addSong(string, string, int, int, int&, int&);
		int removeSong(string, string, int, int, int&, int&);
		int clearSongList();
		int showSongList();
		int sortSongList(int);
		int TotalMem() const;
		int RemainingMem(int) const;
		int ConsumedSongNum() const;
		void setSong(Song);
		void closeBinary();
};
#endif
