/*****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 18
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{
	//instantiate myPod
	TsuPod myPod(100, 5);

        myPod.addSong("Hello", "Adele", 1, 0);
	myPod.addSong("Castle on the Hill", "Ed Sheeran",2, 0);
	myPod.addSong("Paris", "Chain Smokers", 3, 0);
	myPod.addSong("Issues", "Julia Michaels", 4, 0);
	myPod.addSong("Starboy", "The Weeknd", 5, 0);

//	myPod.showList();
	cout << "Removing song: " << myPod.getSong(3).getArtist() << endl;
	myPod.removeSong(myPod.getSong(2));


	









	for(int i = 4; i >= 0; i--)
	{	
//		if(!(myPod.getSong(i) == myPod.removeSong("Starboy", "The Weeknd", 5)))
//		{
//			temp.addSong(i);
//		}	

	}


	cout << "Song removed: " << endl;
	myPod.showList();	

//	for ( int i = 0; i < 100; i++ )
//		myPod.getSong(myPod.getRandomSongNumber());
//
for (int i = 4; i >= 0; i--)
myPod.getSong(i);
for ( int i = 0; i < 100; i++ )
myPod.getSong(myPod.getRandomSongNumber());
	return 0;	
}
