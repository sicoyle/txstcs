/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#ifndef tsuPod_h
#define tsuPod_h
#include "Song.h"

using namespace std;

class TsuPod
{
	private:
	int memory, cmem, songs, csongs; //tsupod resources memory&songs, current count : cmem/csongs
	int * offsets;
void updateOffsets(int, int);
int sizeOf(int);
int getsOffset(int);
int insertSong(Song, int);
void printOffsets();

	public:
	//Constructor
	TsuPod(int mem, int songCount);
	
	//Functions
	int initialize();	
	int addSong(string T, string A, int S, int songNum);
	int removeSong(Song s);
	int clearList();
	int sortList();
	void showList();
	int getTotalMem();
	int shuffle();
	int getRemainingMem();
};

#endif


