/*****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 9
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{
	//return code variable
	int retCode = 0;
	int memTotal = 0;
	int songTotal = 0;
	//Create object
	TsuPod myPod(10, 1);
	

//	retCode = myPod.initialize();
//		cout << "Initialized: " << retCode << endl;
//	myPod.showList();


	//Add 25 Songs
	myPod.addSong("Title", "Artist", 2, 0, memTotal, songTotal);	

	myPod.showList();

//	myPod.addSong(Song("Shape of you", "Ed Sheeran", 2));
/*	myPod.addSong(Song("Castle on the Hill", "Ed Sheeran", 3));
	myPod.addSong(Song("Paris", "Chain Smokers", 2));
	myPod.addSong(Song("Issues", "Julia Michaels", 1));
	myPod.addSong(Song("Starboy", "The Weeknd", 3));
	myPod.addSong(Song("Closer", "Chainsmokers", 2));
	myPod.addSong(Song("Side to Side", "Ariana Grande", 3));
	myPod.addSong(Song("Fake Love", "Drake", 2));
	myPod.addSong(Song("Heathens", "Twenty One Pilots", 4));
	myPod.addSong(Song("Caroline", "Anime", 3));
	myPod.addSong(Song("Scars To Your Beautiful", "Alessia Cara", 2));
	myPod.addSong(Song("All Time Low", "Jon Bellion", 2));
	myPod.addSong(Song("Mercy", "Shawn Mendes", 4));
	myPod.addSong(Song("I Don't Wanna Live Forever", "Taylor Swift", 4));
	myPod.addSong(Song("Love On The Brain", "Rihanna", 3));
	myPod.addSong(Song("Treat You Better", "Shawn Mendes", 3));
	myPod.addSong(Song("Blue Ain't Your Color", "Keith Urban", 4));
	myPod.addSong(Song("I Hate U I Love U", "Gnash", 4));
	myPod.addSong(Song("Don't Let Me Down", "Chainsmokers", 2));
	myPod.addSong(Song("HandClap", "Fitz And The Tantrums", 1));
	myPod.addSong(Song("Immortal", "J. Cole", 1));
	myPod.addSong(Song("Make Me (Cry)", "Noah Cyrus", 6));
	myPod.addSong(Song("Twin Size Mattress", "The Front Bottoms", 7));
	myPod.addSong(Song("Swimming Pool", "The Front Bottoms", 4));
	myPod.addSong(Song("Au Revoir", "The Front Bottoms", 8));
*/
	return 0;	
}
