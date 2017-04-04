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
	TsuPod myPod(100, 25);

        myPod.addSong("Hello", "Adele", 1, 0);
	myPod.addSong("Castle on the Hill", "Ed Sheeran",2, 0);
	myPod.addSong("Paris", "Chain Smokers", 3, 0);
	myPod.addSong("Issues", "Julia Michaels", 4, 0);
	myPod.addSong("Starboy", "The Weeknd", 5, 0);
	myPod.addSong("Closer", "Chainsmokers", 2, 0);
	myPod.addSong("Side to Side", "Ariana Grande", 3, 0);
	myPod.addSong("Fake Love", "Drake", 3, 0);
	myPod.addSong("Heathens", "Twenty One Pilots", 3, 0);
	myPod.addSong("Caroline", "Anime", 3, 0);
	myPod.addSong("Scars To Your Beautiful", "Alessia Cara", 3, 0);
	myPod.addSong("All Time Low", "Jon Bellion", 3, 0);
	myPod.addSong("Mercy", "Shawn Mendes", 3, 0);
	myPod.addSong("I Don't Wanna Live Forever", "Taylor Swift", 3, 0);
	myPod.addSong("Love On The Brain", "Rihanna", 3, 0);
	myPod.addSong("Treat You Better", "Shawn Mendes", 3, 0);
	myPod.addSong("Blue Ain't Your Color", "Keith Urban", 3, 0);
	myPod.addSong("I Hate U I Love U", "Gnash", 3, 0);
	myPod.addSong("Don't Let Me Down", "Chainsmokers", 3, 0);
	myPod.addSong("HandClap", "Fitz And The Tantrums", 3, 0);
	myPod.addSong("Immortal", "J. Cole", 3, 0);
	myPod.addSong("Make Me (Cry)", "Noah Cyrus", 3, 0);
	myPod.addSong("Twin Size Mattress", "The Front Bottoms", 3, 0);
	myPod.addSong("Swimming Pool", "The Front Bottoms", 3, 0);
	myPod.addSong("Au Revoir", "The Front Bottoms", 3, 0);

	myPod.showList();

	//Remove a song
//	myPod.removeSong("Side to Side", "Ariana Grande", 3);

	return 0;	
}
