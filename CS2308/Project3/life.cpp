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

#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS = 0;         //stores the number of rows in the grid
int COLUMNS = 0;      //stores the number of rows in the grid

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void populateWorld (const char * file)
{
ifstream fin;
fin.open("glider_gun_fight.txt");
	while(!eof())
	{
		ROWS++;
		while(fin.get(arr))
		{	COLUMNS++;
			for(int r = 0; r < ROW; r++)
				arr[r] = new int[COLUMN];
		}
	}
}

//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{

}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{

}

