/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include "Song.h"

using namespace std;

class TsuPod
{
	private:
		struct songNode
		{
			Song s;			//Song object
			songNode * next;	//Ptr for next node
		};
		songNode * head;
		
		//tsuPod resources: songs and memory, and consumed songs/memory
		int totMem, cmem, songs, csongs;

	public:
		//Constructor and deconstructor
		TsuPod(int);
		~TsuPod();

		int checkAddSong(Song);
		int addSong(Song);
		int removeSong(Song);
		void showList();
		void sortList();
		void shuffle();
		void clearList();
		int getTotalMem();
		int getRemainingMem();

		//DELETE!!!
		Song searchLeast();
		bool remove(Song);
};
