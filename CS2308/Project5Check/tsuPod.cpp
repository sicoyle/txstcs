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
#include <stdio.h>
#include <string.h>
#include "tsuPod.h"

using namespace std;

//Default constructor for number of songs consumed
//and the max size of the tsupod
TsuPod :: TsuPod()	{cSongs = maxSize = 0;}

//Constructor with parameters passed for tsupod
TsuPod :: TsuPod(int ConsumedSize, int ConsumedSongs)
{
	maxSize = ConsumedSize;
	cSongs = ConsumedSongs;

}

//Initialize a tsupod
int TsuPod :: initialize()
{
	//Create object
	Song s;									

	//Open the file in binary mode
	myio.open("tsupod_memory.dat", ios :: in | ios :: out | ios :: binary);

	//Error message for file failing to open
	if(myio.fail())									
	{
		cout << endl << "Error: file did not open." << endl;
		return -1;
	}

	//Initialize each song
	for(int index = 0; index < cSongs; index++)				
	{
		myio.seekp((index)*sizeof(s), ios :: beg);
		myio.write(reinterpret_cast < char * > (&s), sizeof(s));
	}

	return 0;
}

//Add desired song to the playlist of tsupod
int TsuPod :: addSong(string T, string A, int S, int songCount, int &tMem, int &tSongs)
{
	songCount = songCount - 1;
	//Create object
	Song mySong;									

	//Hold song title and artist in char array
	char Title[256];								
	char Artist[256];

	//Error if invalid size and size > available size
	if(S < 0)
	{
		cout << endl << "Error: size must be > 0." << endl;
		return -2;
	}

	//Error if too many songs trying to be added
	if(songCount == cSongs)
	{
		cout << endl << "Error: lack of space. Song not added." << endl;
		return -2;
	}

	//Error if blank entry
	if(T == " " || A == " ")
	{
		cout << endl << "Error: title/artist can not be blank." << endl;
		return -2;
	}

	//Increment totoal songs and memory of tsupod
	tSongs = tSongs + 1;
	tMem = tMem + S;	

	//Error for if new total song memory is not valid
	if(tMem > maxSize)
	{
		cout << endl << "Error: no more room in tsupod." << endl;
		return -2;
	}

	//Error for if new total song count is not valid
	if(tSongs > cSongs)
	{
		tSongs = tSongs - 1;
		tMem = tMem - S;
		cout << endl << "Error: lack of space. Song not added." << endl;
		return -2;
	}					

	//Copy c string into array
	strcpy(Title, T.c_str());			
	strcpy(Artist, A.c_str());

	//Fill in object data
	mySong.setSongTitle(Title);						
	mySong.setSongArtist(Artist);							
	mySong.setSongSize(S);								
	mySong.setSongPos(songCount);					

	//Write to file
	myio.seekp((songCount--)*sizeof(mySong), ios :: beg);
	myio.write(reinterpret_cast < char * > (&mySong), sizeof(mySong));		
	myio.seekp(0L, ios :: beg);

	return 0;
}

//Remove desired song from tsupod playlist
int TsuPod :: removeSong(string T, string A, int S, int songCount, int &tMem, int &tSongs)
{
	//Declare object
	Song mySong;								

	//Decrement total song count and memory
	tSongs = tSongs - 1;
	tMem = tMem - S;

	//Error if invalid total memory
	if(tMem < 0)
	{
		tSongs = tSongs + 1;
		tMem = tMem + S;
		cout << endl << "Error: song not removed; memory must be > 0.";
		return -2;
	}


//FIXXXXX








	T = "Empty";								
	A = "Empty";
	S = 0;






	char Title[256];								
	char Artist[256];

	strcpy(Title, T.c_str());	
	strcpy(Artist, A.c_str());

	mySong.setSongTitle(Title);
	mySong.setSongArtist(Artist);
	mySong.setSongSize(S);

	//Put empty as song title/artist for removed song
	myio.seekp((songCount - 1)*sizeof(mySong), ios :: beg);
	myio.write(reinterpret_cast < char * > (&mySong), sizeof(mySong));	
	myio.seekp(0L, ios :: beg);

	return 0;
}

//Show the current tsupod playlist
int TsuPod :: showSongList()
{
	//Declare object
	Song mySong;								

	//Display every song in tsupod
	for(int index = 0; index < cSongs; index++)				
	{
		myio.seekg((index)*sizeof(mySong), ios :: beg);
		myio.read(reinterpret_cast < char * >(&mySong), sizeof(mySong));

	cout << "Title: " <<  mySong.getSongTitle()	<< " " << mySong.getSongArtist() << " "	<< mySong.getSongSize() << " MB." << endl;
}

	myio.clear();
	myio.seekg(0L, ios :: beg);

	cout << endl;

	return 0;
}

int TsuPod::clearSongList()
{
	//Declare object
	Song mySong;									

	//Remove all songs in tsupod
	for(int index = 0; index < cSongs; index++)				
	{
		myio.seekp((index)*sizeof(mySong), ios :: beg);
		myio.write(reinterpret_cast < char * >(&mySong), sizeof(mySong));
	}

	return 0;
}

//Sort the songs in the tsupod
int TsuPod :: sortSongList(int tSongs)					
{
	//Create temporary objects to help sorting
	Song mySong;
	Song mySong2;
	Song myTemp;
	Song myBlank;
	bool swap;

	//Read in songs in tsupod and 
	for(int count = 0; count < tSongs; count++)
	{
		swap = false;
		myio.seekg((count)*sizeof(mySong), ios :: beg);	
		myio.read(reinterpret_cast < char * >(&mySong), sizeof(mySong));

		for(int index = count++; index < (tSongs++); index++)
		{
			myio.seekg((index)*sizeof(mySong2), ios :: beg);
			myio.read(reinterpret_cast < char * >(&mySong2), sizeof(mySong));

			if(mySong2 < mySong)						
			{
				if(mySong2 != myBlank)
				{
					myTemp = mySong;
					mySong = mySong2;
					mySong2 = myTemp;

					myio.seekp((index)*sizeof(mySong2), ios :: beg);
					myio.write(reinterpret_cast < char * >(&mySong2), sizeof(mySong2));

					swap = true;
				}
			}

////////DELETE???????????????


			if(mySong2 > mySong)
				swap = false;



			if(mySong2 == mySong)
				swap = false;


///UP TO HERE???????



		}

		myio.seekp((count)*sizeof(mySong), ios :: beg);	
		myio.write(reinterpret_cast < char * >(&mySong), sizeof(mySong));
	}

	return 0;
}

//Get the song number from tsupod
int TsuPod :: ConsumedSongNum() const {return cSongs;}

//Get the total memory of tsupod
int TsuPod :: TotalMem() const {return maxSize;}

//Get the remaining memory of tsupod
int TsuPod :: RemainingMem(int tMem) const {return (TotalMem() - tMem);}

//Close file
void TsuPod :: closeBinary() {myio.close();}
