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
	fin.open("glider_gun_fight.txt");

	//Rest of variables
	int ** arr;
	//arr = new int * [ROWS];
	//char ch = new int [COLUMNS];
	char ch;
	vector < vector<char> > gameBoard; //For reading in the gameboard info	

	//Make sure file opens
	if(fin.fail())
		cout << "Error: input file did not open. ";
		
	//Read in input for each row of data
	while(fin.get(ch))
	{
		if(atoi(ch) == 0 || atoi(ch) == 1)
			gameBoard[ROWS];

		if(ch == '\n')
//This line needs fixing			gameBoard.push_back(vector <char>);
		}
		gameBoard.push_back(temp);
		ROWS++;
	}
		COLUMNS++;
}
//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{
	cout << "In showworld function\n";
}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{
	cout << "In iterategeneration function\n";
}

