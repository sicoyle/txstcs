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
#include <cstring>

#include <string>


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
}

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
	
	//Look through number of songs and initialize
	for(int index = 0; index < songs; index++)
	{
cout << "tsupod::init()"; 
		myio.seekp((index)*sizeof(s), ios::beg);
		myio.write(reinterpret_cast<char*>(&s), sizeof(s));
cout << " done." << endl;
	}

	//Close the file
	myio.close();

	return 0;
}	

//Add desired song to playlist
int TsuPod::addSong(string T, string A, int S, int numSong, int &songTotal, int &memTotal)
{
	Song s;
	char c_stringT[256]; //C string title
	char c_stringA[256]; //C string artist

	myio.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
	cout << "tsupod::addsong():" << T << A << S << endl;
	//Check that size is a valid number. Must be > 0.
	if(S < 0)
	{
		cout << "Error: size must be greater than 0. Song not added." << endl;
		return -2;
	}

	//Error if too many songs
	if(songs > maxSongs)
	{
		cout << "Error: lack of space. Song not added." << endl;
		return -2;
	}
	
	//Error if blank entry
	if(T == " " || A == " ")
	{
		cout << "Error: title/artist can not be blank." << endl;
		return -2;
	}

	//If not errors, increment song total
	songTotal++;

	//Add size of added song to mem total
	memTotal += S;

	//Error if too many songs
	if(songTotal > maxSongs)
	{
		cout << "Error: Song not added. Too many songs." << endl;
		return -2;
	}

	//Error if too much memory would be used
	if(memTotal > maxMem)
	{
		cout << "Error: Song not added. Too much memory would be used." << endl;
		return -2;
	}

	//if(getRemainingMem() <= getTotalMem())
	
cout << "sizeof(Song) == " << sizeof(Song) << endl;

cout << "fixing to write: song.title() == " << s.getTitle() << endl;
	
	//Convert string variables to c strings
	strcpy(c_stringT, T.c_str());
	strcpy(c_stringA, A.c_str());

	//Assign data to song object
	s.setTitle(c_stringT);
	s.setArtist(c_stringA);
	s.setSize(S);
	cout << "HERE title: " << c_stringT << " artist " << c_stringA << " size " << S << endl;
	
	myio.seekp((numSong-1) * sizeof(s), ios::beg);

	long pos = myio.tellp();
	cout << "inputting song in bytes addr [ " << pos; 
	myio.write(reinterpret_cast<char *>(&s), sizeof(s));
//	myio.write(s.getTitle().c_str(), s.getTitle().size());
//	myio.write(s.getArtist().c_str(), s.getArtist().size());
//	myio.write(reinterpret_cast<char *>(&s.getSize()),sizeof(s.getSize()));



pos = myio.tellp();
cout << " -> " << pos << "];" << endl;
	cout << endl << "Cstring title " << c_stringT << " artist " << c_stringA << " " << S << endl;

	//Write data to file
	myio.seekp(0L, ios::beg);	
	

	//Close the file
	myio.close();
	return 0;
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
	Song s;	

	myio.open("tsupod_memory.dat", fstream::binary | fstream::in);
	cout << "Song List: " << endl;
	
	for(int index = 0; index < songs; index++)
	{
		myio.seekg((index)*sizeof(s), myio.beg);
long pos = myio.tellg();
cout << "reading song from bytes addr [ " << pos << " -> "; 
		myio.read(reinterpret_cast<char*>(&s), sizeof(s));
pos = myio.tellg();
cout << pos << " ];" << endl;
		cout << "Song number: " << index + 1 << " titled: " << s.getTitle();
		cout << " written by: " << s.getArtist() << " with size of: " << s.getSize();
		cout << " MB" << endl;
	}

	myio.close();
}

//Display the total memory space left over
int TsuPod::getTotalMem()
{
	return maxMem;
}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem()
{
//	return memTotal;
}

