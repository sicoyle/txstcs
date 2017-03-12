/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 4
Hours spent solving the problem: 
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
    
    // Following code lists all songs located in tsuPod memeory 
    showSongList(/*add nessesary parameters here*/);
    cout << endl;

    // Following code tests tsuPod input functionality 
    int retCode = addSong("Runaway1", "Bon Jovi1", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway2", "Bon Jovi2", 2);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway3", "Bon Jovi3", 3);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway4", "Bon Jovi4", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway5", "Bon Jovi5", 5);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway6", "Bon Jovi6", 6);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway7", "Bon Jovi7", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway8", "Bon Jovi8", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway8", "Bon Jovi8", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway8", "Bon Jovi8", 1);
    retCode = addSong(/*add nessesary parameters here*/ "Runaway8", "Bon Jovi8", 1);
    cout << retCode << endl;   
    showSongList();
    cout << endl;

    // Following code tests tsuPod song removal functionality         
    retCode = removeSong("Runaway100");
    cout << retCode << endl;    
    showSongList();
    cout << endl;

    // Following code tests tsuPod song shuffling functionality      
    shuffle();
    cout << endl;
    showSongList();
    cout << endl;
    
    //system("PAUSE");    
}
