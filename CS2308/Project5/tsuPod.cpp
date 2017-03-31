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

TsuPod::TsuPod(int mem, int songCount)
{
	cout << "NEW TSUPOD: " << endl;
	memory = mem;
	songs = songCount;
	
}

/*//Create original file of songs
void OriginalSongs(ifstream file)
{

25;
"Shape of you	Ed Sheeran	2";
"Castle on the Hill	Ed Sheeran	3";
"Paris	Chain Smokers	2";
"Issues	Julia Michaels	1";
"Starboy	The Weeknd	3";
"Closer	Chainsmokers	2";
"Side to Side	Ariana Grande	3";
"Fake Love	Drake	2";
"Heathens	Twenty One Pilots	4";
"Caroline	Anime	3";
"Scars To Your Beautiful	Alessia Cara	2";
"All Time Low	Jon Bellion	2";
"Mercy	Shawn Mendes	4";
"I Don't Wanna Live Forever	Taylor Swift	4";
"Love On The Brain	Rihanna	3";
"Treat You Better	Shawn Mendes	3";
"Blue Ain't Your Color	Keith Urban	4";
"I Hate U I Love U	Gnash	4";
"Don't Let Me Down	Chainsmokers	2";
"HandClap	Fitz And The Tantrums	1";
"Immortal	J. Cole	1";
"Make Me (Cry)	Noah Cyrus	6";
"Twin Size Mattress	The Front Bottoms	7";
"Swimming Pool	The Front Bottoms	4";
"Au Revoir	The Front Bottoms	8";



}*/

//Add desired song to playlist
int TsuPod::addSong(Song s)
{
	myio.open("tsupod_memory.dat", ios::binary | ios::out | ios::app);
	myio << s.getTitle() << s.getArtist() << s.getSize() << endl;
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


}

//Display the total memory space left over
void TsuPod::getTotalMem()
{


}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem()
{

}

