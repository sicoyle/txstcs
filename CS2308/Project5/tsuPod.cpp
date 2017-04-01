/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>


//#include "Song.h"

using namespace std;

fstream myio;

//Constructor with parameters
TsuPod::TsuPod(int mem, int songCount)
{
	cout << "NEW TSUPOD: " << endl;
	memory = mem;
	songs = songCount;
	maxMem = 100;
	maxSongs = 25;
	songCount = 0;	
}

/*//Create original file of songs
void OriginalSongs(ifstream file)
{25;*/

int TsuPod::initialize()
{
	//Create object
	Song s;

	//Open file in binary mode
	myio.open("tsupod_memory.dat", ios::binary | ios::out | ios::in | ios::app);

	//Check that file opens
	if(myio.fail())
	{
		cout << "Error: file did not open." << endl;
		return -1;
	}

	for(int i = 0; i < songs; i++)
		cout << "HELLO" << endl;
	
	return 0;
}	

//Add desired song to playlist
int TsuPod::addSong(Song s)
{
	
	if(getRemainingMem() <= getTotalMem())
		myio.write(reinterpret_cast<char*>(&s), sizeof(s));
	
//	cout << "READ: " << myio.read(reinterpret_cast<char*>(&s), sizeof(s)) << endl;

	myio.close();
}

//Remove desired song to playlist
int TsuPod::removeSong(Song s)
{



}

//Clear the song list
int TsuPod::clearList()
{



}

//Sort the song list alphabetically
int TsuPod::sortList()
{


}

//Dislay the list to the console
void TsuPod::showList()
{
	cout << "Song List: " << endl << endl;
	
	

}

//Display the total memory space left over
int TsuPod::getTotalMem()
{
	return memLeft;
}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem()
{

}

