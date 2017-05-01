/****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 32
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

//File object
fstream myio;

//Constructor with parameters
TsuPod::TsuPod (int mem, int songCount)
{
  cout << "NEW TSUPOD: " << endl;
  memory = mem;
  cmem = csongs = 0;
  songs = songCount;
  offsets = new int[songCount];
  cout << "addr(offsets): " << offsets << endl;
  for (int i = 0; i < songCount; i++)
    *(offsets + i) = 0;

srand(0);
}

//Initialize the tsuPod
int TsuPod::initialize ()
{
  	//Create object
  	Song s;

  	//Open file in binary mode
  	myio.open ("tsupod_memory.dat",ios::binary | ios::out | ios::in | ios::app);

  	//Check that file opens
  	if (myio.fail ())
    	{
      		cout << "Error: file did not open." << endl;
      		return -1;
    	}

  	//Close the file
  	myio.close ();

  	return 0;
}

//Return a song
Song TsuPod::getSong(int pos)
{                                                                                                                                                                                                                                                                                                  
	myio.open("tsupod_memory.dat", fstream::binary | fstream::in);                                                                                                          
        int blobSize = sizeOf(pos);                                                                                                                                             
	char blob[blobSize];                                                                                                                                                    
	int size = 0;                                                                                                                                                           
                                                                                                                                                                        
	myio.seekg(getsOffset(pos), myio.beg);                                                                                                                                  
                                                                                                                                                                        
	myio.read(reinterpret_cast<char *>(blob), blobSize - 4);                                                                                                                
	myio.read(reinterpret_cast<char *>(&size), sizeof(int));                                                                                                                
                                                                                                                                                                        
	char *artist = blob;                                                                                                                                                    
        while (*(++artist) != '\0');                                                                                                                            
	        artist++;                                                                                                                                       
                                                                                                                                                                        
        //Title, artist variables                                                                                                                               
        string t (blob);                                                                                                                                        
        string a (artist);                                                                                                                                      
                                                                                                                                                                        
        //Pass data to object                                                                                                                                   
        Song s (t, a, size);                                                                                                                                    
        cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.getArtist () << "\", " << s.getSize () << ");" << endl;                           
        myio.close();                                                                                                                                                           
	return s;                                                                                                                                                               
}       

//Update the off sets                                                                                                                                                                
void TsuPod::updateOffsets (int pos, int d)
{
	cout << "updating offsets:\t pos:" << pos << " d:" << d << endl;
	cout << "\tcurr val: " << *(offsets+pos) << " - > new val: " << *(offsets+pos)+d << endl;
  	//*(offsets + (pos)) += d;
	d += *(offsets + (pos));

	if(++pos < csongs + 1)
  		updateOffsets(pos, d);
}

//Get a random song number to help with shuffling
int TsuPod::getRandomSongNumber()
{
	return rand() % csongs;
}

//Return the size of position
int TsuPod::sizeOf (int p)
{
	if(p<=0)
		return *(offsets);
  	return (offsets[p] - offsets[p - 1]);
}

//Get the offset value for position
int TsuPod::getsOffset (int p)
{
	if(!p)
		return 0;
  	return *(offsets + p - 1);
}

//Show me off set values
void TsuPod::printOffsets()
{
	cout << "current song #: " << csongs << endl;
	cout << "*(offsets+i):"<<endl;

	for(int i = 0; i < songs; i++)
		cout << "[" << i << " :: " << *(offsets+i) << "]" << endl;

	cout<< "getsOffset(i):" <<endl;

	for(int i = 0; i < songs; i++)
		cout << "[" << i << " :: " << getsOffset(i) << endl;

	cout<< "sizeOf(i):"<<endl;

	for(int i = 0; i < songs; i++)
		cout << "[" << i << " :: " << sizeOf(i) << endl;
}

//Insert the actual song
int TsuPod::insertSong (Song s, int pos)
{
	//Create char array to allow deep copy of string
  	char title[s.getTitle ().size () + 1];
  	strcpy (title, s.getTitle ().c_str ());
  	char artist[s.getArtist ().size () + 1];
  	strcpy (artist, s.getArtist ().c_str ());

	//Other variables to help with correct location
  	int size = s.getSize();
  	int insertPoint = getsOffset(pos);
  	bool lastSong = (pos == csongs - 1);
  	int fileSize = getsOffset(csongs); //File size
  	void *tmpbuf = malloc(fileSize); //Temp variable to store file
  	
	cout << "lastSong == " << lastSong << endl;
  	
	//Open file in binary
	myio.open ("tsupod_memory.dat",fstream::binary | fstream::out | fstream::in);
	
	cout << "consumed songs at insersetion: " << csongs << endl;
  	cout << "size of file currently copying into mem: " << getsOffset(csongs) <<
  	endl;

	//Read in to tmpbuf the file and close file
  	myio.read ((char *) tmpbuf, fileSize);
  	myio.close ();

	//Show how many bytes were copied
  	cout << "copied " << fileSize << " bytes from tsupod_mem.dat" << endl;
  	cout << "writing up to byte " << getsOffset (pos) << endl;

	//Open file
  	myio.open ("tsupod_memory.dat",fstream::binary | fstream::out | fstream::in);
  	
	//Show where insert point is
	cout << "INSERT POINT: " << insertPoint << endl;
	cout << "blob size: " << s.blobSize() << endl;
	cout << "w[0:" << insertPoint << "] \t\t preinsert old file contents." <<
    	endl;

	//Write the file up to insertion point
  	myio.write ((char *) tmpbuf, insertPoint);

	//Variable to tell me where I am
  	long p = myio.tellp ();
  	cout << "w[" << p;
  	
	//Write title, artist, and sizee to file
	myio.write (reinterpret_cast < char *>(title), s.getTitle ().size () + 1);
  	myio.write (reinterpret_cast < char *>(artist), s.getArtist ().size () + 1);
  	myio.write (reinterpret_cast < char *>(&size), sizeof (int));

	//Check where I am at in file
  	p = myio.tellp ();
  	cout << ":" << p << "] \t new song\nw[" << p << ":" << fileSize +
    	s.blobSize () << "] \t post insert old file contents." << endl;

	//Write the rest of the file after song was added
    	myio.write (reinterpret_cast < char *>(tmpbuf) + insertPoint,
			 fileSize - insertPoint);
	
	cout << "writing end of file" << endl;
	cout << "PRESHUFFLE DOWN FOR INSERT:" << endl;
	printOffsets();
	cout << "sizeof(0): " << sizeOf(0);
	
	//Show me offsets for consumed songs
	if(csongs >=1)
  		for (int i = csongs; i >= pos; i--)
		{
			cout << "moving offsets:\t pos:[" << i << "]v:" << *(offsets+i) << endl;
			cout << "\tto pos:[" << i+1 << "]v:" << *(offsets+i+1) << endl;
			*(offsets+i+1) = *(offsets+i);
		}

	cout << "PREUPDATE:" << endl;
	
	if(pos == 0)
		*(offsets) = s.blobSize();
	
	//Update offsets
	else
		updateOffsets (pos, s.blobSize());
	cout << "postupdate!!!!:" << endl;
	printOffsets();

  	//Close the file
  	myio.close ();
}

//Return neg if error with trying to add song
int TsuPod::checkAddSong(string T, string A, int S, int cmem)
{
	//Check that size is a valid number. Must be > 0.
	if(S < 0 && S > ((getRemainingMem(cmem))))
	{
		cout << "Error: size must be greater than 0. Song not added." << endl;
		return -2;
	}

	//Error if too many songs
	if(csongs == songs)
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

	return 0;
}

//Add desired song to playlist
int TsuPod::addSong(string T, string A, int S, int position)
{
	//Check if song can be added
	if(checkAddSong(T,A,S,cmem) < 0)
		return -1;
	
	Song s(T, A, S);
	insertSong(s, position);

	//Add size of added song to mem total
	cmem += S;
	//If not errors, increment song total
	csongs++;

	return 0;
}

//Remove the song from playlist
int TsuPod::removeSong(Song s)
{
	//Update song count and mem
	csongs--;
	cmem -= s.getSize();

	TsuPod temp(100, (csongs));	
	
	for(int i = 0; i < csongs; i++)
	{
		if(!((getSong(i).getArtist() == s.getArtist()) && (getSong(i).getTitle() == s.getTitle()) && (getSong(i).getSize() == s.getSize())))
			insertSong(getSong(i), 0);
	}
	
	return 0;
}

//Clear the song list
int
TsuPod::clearList ()
{



}

//Sort the song list alphabetically
int
TsuPod::sortList ()
{


}

//Display the list to the console
void TsuPod::showList ()
{
  	Song s;
  	
	//Open file
	myio.open ("tsupod_memory.dat", fstream::binary | fstream::in);
  	cout << "\n\nSong List: " << endl;

  	for (int index = 0; index < csongs; index++)
    	{
		//Variables
      		long pos = myio.tellg ();
      		int textSize = sizeOf(index);	//Size for text
      		char text[textSize];	//Holds title and artist
      		int size = 0;	//Holds size of song

      		cout << "textSize == " << textSize;
      		cout << "r[" << pos << ":";

		//Read the data to be able to print out
      		myio.read (reinterpret_cast < char *>(text), textSize - 4);
      		myio.read (reinterpret_cast < char *>(&size), sizeof (int));

      		pos = myio.tellg ();
      		cout << pos << "] :: " << endl;

		//Assign artist
      		char *artist = text;
      		while (*(++artist) != '\0');
      			artist++;

		//Title, artist variables
      		string t (text);
      		string a (artist);

		//Pass data to object
      		Song s (t, a, size);
      		cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.
		getArtist () << "\", " << s.getSize () << ");" << endl;
    	}
	
	//Display remaining memory to console
	cout << "Total remaining memory: " << getRemainingMem(cmem) << endl;
	
	//Close file
	myio.close ();
}

//Display the total memory space left over
int TsuPod::getTotalMem()
{
  	return memory;
}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem(int cmem)
{
      return (getTotalMem() - cmem);
}
