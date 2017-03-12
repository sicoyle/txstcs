/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 4
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>

using namespace std;

//Global variables
const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

//Initialize the tsu pod to blanks and 0 memory size
void initTsuPod()
{
	struct TsuPod
	{
		string title;
		string artist;
		int size;
	};

	//Instance
	TsuPod tsuPod[NUM_SONGS];
	
	//Initialize
	for(int i = 0; i < NUM_SONGS; i++)
	{
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;		
	}
}

//Add songs
int addSong(string newTitle, string newArtist, int size)
{
	

}


//Remove song
int removeSong(string title)
{


}

//Clear memory
void clearMemory()
{


}

//Display the song list
void showSongList()
{



}

//Shuffle the songs
void shuffle()
{


}


