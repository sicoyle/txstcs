/****************************************************
Name: Samantha Coyle
Date: 2/28/2017
Problem Number: 3
CS2308
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.


#include <iostream>
#include <fstream>
#include <cstdio>
#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of rows in the grid

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void populateWorld (const char * file)
{
	//Initialize variables
	ROWS = 0;
	COLUMNS = 0;
	ifstream fin; //Create file object
	
	//Open file
	fin.open(file);

	//Rest of variables
	int ** arr;
	char ch;

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";
cout << "HERE" << endl;		
	//Read in input for each row of data
	while(fin.get(ch))
	{
cout << "here";
		COLUMNS++;
		if(ch == '\n')
			ROWS++;
	}
	COLUMNS = COLUMNS/ROWS;

}
//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
	cout << "In showworld function\n";
cout << ROWS << endl << COLUMNS;
}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{
	cout << "In iterategeneration function\n";
}

