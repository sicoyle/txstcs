/****************************************************
Name: Samantha Coyle
Date: 2/28/2017
Problem Number: 3
Hours spent solving problem: 17 
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
cout << "SEARCHING FOR NEIGHBORS FOR COORD [" << j << ", " << k << "]:" << endl;
	//Declare variables
	int counter = 0;
	
	//Get neighbor counts for each cell
	for(int m = j - 1; m <= j + 1; m++)
	{
		for(int n = k - 1; n <= k + 1; n++)
		{
			//Incremement count if cell is alive
			if( *(* (arr + m) + n) == 49){
				counter += 1;
				cout << "\tneighbor found! [" << n << ", " << m << "]" << endl;
				}
		}
	}
		//Subtract value of cell from NC
//		if( *(* (arr + j) + k) == 49)
//			counter = counter - 1;
	
	//Return neighbor count
	return counter;
}

void countNeighbors()
{
	cout << "NC:" << endl;
	//Assign number of neighbors to NC
	for(int j = 1; j < (ROWS+1); j++)
	{
		for(int k = 1; k < (COLUMNS+1); k++)
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
	arr = new char * [ROWS+2]; 

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";

	//Allocate memory for world grid
	for(int r = 0; r < (ROWS+2); r++)
		arr[r] = new char [COLUMNS+2];

	//Initialize all values of world grid to 0
	for(int R = 0; R < (ROWS+2); R++)
		for(int C = 0; C < (COLUMNS+2); C++)
			*(* (arr + R) + C) = 48;

	//Allocate memory for neighbor count
	NC = new int * [ROWS + 2];	
	for(int index = 0; index < (ROWS + 2); index++)
		NC[index] = new int [COLUMNS + 2];

	//Initialize NC to zeros
	for(int u = 0; u < (ROWS + 2); u++)
		for(int v = 0; v < (COLUMNS + 2); v++)
			*(* (NC + u) + v) = 0;

	//Read in the world grid values
	for(int row = 0; row < (ROWS); row++)
	{
		for(int columns = 0; columns < (COLUMNS); columns++)
		{
			fin.get(ch); //Read in characters

			//If value is a 0 or 1, put into array
			if(ch == 48 || ch-1 == 48)	
				*(* (arr + row) + columns) = ch;
		}
		fin.ignore();
	}
	countNeighbors();
	fin.close(); //Close the files
}

//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
	cout << "Original world: " << endl;
	//Print out the world to console
	for(int a = 0; a < (ROWS); a++)
	{ 
		for(int b = 0; b < (COLUMNS); b++)
		{			
			cout << *(* (arr + a) + b);
		}
		cout << endl;
	}
}

char * getRow(int r, char ** world)
{
	return * (world + r);
}

void removeRow(int r, char ** world)
{
	delete getRow(r, world);
//	ROWS--;
	if(r == 0)
		world++;
}

int rowIsZero(int rowNum, char ** world)
{
	char * ptr = getRow(rowNum, world);
	for(int index = 0; index < COLUMNS; index++)
	{
		if( *(ptr + index) == 49)
			return 1;
	}
	return 0;
}

void Borders(char** world)
{
	if(rowIsZero(0, world))
	{	
		removeRow(0, world);
	}
}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void outputNextGen(char ** world)
{
	Borders(world);

	cout << "Here is next generation: at addr" << world << endl;
	for(int d = 0; d < (ROWS); d++)
	{
		for(int e = 0; e < (COLUMNS); e++)
		{
//			cout << *(* (nextGen + d) + e);
		}
		cout << endl;
	}
}

void iterateGeneration ()
{

	countNeighbors();

	//Create and allocate memory for next generation
	char ** nextGen = new char * [ROWS];
	for(int x = 0; x < (ROWS); x++)
		nextGen[x] = new char [COLUMNS];
//allocate
	for(int y = 0; y < (ROWS); y++)
		for(int z = 0; z < (COLUMNS); z++)
			*(* (nextGen + y) + z) = 48;


cout << "ded" << endl;
	//Initialize next generation to zero
cout << "ded?" << endl;
	for(int ro = 0; ro < (ROWS); ro++)
	{
		for(int co = 0; co < (COLUMNS); co++)
		{
			//Rule One:
			//Alive if arr was dead with NC is 3
			if(*(* (arr + ro) + co) == 48 && *(* (NC + ro) + co) == 3)
				*(* (nextGen + ro) + co) = 49;
			
			//Rule Two:
			//Dead if NC is 4 or more
			if(*(* (arr + ro) + co) == 49 && *(* (NC + ro) + co) >= 4)
				*(* (nextGen + ro) + co) = 48;
			
			//Rule Three:
			//Dead if NC is one or fewer
			if(*(* (arr + ro) + co) == 49 && *(* (NC + ro) + co) < 2)
				*(* (nextGen + ro) + co) = 48;
			
			//Rule Four:
			//Alive if NC is 2 or more
			if((*(* (NC + ro) + co) == 2 ||
			    *(* (NC + ro) + co) == 3))
				*(* (nextGen + ro) + co) = 49;
		}
	}
	//outputNextGen(nextGen);	
for(int i = 0; i < ROWS; i++)
removeRow(i, arr);
delete arr;

arr = nextGen;
}

