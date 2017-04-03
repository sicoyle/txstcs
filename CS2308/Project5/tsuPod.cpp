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
offsets = new int[songCount+2];

for(int i = 0; i < songCount+2; i++)
*(offsets+i) = 0;

offsets++;

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
if(pos > songs-1) 
return 0;
if(*(offsets+pos)+d < 0) 
d *= -1;
*(offsets+(pos)) += d;
updateOffsets(pos+1, d);
}
int TsuPod::sizeOf(int p) {
return (getOffset(p) - getOffset(p-1));
}
int TsuPod::getOffset(int p) {
return *(offsets + p);
}

int TsuPod::insertSong(Song s, int pos){
char title[s.getTitle().size() + 1];
strcpy(title,s.getTitle().c_str());
char artist[s.getArtist().size() + 1];
strcpy(artist,s.getArtist().c_str());
int size = s.getSize();
int insertPoint = getOffset(pos-1);
	myio.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
	//Assign data to song object
	int d = s.blobSize() - sizeOf(pos);
	int fileSize = getOffset(csongs-2);
//cout << "size of file currently copying into mem: " << getOffset(csongs-2) << endl;
	void * tmpbuf = malloc(fileSize);
	myio.read((char *)tmpbuf, fileSize);
	myio.close();
//cout << "copied " << fileSize << " bytes from tsupod_mem.dat" << endl;
//cout << "writing up to byte " << getOffset(pos) << endl;
	myio.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
cout << "INSERT POINT: " << insertPoint << endl;
//if(insertPoint)
cout << "w[0:" << insertPoint << "] \t\t preinsert old file contents." << endl;
	myio.write((char *) tmpbuf, insertPoint);
	long p = myio.tellp();
	cout << "w[" << p; 
	myio.write(reinterpret_cast<char *>(title), s.getTitle().size() + 1);
	myio.write(reinterpret_cast<char *>(artist), s.getArtist().size() + 1);
	myio.write(reinterpret_cast<char *>(&size), sizeof(int));
p = myio.tellp();
cout << ":" << p << "] \t new song\nw[" << p << ":" << fileSize+s.blobSize() << "] \t post insert old file contents." << endl;
if(pos != csongs-2)
myio.write(reinterpret_cast<char *>(tmpbuf+insertPoint), fileSize-insertPoint);
for(int i = csongs; i > pos; i--)
 *(offsets+i) = *(offsets+i-1);

updateOffsets(pos+1, s.blobSize());
cout << "latest offsets: ";
for(int i = 0; i < songs; i++)
cout << "\t[" << i << "]: " << *(offsets+i);
	cout << endl << "Cstring title " << title << " artist " << artist << " " << size << endl;

	//Close the file
	myio.close();
}

//Add desired song to playlist
int TsuPod::addSong(string T, string A, int S, int position)
{

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
	cout << "\n\nSong List: " << endl;
	
	for(int index = 0; index < csongs; index++)
	{
long pos = myio.tellg();
int textSize = sizeOf(index);
char text[textSize];
int  size = 0;
cout << "textSize == " << textSize;
cout << "r[" << pos << ":"; 
		myio.read(reinterpret_cast<char*>(text), textSize-4);
		myio.read(reinterpret_cast<char*>(&size), sizeof(int));
pos = myio.tellg();
cout << pos << "] :: " << endl;
char* artist = text;
while(*(++artist) != '\0');
artist++;

string t(text);
string a(artist);

Song s(t, a, size);
cout << "TsuPod::showList::Song(\"" << s.getTitle() << "\", \"" << s.getArtist() << "\", " << s.getSize() << ");" << endl;

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

