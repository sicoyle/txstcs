/****************************************************
Name: Samantha Coyle
Date: 3/1/2017
Problem Number: 3
CS2308
Hours worked on project: 20
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.

#include <iostream>
#include <fstream>
#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of rows in the grid
char ** world;	  //store values of world
int ** NC;	  //store value of neighbor counts for world

//This function reads input file for subsequent prosessing
void getGrid(const char * file)
{
	ifstream fin;
	fin.open(file);
	char ch;

	//Check file opens
	if(fin.fail())
		cout << "Error 1: file did not open." << endl;

	//Read in grid
	while(fin.get(ch))
	{
		if(ch == 48 || ch-1 == 48)
			COLUMNS++;
		if(ch == '\n')
			ROWS++;
	}
	
	//Get actual column number
	COLUMNS = COLUMNS/ROWS;
	cout << "ROWS: " << ROWS << " COLUMNS: " << COLUMNS << endl;
	
	//Close file
	fin.close();
}

//Get the count per organism of neighbors
int Count(int ro, int co)
{
	//initialize neighbor count
	int count = 0;	

	//Upper left diagonal neighbor
	if( *(* (world + (ro - 1)) + (co - 1)) == 49)
		count++;

	//Left neighbor
	if( *(* (world + ro) + (co - 1)) == 49)
		count++;
	
	//Bottom left diagonal neighbor
	if( *(* (world + (ro + 1)) + (co - 1)) == 49)
		count++;
	
	//Neighbor beneath
	if( *(* (world + (ro + 1)) + co) == 49)
		count++;

	//Bottom right diagonal neighbor
	if( *(* (world + (ro + 1)) + (co + 1)) == 49)
		count++;

	//Right neighbor
	if( *(* (world + ro) + (co + 1)) == 49)
		count++;

	//Right upper diagonal neighbor
	if( *(* (world + (ro - 1)) + (co + 1)) == 49)
		count++;

	//Neighbor above
	if( *(* (world + (ro - 1)) + co) == 49)
		count++;

	//return total neighbor count
	return count;
}

//Get neighbor count filled with data
void countNeighbors()
{
	cout << "Neighbor Count" << endl;
	
	//For every row and column with an organism, count neighbors
	for(int r = 1; r < (ROWS + 1); r++)
	{
		for(int c = 1; c < (COLUMNS + 1); c++)
		{
			//get neighbor count
			*(* (NC + r) + c) = Count(r,c);

			cout << *(* (NC + r) + c);
		}
		cout << endl;
	}
	
}

//Populate the world with data on live/dead cells
void populateWorld (const char * file)
{
	//Initialize variables
	ROWS = 0;
	COLUMNS = 0;
	char ch;
	ifstream fin;//make file object

	//Read in grid
	getGrid(file);

	//Open file
	fin.open(file);

	//If file doesn't open give error
	if(fin.fail())
		cout << "Error 2: file did not open." << endl;


	//Make memory for my world
	world = new char * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		world[row] = new char [COLUMNS + 2];

	//Initialize memory for my world
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (world + row) + col) = 48;

	//Make memory for NC
	NC = new int * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		NC[row] = new int [COLUMNS + 2];

	//Initialize NC to zero
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (world + row) + col) = 0;

	//Read in world values
	for(int row = 1; row < ROWS + 1; row++)
	{
		for(int col = 1; col < COLUMNS + 1; col++)
		{
			fin.get(ch);
			
			//If 1 or 0 read in value
			if(ch == 48 || ch-1 == 48)
				*(* (world + row) + col) = ch;
		}
		fin.ignore();
	}
	fin.close();
}

//This function outputs the grid for current generation 
void showWorld ()
{
	cout << "World: " << endl;

	//show content for every row and column
	//keep in mind buffer of zeros around world
	for(int r = 1; r < ROWS + 1; r++)
	{
		for(int c = 1; c < COLUMNS + 1; c++)
		{
			cout << *(* (world + r) + c);
		}
		cout << endl;
	}
	
}

//This function creats new geneneration grid from the old generation grid
void iterateGeneration ()
{
	//Count neighbors
	countNeighbors();
	
	//Create and allocate memory for next generation
	char ** nextGen;
	nextGen = new char * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		nextGen[row] = new char [COLUMNS + 2];
	
	//Initialize next generation
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (nextGen + row) + col) = 48;

	//Check if next generation organism becomes alive/dead
	for(int row = 1; row < ROWS + 1; row++)
	{
		for(int col = 1; col < COLUMNS + 1; col++)
		{
			//Rule one: alive if world was dead with NC is 3
			if( (*(* (world + row) + col) == 48) && 
					(*(* (NC + row) + col) == 3))
				*(* (nextGen + row) + col) = 49;

			//Rule two: dead if NC is 4 or more
			if( (*(* (world + row) + col) == 49) && 
					(*(* (NC + row) + col) >= 4))
				*(* (nextGen + row) + col) = 48;
	
			//Rule three: dead if NC is one or fewer
			if( (*(* (world + row) + col) == 49) && 
					(*(* (NC + row) + col) < 2))
				*(* (nextGen + row) + col) = 48;

			//Rule four: alive if NC is 2 or more
			if( (*(* (world + row) + col) == 49) &&	
					(*(* (NC + row) + col) == 2) || 
					(*(* (NC + row) + col) == 3))
				*(* (nextGen + row) + col) = 49;
		
		}
	}

	//Output next generation world
	cout << "Next Generation" << endl;
	for(int row = 1; row < ROWS + 1; row++)
	{
		for(int col = 1; col < COLUMNS + 1; col++)
		{
			cout << *(* (nextGen + row) + col);
		}
		cout << endl;
	}
	
	//Clear memory for next iteration
	delete world;
	world = nextGen;
}		

