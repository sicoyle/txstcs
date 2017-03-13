/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 5
Hours spent solving the problem: 4
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>
#include <iomanip>
using namespace std;

//Global variables
const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

struct TsuPod
{
	string title;
	string artist;
	int size;
};

//Instance
TsuPod tsuPod[NUM_SONGS];
	
//Initialize the tsu pod to blanks and 0 memory size
void initTsuPod()
{
	//Initialize
	for(int i = 0; i < NUM_SONGS; i++)
	{
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;		
	}
}

//Add songs to tsuPod
int addSong(string newTitle, string newArtist, int size)
{
	int i = 0;
	int total = 0;
	int memoryLeft = 0;

	//Calculate the total memory amount left
	for(int index = 0; index < NUM_SONGS; index++)
		total += tsuPod[index].size;
	memoryLeft = MEMORY_SIZE - total;

	//If you don't have enough memory, return -1
	if(size > memoryLeft)
		return -1;

	while(i < NUM_SONGS)
	{
		if(tsuPod[i].size > 0)
			i++;
		else
		{	
			tsuPod[i].title = newTitle;
			tsuPod[i].artist = newArtist;
			tsuPod[i].size = size;
			return 0;
		}
	}
	
	if(i >= 8)
		return -2;		

}

//Remove song
int removeSong(string title)
{
	for(int i = 0; i < NUM_SONGS; i++)
	{
		if(tsuPod[i].title == title)
		{
			tsuPod[i].title = "EMPTY";
			tsuPod[i].artist = "EMPTY";
			tsuPod[i].size = 0;
			return 0;
		}

	}
	return -1;
}

//Clear memory
void clearMemory()
{
	for(int i = 0; i < NUM_SONGS; i++)
	{
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;
	}

}

//Display the song list
void showSongList()
{
	cout << left << setw(15) << "Slot Number" << left << setw(25);
	cout << "Title" << left << setw(20) << "Artist";
	cout << left << setw(15) << "Size (MB)" << endl;

	for(int i = 0; i < NUM_SONGS; i++)
	{
		cout << left << setw(15) << i+1;
		cout << left << setw(25) << tsuPod[i].title;
		cout << left << setw(20) << tsuPod[i].artist;
		cout << left << setw(15) << tsuPod[i].size << endl;
	}
}

//Shuffle the songs
void shuffle()
{


}


