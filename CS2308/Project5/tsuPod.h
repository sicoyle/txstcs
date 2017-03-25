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
	int maxMem, songCounter, memLeft;

	public:
	//Constructor
	TsuPod();

	//Functions

	int addSong(Song);
	int removeSong(Song);
	int clearList();
	int sortList();
	void showList();
	void showTotalMem();
	void showRemaining();
	int shuffle();
	int getRemainingMem();
};

#endif


