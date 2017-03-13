/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 4
Hours spent solving the problem: 6
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
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
	//Error if i is greater or equal to 8	
	if(i >= 8)
		return -2;		

}

//Remove song from playlist
int removeSong(string title)
{
	//Find matching index and mark as empty
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
	//If song not found, return -1
	return -1;
}

//Clear memory
void clearMemory()
{
	//Clear all slots in playlist
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
	TsuPod temp;
	int randomIndex = 0;
	srand(time(0));
	for(int i = 0; i < NUM_SONGS; i++)
	{
		randomIndex = rand() % NUM_SONGS;
		temp = tsuPod[i];
		tsuPod[i] = tsuPod[randomIndex];
		tsuPod[randomIndex] = temp;

	}

}


