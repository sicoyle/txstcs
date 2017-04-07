/****************************************************
Name: Samantha Coyle
Date: 4/6/2017
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{
	//Create tsupod instance
	TsuPod myPod(100, 25);
	int tMem;					
	int tSongs = tMem = 0;

	//Display total memory
	int retCode = myPod.TotalMem();
	cout << "Total memory in tsupod: " << retCode << endl << endl;
			
	
	//Show that tsupod is initialized			
	retCode = myPod.initialize();
		cout << "tsupod successfully initialized: " << retCode << endl;

	//Show initialized tsupod
	retCode = myPod.showSongList();	
	cout << endl << endl;

	//Add in 25 Songs correctly
    	retCode = myPod.addSong("Hello", "Adele", 5, 1, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Castle on the Hill", "Ed Sheeran",6, 2, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Paris", "Chain Smokers", 3, 3, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Issues", "Julia Michaels", 1, 4, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Starboy", "The Weeknd", 4, 5, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Closer", "Chainsmokers", 2, 6, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl; 
	retCode = myPod.addSong("Side to Side", "Ariana Grande", 3, 7, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Fake Love", "Drake", 3, 8, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Heathens", "Twenty One Pilots", 3, 9, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Caroline", "Anime", 3, 10, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl; 
	retCode = myPod.addSong("Scars To Your Beautiful", "Alessia Cara", 3, 11, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("All Time Low", "Jon Bellion", 3, 12, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Mercy", "Shawn Mendes", 3, 13, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("I Don't Wanna Live Forever", "Taylor Swift", 3, 14, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Love On The Brain", "Rihanna", 3, 15, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Treat You Better", "Shawn Mendes", 3, 16, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl; 
	retCode = myPod.addSong("Blue Ain't Your Color", "Keith Urban", 3, 17, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("I Hate U I Love U", "Gnash", 3, 18, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Don't Let Me Down", "Chainsmokers", 3, 19, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("HandClap", "Fitz And The Tantrums", 3, 20, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Immortal", "J. Cole", 3, 21, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Make Me (Cry)", "Noah Cyrus", 3, 22, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Twin Size Mattress", "The Front Bottoms", 3, 23, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Swimming Pool", "The Front Bottoms", 3, 24, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl;
	retCode = myPod.addSong("Au Revoir", "The Front Bottoms", 3, 25, tMem, tSongs);
		cout << "Successfully added song: " << retCode << endl << endl;

	retCode = myPod.addSong("Gold", "Kiiara", 8, 26, tMem, tSongs);
		cout << "Unsuccessfully added song: " << retCode << endl;

	cout << endl << "tsupod with 25 songs added." << endl;
	myPod.showSongList();

	//Display tsupod memory after song addition
	retCode = myPod.RemainingMem(tMem);
	cout << endl << "After song addition, remaining memory is: " << retCode << endl;	

	//Sort list and display
//	myPod.sortSongList(tSongs);	
//	myPod.showSongList();

	//Remove a song and display
	retCode = myPod.removeSong("Side to Side", "Ariana Grande", 3, 7, tMem, tSongs);
		cout << "Song successfully removed: " << retCode << endl;

	//Show failure to remove a song
	retCode = myPod.removeSong("Bad and Boujee", "Migos", 10, 8, tMem, tSongs);
		cout << "Song unsuccesfully removed: " << retCode << endl;


	myPod.showSongList();

	retCode = myPod.RemainingMem(tMem);
	cout << "Remaining memory in tsupod after song removal: " << retCode << endl;


	//Clear the tsupod and display
	myPod.clearSongList();						
	myPod.showSongList();

	myPod.closeBinary();							

	return 0;
}
