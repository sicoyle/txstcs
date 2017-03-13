/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 4
Hours spent solving the problem: 6
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main() 
{
    // Following code initializes the tsuPod 
    initTsuPod();

    cout << "Here is initialized playlist" << endl;
    
    // Following code lists all songs located in tsuPod memeory 
    showSongList();
    cout << endl;

    // Following code tests tsuPod input functionality
    // Correctly adds a song to playlist 
    int retCode = addSong("Issues", "Julia Michaels", 1);
	cout << "Successfully added song: " << retCode << endl;

    //Adds song to playlist
    retCode = addSong("Shape of You", "Ed Sheeran", 2);
    	cout << "Successfully added song: " << retCode << endl;

    //Adds song to playlist
    retCode = addSong("Mercy", "Shawn Mendez", 3);
	cout << "Successfully added song: " << retCode << endl;

    //Adds song to playlist
    retCode = addSong("Blue Ain't Your Color", "Keith Urban", 1);
	cout << "Successfully added song: " << retCode << endl;
    
    //Adds song to playlist
    retCode = addSong("Paris", "Chainsmokers", 5);
	cout << "Successfully added song: " << retCode << endl;

    //Adds song to playl;ist
    retCode = addSong("Mattress", "Front Bottoms", 6);
	cout << "Successfully added song: " << retCode << endl;

    //Unsuccessful song addition - lack of memory
    retCode = addSong("Earned it", "The Weeknd", 22);
	cout << "Unsuccessful song addition - lack of memory: " << retCode << endl;

    //Adds song to playlist
    retCode = addSong("Dream On", "Aerosmith", 1);
    	cout << "Successfully added song: " << retCode << endl;

    //Adds song to playlist
    retCode = addSong("Caroline", "Amine", 1);
	cout << "Successfully added song: " << retCode << endl;
 
    //Unsuccessful song addition -  no empty slots
    retCode = addSong("Irresistible", "Fall Out Boys", 1);
	cout << "Unsuccessful song addition - no empty slots: " << retCode << endl;

    cout << endl << "Playlist with songs added" << endl;
    showSongList();
    cout << endl;

    // Following code tests tsuPod song removal functionality         
    //Successfully remove song
    retCode = removeSong("Dream On");
    cout << "Successfully remove song: " << retCode << endl;

    //Unsuccessfully remove song
    retCode = removeSong("Wrecking Ball");
    cout << "Unsuccessfully removed song - song not found: " << retCode << endl;
    
    //Show playlist minus the removed song
    cout << endl;
    cout << "Playlist with song removed" << endl;
    showSongList();
    cout << endl;

    // Following code tests tsuPod song shuffling functionality      
    shuffle();
    cout << "Shuffled playlist" << endl;
    showSongList();
    cout << endl;

    //Show a cleared playlist
    clearMemory();
    cout << endl << "Cleared Playlist" << endl;
    showSongList();
    
    //system("PAUSE");   
 
}
