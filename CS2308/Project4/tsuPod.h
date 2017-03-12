/****************************************************
Name: Samantha Coyle
Date: 3/12/2017
Problem Number: 4
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/
/*This header file provides the prototypes of the function definitions
for the tsuPod project. This file has to be included in the program that tests the functionality of tsuPod.

You have to create file tsuPod.cpp with function definitions for the test program to work.

*********************************/
#ifndef tsuPod_h
#define tsuPod_h

#include <string>

using namespace std;

void initTsuPod ();

///////////////////////////////
/* FUNCTION - int addSong
 * attempts to add a new song to the tsuPod
          o returns a 0 if successful
          o returns -1 if not enough memory to add the song
          o returns -2 for any other error (such as a blank title or artist)
 
 input parms - add nessesary parameters here
 
output parms - add nessesary parameters here
*/

int addSong (/*add nessesary parameters here*/ string newTitle, string newArtist, int size);

////////////////////////////
/* FUNCTION - int removeSong
    * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed
    
          
input parms - add nessesary parameters here
 
output parms - add nessesary parameters here
*/   

int removeSong (/*add nessesary parameters here*/ string title);

////////////////////////////
/* FUNCTION - void clearMemory
* clears all the songs from memory

input parms - add nessesary parameters here
 
output parms - /*add nessesary parameters here
*/
void clearMemory(/*add nessesary parameters here*/);

/////////////////////////////
/* FUNCTION - void showSongList   
    * prints the current list of songs in order from first to last to standard output
    * format - slot #, Title, Artist, size in MB (one song per line)
    * print "Empty" for any slots that do not contain a song

input parms - add nessesary parameters here
 
output parms - add nessesary parameters here
*/
    
void showSongList (/*add nessesary parameters here*/);

////////////////////////////
/* FUNCTION - void shuffle
    *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

input parms - add nessesary parameters here
 
output parms - add nessesary parameters here
*/

void shuffle (/*add nessesary parameters here*/);

#endif
