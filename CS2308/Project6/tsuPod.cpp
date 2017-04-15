/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
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
#include <stdlib.h>
#include <string>

using namespace std;

//Constructor for tsuPod with parameters
TsuPod::TsuPod(int mem)
{
	head = NULL;		//initialize head to null
	totMem = mem;		//initialize total memory
	cmem = csongs = 0;	//initialize consumed mem and songs to 0
}

//Deconstructor for tsuPod
TsuPod::~TsuPod(){}

//Function to check if song can be added to playlist
int TsuPod::checkAddSong(Song mySong)
{
	//Error if blank title and artist for song
	if(mySong.getTitle() == "" || mySong.getArtist() == "")
	{
		cout << "Error: title and artist can not be blank." << endl;
		return -1;
	}
	
	//Error if invalid size and not enough memory
	else if((mySong.getSize() < 1) && (mySong.getSize() > getRemainingMem()))
	{
		cout << "Error: size must be valid. ";
		cout << "There also needs to be enough memory available" << endl;
		return -1;
	}
}

//Function to add a song to playlist
int TsuPod::addSong(Song mySong)
{
	//Call function to check if song can be added
	if((checkAddSong(mySong)) < 0)
		return -1;

	//Pointer for new node and to traverse through list
	songNode * newNode, * nodePtr;

	//Initialize new node
	newNode = new songNode;
	newNode -> s = mySong;
	newNode -> next = NULL;

	//Increment consumed songs and memory
	csongs++;
	cmem = cmem + mySong.getSize();

	//If empty list, make head
	if(head == NULL)
		head = newNode;

	else
	{
		nodePtr = head;

		//Traverse to last node
		while(nodePtr -> next != NULL)
			nodePtr = nodePtr -> next;

		//Point node to a new node
		nodePtr -> next = newNode;
	}
	
	return 0;
}

//Function to remove a song from the playlist
int TsuPod::removeSong(Song mySong)
{
	//Variable for finding song to remove
	bool found = false;
	
	//Pointer for traversal and previous node
	songNode * previousNode, * nodePtr;

	//Initialize pointers
	* previousNode = NULL;
	* nodePtr = head;

	//Check for empty list
	if(head == NULL)
	{
		cout << "Error: empty list." << endl;
		return -1;
	}

	
	





}








//Show the contents of the song list
void TsuPod::showList()
{
	//Pointer to traverse through list
	songNode *nodePtr;

	//Initialize to start
	nodePtr = head;

	//Provide header
	cout << endl;
	cout << left << setw(25) << "Title" << left << setw(20) << "Artist";
	cout << left << setw(15) << "Size (MB)" << endl;

	//While there are still songs to print, show content and move to next song
	while(nodePtr != NULL)
	{
		cout << left << setw(25) << nodePtr -> s.getTitle();
		cout << left << setw(20) << nodePtr -> s.getArtist();
		cout << left << setw(15) << nodePtr -> s.getSize() << endl;

		nodePtr = nodePtr -> next;
	}
}






//Get the total memory of the tsuPod
int TsuPod::getTotalMem() {return totMem;}

//Get the remaining memory space left in the tsuPod
int TsuPod::getRemainingMem() {return (getTotalMem() - cmem);}
