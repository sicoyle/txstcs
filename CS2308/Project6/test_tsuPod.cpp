/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{
	//instantiate myPod
	TsuPod myPod(256);

	int retCode = -1;

	Song mySong1("Hello", "Adele", 1);
        retCode = myPod.addSong(mySong1);
		cout << "Add song return code: " << retCode << endl;

	Song mySong2("Castle on the Hill", "Ed Sheeran",2);
	retCode = myPod.addSong(mySong2);
		cout << "Add song return code: " << retCode << endl;


	myPod.showList();

/*
	myPod.addSong("Paris", "Chain Smokers", 3);
	myPod.addSong("Issues", "Julia Michaels", 4);
	myPod.addSong("Starboy", "The Weeknd", 5);
*/
}
