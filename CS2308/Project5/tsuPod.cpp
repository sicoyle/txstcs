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

}
int
TsuPod::initialize ()
{
  //Create object
  Song s;

  //Open file in binary mode
  myio.open ("tsupod_memory.dat",
	     ios::binary | ios::out | ios::in | ios::app);

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

void
TsuPod::updateOffsets (int pos, int d)
{
cout << "updating offsets:\t pos:" << pos << " d:" << d << endl;
cout << "\tcurr val: " << *(offsets+pos) << " - > new val: " << *(offsets+pos)+d << endl;
  *(offsets + (pos)) += d;
if(++pos < csongs+1)
  updateOffsets (pos, d);
}

int
TsuPod::sizeOf (int p)
{
if(p<=0)
return *(offsets);
  return (getsOffset (p+1) - getsOffset (p));
}

int
TsuPod::getsOffset (int p)
{
if(!p)
return 0;
  return *(offsets + p - 1);
}

void
TsuPod::printOffsets(){

cout << "current song #: " << csongs << endl;
cout << "*(offsets+i):"<<endl;
for(int i = 0; i < songs; i++)
printf("[%d :: %d]\n", i, *(offsets+i));

cout<< "getsOffset(i):" <<endl;
for(int i = 0; i < songs; i++)
printf("[%d :: %d]\n", i, getsOffset(i));

cout<< "sizeOf(i):"<<endl;
for(int i = 0; i < songs; i++)
printf("[%d :: %d]\n", i, sizeOf(i));
}
int
TsuPod::insertSong (Song s, int pos)
{
  char title[s.getTitle ().size () + 1];
  strcpy (title, s.getTitle ().c_str ());
  char artist[s.getArtist ().size () + 1];
  strcpy (artist, s.getArtist ().c_str ());
  int size = s.getSize ();
  int insertPoint = getsOffset (pos);

  bool lastSong = (pos == csongs - 1);
  cout << "lastSong == " << lastSong << endl;
  myio.open ("tsupod_memory.dat",
	     fstream::binary | fstream::out | fstream::in);
  //Assign data to song object
  cout << "consumed songs at insersetion: " << csongs << endl;
  int fileSize = getsOffset (csongs);
  cout << "size of file currently copying into mem: " << getsOffset (csongs) <<
    endl;
  void *tmpbuf = malloc (fileSize);
  myio.read ((char *) tmpbuf, fileSize);
  myio.close ();
  cout << "copied " << fileSize << " bytes from tsupod_mem.dat" << endl;
  cout << "writing up to byte " << getsOffset (pos) << endl;
  myio.open ("tsupod_memory.dat",
	     fstream::binary | fstream::out | fstream::in);
  cout << "INSERT POINT: " << insertPoint << endl;
cout << "blob size: " << s.blobSize() << endl;
//if(insertPoint)
  cout << "w[0:" << insertPoint << "] \t\t preinsert old file contents." <<
    endl;
  myio.write ((char *) tmpbuf, insertPoint);
  long p = myio.tellp ();
  cout << "w[" << p;
  myio.write (reinterpret_cast < char *>(title), s.getTitle ().size () + 1);
  myio.write (reinterpret_cast < char *>(artist), s.getArtist ().size () + 1);
  myio.write (reinterpret_cast < char *>(&size), sizeof (int));
  p = myio.tellp ();
  cout << ":" << p << "] \t new song\nw[" << p << ":" << fileSize +
    s.blobSize () << "] \t post insert old file contents." << endl;
  if (!lastSong){
    myio.write (reinterpret_cast < char *>(tmpbuf) + insertPoint,
		fileSize - insertPoint);
cout << "writing end of file" << endl;
}
cout << "PRESHUFFLE DOWN FOR INSERT:" << endl;
printOffsets();

//current pos update:

cout << "sizeof(0): " << sizeOf(0);
  for (int i = csongs; i >= pos; i--)
{
cout << "moving offsets:\t pos:[" << i << "]v:" << *(offsets+i) << endl;
cout << "\tto pos:[" << i+1 << "]v:" << *(offsets+i+1) << endl;
*(offsets+i+1) = *(offsets+i);
}
cout << "PREUPDATE:" << endl;
if(pos == 0)
*(offsets) = s.blobSize();
updateOffsets (pos+1, s.blobSize());
cout << "postupdate!!!!:" << endl;
printOffsets();
  //Close the file
  myio.close ();
}

//Add desired song to playlist
int
TsuPod::addSong (string T, string A, int S, int position)
{

  //Check that size is a valid number. Must be > 0.
  if (S < 0 && S > (memory - cmem))
    {
      cout << "Error: size must be greater than 0. Song not added." << endl;
      return -2;
    }

  //Error if too many songs
  if (csongs == songs)
    {
      cout << "Error: lack of space. Song not added." << endl;
      return -2;
    }

  //Error if blank entry
  if (T == " " || A == " ")
    {
      cout << "Error: title/artist can not be blank." << endl;
      return -2;
    }

  //Add size of added song to mem total
  cmem += S;
  //If not errors, increment song total


  //if(getRemainingMem() <= getTotalMem())



  Song s (T, A, S);
  insertSong (s, position);
  csongs++;
return 0;
}

//Remove desired song to playlist
int
TsuPod::removeSong (Song s)
{



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

//Dislay the list to the console
void
TsuPod::showList ()
{
  Song s;
  int timeout = 100;
  myio.open ("tsupod_memory.dat", fstream::binary | fstream::in);
  cout << "\n\nSong List: " << endl;

  for (int index = 0; index < csongs; index++)
    {
      long pos = myio.tellg ();
      int textSize = sizeOf (index);
      char text[textSize];
      int size = 0;
      cout << "textSize == " << textSize;
      cout << "r[" << pos << ":";
      myio.read (reinterpret_cast < char *>(text), textSize - 4);
      myio.read (reinterpret_cast < char *>(&size), sizeof (int));
      pos = myio.tellg ();
      cout << pos << "] :: " << endl;
      char *artist = text;
      while (*(++artist) != '\0');
      artist++;

      string t (text);
      string a (artist);

      Song s (t, a, size);
      cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.
	getArtist () << "\", " << s.getSize () << ");" << endl;

    }

  myio.close ();
}

//Display the total memory space left over
int
TsuPod::getTotalMem ()
{
  return memory;
}

//Shuffle the song list into a different order
int
TsuPod::shuffle ()
{

}

//Get the remaining memory space left over
int
TsuPod::getRemainingMem ()
{
//      return memTotal;
}
