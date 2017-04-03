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
#include <cstring>

#include <string>


using namespace std;

fstream myio;

//Constructor with parameters
TsuPod::TsuPod(int mem, int songCount)
{
	cout << "NEW TSUPOD: " << endl;
	memory = mem;
cmem = csongs = 0;
	songs = songCount;
offsets = new int[songCount];

for(int i = 0; i < songCount; i++)
*(offsets+i) = 0;

}

int TsuPod::initialize()
{
	//Create object
	Song s;

	//Open file in binary mode
	myio.open("tsupod_memory.dat", ios::binary | ios::out | ios::in | ios::app);
	
	//Check that file opens
	if(myio.fail())
	{
		cout << "Error: file did not open." << endl;
		return -1;
	}
	

	//Close the file
	myio.close();

	return 0;
}	
int TsuPod::updateOffsets(int pos, int d) {
*(offsets+pos) -= d;
if(pos < csongs-1)
updateOffsets(pos+1, d);
}
int TsuPod::sizeOf(int p) {
return (p < csongs) ? (getOffset(++p) - getOffset(--p)) : 0;
}
int TsuPod::getOffset(int p) {
return (p < csongs) ? *(offsets + p) : 0;
}

int TsuPod::insertSong(Song s, int pos){
char title[s.getTitle().size() + 1];
strcpy(title,s.getTitle().c_str());
char artist[s.getArtist().size() + 1];
strcpy(artist,s.getArtist().c_str());
int size = s.getSize();
int insertPoint = getOffset(pos);
	myio.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
	//Assign data to song object
	int d = s.blobSize() - sizeOf(pos);
	int fileSize = getOffset(csongs);
	void * tmpbuf = malloc(fileSize);
	myio.read((char *)tmpbuf, fileSize);
	myio.close();
cout << "copied " << fileSize << " bytes from tsupod_mem.dat" << endl;
cout << "writing up to byte " << getOffset(pos) << endl;
	myio.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
cout << "INSERT POINT: " << insertPoint << endl;
if(insertPoint)
	myio.write((char *) tmpbuf, insertPoint);
	long p = myio.tellp();
	cout << "inputting song in bytes addr [ " << p; 
	myio.write(reinterpret_cast<char *>(title), s.getTitle().size() + 1);
	myio.write(reinterpret_cast<char *>(artist), s.getArtist().size() + 1);
	myio.write(reinterpret_cast<char *>(&size), sizeof(int));
updateOffsets(pos, d);

p = myio.tellp();
cout << " -> " << p << "];" << endl;
	cout << endl << "Cstring title " << title << " artist " << artist << " " << size << endl;

	//Close the file
	myio.close();
}

//Add desired song to playlist
int TsuPod::addSong(string T, string A, int S, int position)
{

	cout << "tsupod::addsong():" << T << A << S << endl;
	//Check that size is a valid number. Must be > 0.
	if(S < 0 && S > (memory-cmem))
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

	//Add size of added song to mem total
	cmem += S;
	//If not errors, increment song total
	csongs++;

	//if(getRemainingMem() <= getTotalMem())
	
cout << "sizeof(Song) == " << sizeof(Song) << endl;

	
	Song s(T, A, S);
insertSong(s, position);
	return 0;
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
	Song s;	
int timeout = 100;
	myio.open("tsupod_memory.dat", fstream::binary | fstream::in);
	cout << "Song List: " << endl;
	
	for(int index = 0; index < csongs; index++)
	{
long pos = myio.tellg();
int textSize = sizeOf(index);
char text[textSize];
cout << "textSize: " << textSize << endl;
int  size = 0;
cout << "reading song from bytes addr [ " << pos << " -> "; 
		myio.read(reinterpret_cast<char*>(text), textSize-4);
		myio.read(reinterpret_cast<char*>(&size), sizeof(int));
char* artist = text;
while(*(++artist) != '\0' && timeout--);
artist++;

string t(text);
string a(artist);

Song s(t, a, size);
cout << "T: " << s.getTitle() << "; A = " << s.getArtist() << "; S = " << s.getSize() << endl;
cout << "wppt" << endl;

pos = myio.tellg();
cout << pos << " ];" << endl;
	}

	myio.close();
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
int TsuPod::getRemainingMem()
{
//	return memTotal;
}

