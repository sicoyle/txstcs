/****************************************************
Name: Samantha Coyle
Date: 2/28/2017
Problem Number: 3
Hours spent solving problem: 3
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
		COLUMNS++;
		if(ch == '\n')
			ROWS++;
	}

	//Get the correct column value
	COLUMNS = COLUMNS/ROWS;
	fin.close();
}

int Count(int j, int k, char ** arr)
{
	//Declare variables
	int counter = 0;

	//Get neighbor counts for each cell
	for(int m = j - 1; m <= j + 1; m++)
	{
		for(int n = k - 1; n <= k + 1; n++)
		{
			//Incremement count if cell is alive
			counter += atoi(arr[m][n]);
		}
			//Subtract value of cell from NC
			counter -= atoi(arr[j][k]);	
		
	}
	//Return neighbor count
	return counter;
}

void countNeighbors(char ** arr)
{
	//Create variable to hold the # of neighbors a cell has
	char ** NC;

	//Allocate memory for neighbor counts
	NC = new char * [ROWS + 2];
	for(int r = 0; r < (ROWS); r++)
		NC[r] = new char [COLUMNS + 2];

	//Assign number of neighbors to NC
	for(int j = 0; j < ROWS; j++)
	{
		for(int k = 0; k < COLUMNS; k++)
		{
			NC[j][k] = Count(j,k,arr);
		}
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
	arr = new char * [ROWS]; 

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";

	//Allocate memory for grid
	for(int r = 0; r < ROWS; r++)
	{
		arr[r] = new char [COLUMNS];
		//cout << arr[r];
	}

	//Read in the grid values
	for(int row = 0; row < ROWS; row++)
	{
		for(int columns = 0; columns < COLUMNS; columns++)
		{
			fin.get(ch); //Read in characters

			//If value is a 0 or 1, put into array
			if(ch == 48 || ch-1 == 48)	
				*(* (arr + row) + columns) = ch;
		}
	}
	
	//countNeighbors(arr);	
	
	fin.close(); //Close the files
}

//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
	//Print out the world to console
	for(int a = 0; a < ROWS; a++)
	{ 
		for(int b = 0; b < COLUMNS; b++)
		{			
			cout << *(* (arr + a) + b);
		}
		cout << endl;
	}
	countNeighbors(arr);
}
//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{
	cout << "Iterate gen function. " << endl;

}

