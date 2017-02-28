/****************************************************
Name: Samantha Coyle
Date: 2/28/2017
Problem Number: 3
Hours spent solving problem: 9 
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
char ** arr;      //Stores the grid values
int ** NC;        //Create variable to hold the # of neighbors a cell has

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void gridSize(const char * file)
{
	//Create file object, declare variables
	ifstream fin(file);
	char ch;

	if(fin.fail())
		cout << "Error: input file did not open first try." << endl;
	
	//Read in the grid size
	while(fin.get(ch))
	{
		if(ch == 48 || ch-1 == 48)
			COLUMNS++;
		if(ch == '\n')
			ROWS++;
	}

	//Get the correct column value
	COLUMNS = COLUMNS/ROWS;
	fin.close();
	cout << "rows: " << ROWS << "	columns: " << COLUMNS << endl;
}

int Count(int j, int k)
{
	//Declare variables
	int counter = 0;
	
	//Get neighbor counts for each cell
	for(int m = j - 1; m <= j + 1; m++)
	{
		for(int n = k - 1; n <= k + 1; n++)
		{
			//Incremement count if cell is alive
			if( *(* (arr + m) + n) == 49)
				counter += 1;
		}
	}
		//Subtract value of cell from NC
		if( *(* (arr + j) + k) == 49)
			counter = counter - 1;
	
	//Return neighbor count
	return counter;
}

void countNeighbors()
{
	cout << "NC:" << endl;
	//Assign number of neighbors to NC
	for(int j = 1; j < (ROWS + 1); j++)
	{
		for(int k = 1; k < (COLUMNS + 1); k++)
		{
			//Get actual neighbor count
			*(* (NC + j) + k) = Count(j, k); 

			//Print out NC
			cout << *(* (NC + j) + k);
		}
		cout << endl;
	}
}

void populateWorld (const char * file)
{
	//Initialize variables
	ROWS = 0;
	COLUMNS = 0;
	ifstream fin; //Create file object

	//Call function to get grid size	
	gridSize(file);

	//Open file
	fin.open(file);

	//Rest of variables
	char ch;
	arr = new char * [ROWS + 2]; 

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";

	//Allocate memory for world grid
	for(int r = 0; r < (ROWS + 2); r++)
		arr[r] = new char [COLUMNS + 2];

	//Initialize all values of world grid to 0
	for(int R = 0; R < (ROWS + 2); R++)
		for(int C = 0; C < (COLUMNS + 2); C++)
			*(* (arr + R) + C) = 0;

	//Allocate memory for neighbor count
	NC = new int * [ROWS + 2];	
	for(int index = 0; index < (ROWS + 2); index++)
		NC[index] = new int [COLUMNS + 2];

	//Initialize NC to zeros
	for(int u = 0; u < (ROWS + 2); u++)
		for(int v = 0; v < (COLUMNS + 2); v++)
			*(* (NC + u) + v) = 0;

	//Read in the world grid values
	for(int row = 1; row < (ROWS + 1); row++)
	{
		for(int columns = 1; columns < (COLUMNS + 1); columns++)
		{
			fin.get(ch); //Read in characters

			//If value is a 0 or 1, put into array
			if(ch == 48 || ch-1 == 48)	
				*(* (arr + row) + columns) = ch;
		}
		fin.ignore();
	}
	
	fin.close(); //Close the files
}

//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
	cout << "Original world: " << endl;
	//Print out the world to console
	for(int a = 1; a < (ROWS + 2); a++)
	{ 
		for(int b = 1; b < (COLUMNS + 2); b++)
		{			
			cout << *(* (arr + a) + b);
		}
		cout << endl;
	}
	countNeighbors();
}

void removeExcess(int ** nextGen)
{
	for(int r = 0; r < (ROWS + 2); r++)
	{
		for(int c = 0; c < (COLUMNS + 2); c++)
		{
			if(*(nextGen + r) == 0)
			{//cout << "Here " << *(nextGen + r) << endl;
			
			}

		}
	}
}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void outputNextGen(int ** nextGen)
{
	removeExcess(nextGen);

	cout << "Here is next generation:" << endl;
	for(int d = 0; d < (ROWS + 2); d++)
	{
		for(int e = 0; e < (COLUMNS + 2); e++)
		{
			cout << *(* (nextGen + d) + e);
		}
		cout << endl;
	}
}

void iterateGeneration ()
{
	//Create and allocate memory for next generation
	int ** nextGen;
	nextGen = new int * [ROWS + 2];
	for(int x = 0; x < (ROWS + 2); x++)
		nextGen[x] = new int [COLUMNS + 2];

	//Initialize next generation to zero
	for(int y = 0; y < (ROWS + 2); y++)
		for(int z = 0; z < (COLUMNS + 2); z++)
			*(* (nextGen + y) + z) = 0;

	for(int ro = 1; ro < (ROWS + 1); ro++)
	{
		for(int co = 1; co < (COLUMNS + 1); co++)
		{
			//Rule One:
			//Alive if arr was dead with NC is 3
			if(*(* (arr + ro) + co) == 48 && *(* (NC + ro) + co) == 3)
				*(* (nextGen + ro) + co) = 1;
			
			//Rule Two:
			//Dead if NC is 4 or more
			if(*(* (arr + ro) + co) == 49 && *(* (NC + ro) + co) >= 4)
				*(* (nextGen + ro) + co) = 0;
			
			//Rule Three:
			//Dead if NC is one or fewer
			if(*(* (arr + ro) + co) == 49 && *(* (NC + ro) + co) < 2)
				*(* (nextGen + ro) + co) = 0;
			
			//Rule Four:
			//Alive if NC is 2 or more
			if((*(* (arr + ro) + co) == 49) && (*(* (NC + ro) + co) == 2 ||
			    *(* (NC + ro) + co) == 3))
				*(* (nextGen + ro) + co) = 1;
		}
	}
	outputNextGen(nextGen);	
}

