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
char ** arr;
//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void gridSize(const char * file)
{
	//Create file object, declare variables
	ifstream fin(file);
	char ch;
	
	//Read in the grid size
	while(fin.get(ch))
	{
		COLUMNS++;
		if(ch == '\n')
			ROWS++;
	}

	//Get the correct column value
	COLUMNS = COLUMNS/ROWS;
	fin.close();
}

void populateWorld (const char * file)
{
	//Initialize variables
	ROWS = 0;
	COLUMNS = 0;
	ifstream fin; //Create file object
	
	gridSize(file);
	//Open file
	fin.open(file);

	//Rest of variables
	char ch;

	arr = new char * [ROWS]; 

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";

	for(int r = 0; r < ROWS; r++)
	{
		arr[r] = new char [COLUMNS];
		cout << "arr "<< arr[r];
	}

	for(int row = 0; row < ROWS; row++)
	{
		for(int columns = 0; columns < COLUMNS; columns++)
		{
		fin.get(ch);
		if(ch == 48 || ch-1 == 48)		
			*(* (arr + row) + columns) = ch;
		}
	}

	fin.close();
}
//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
for(int r = 0; r < ROWS; r++)
{
	for(int c = 0; c < COLUMNS; c++)
		cout << *(*(arr+r)+c);
	cout << endl;
}



}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{
}

