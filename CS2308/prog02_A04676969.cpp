/****************************************
Name: Samantha Coyle
Date: February 14, 2017
Problem Number: 2
Hours spent solving the problem: 6
Instructor: Komogortsev, TSU
****************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;

//Prototypes
char *Token(char *line, int position, char *tokenReturnBuffer);
int FindLowest(int grade1, int grade2, int grade3,
		int grade4, int grade5, int grade6);
int Average(int grade1, int grade2, int grade3, int grade4,
		int grade5, int grade6, int lowestGrade);
int Errors(int grade1, int grade2, int grade3, int grade4,
		int grade5, int grade6);
//Create file objects
ifstream fin;
ofstream fout;

int main()
{
	//Declare variables
	const int SIZE = 256;
	char line[SIZE];
	int position = 0;
	char *first;
	char *last;
	int ID = 0;
	int grade1 = 0, grade2 = 0, grade3 = 0,
	    grade4 = 0, grade5 = 0, grade6 = -1;
	int lowestGrade = 0;
	int AverageGrade = 0;
	//char * isThereGrade6;

	//Open the files
	fin.open("student_input.dat");
	fout.open("student_results.dat");

	//Check that the files open properly
	if(fin.fail())
	{
		cout << "Input file did not open. Terminating program";
		cout << endl;
		return -1;
	}
	
	if(fout.fail())
	{
		cout << "Output file did not open. Terminating program";
		cout << endl;
		return -1;
	}

	//Read in data
	while (fin.getline(line, SIZE)) 
	{
		char *returnBuffer = new char[256];
		//Read in the data
		cout << "This is what I read in: " << line << endl;

		//Assign values to variables through calling Token function
		first = Token(line, 0, returnBuffer);
		last = Token(line, 1, returnBuffer);
		ID = atoi(Token(line, 2, returnBuffer));
		grade1 = atoi(Token(line, 3, returnBuffer));
		grade2 = atoi(Token(line, 4, returnBuffer));
		grade3 = atoi(Token(line, 5, returnBuffer));
		grade4 = atoi(Token(line, 6, returnBuffer));
		grade5 = atoi(Token(line, 7, returnBuffer));
		grade6 = atoi(Token(line, 8, returnBuffer));
		
		lowestGrade = FindLowest(grade1, grade2, grade3, grade4, grade5, grade6);	
		cout << "Lowest grade: " << lowestGrade << endl;

		AverageGrade = Average(grade1, grade2, grade3, grade4, grade5, grade6, lowestGrade);
		cout << "average: " << AverageGrade << endl;

		Errors(grade1, grade2, grade3, grade4, grade5, grade6);

	}

	//Close the files
	fin.close();
	fout.close();

	return 0;
}

/***********************************************
Function 1: Create tokenizer to split up string
***********************************************/
char *Token(char *line, int position, char *tokenReturnBuffer)
{
	char delimiter = ' ';
	char delimiter2 = '\t';
	char *iterator = line;
	int count = 0;
	int letterCount = 0;
	do 
	{
		if ((*iterator == delimiter) || (*iterator == delimiter2))
			count++;

		while ((*iterator == delimiter) || (*iterator == delimiter2))
			iterator++;
		

	} while ((*iterator++) && (count != position));
	iterator--;
	//we're pointing to the first char of the word we want.
	//Make new iterator. While not delimiter, iterator2 ++, once == to delimiter *iterator2 = '\0'
	char *iterator2 = iterator;

	while ((*iterator2 != delimiter) && (*iterator2 != delimiter2)) 
	{
		tokenReturnBuffer[letterCount++] = *iterator2;
		iterator2++;
	}

	tokenReturnBuffer[letterCount] = '\0';
	return tokenReturnBuffer;
}

/**********************************************
Function 2: If there are 6 grades, drop lowest.
**********************************************/
int FindLowest(int grade1, int grade2, int grade3,
		int grade4, int grade5, int grade6)
{
	int lowest = grade1;

	if(grade6)
	{
		if(grade2 < lowest)
			lowest = grade2;
		else if(grade3 < lowest)
			lowest = grade3;
		else if(grade4 < lowest)
			lowest = grade4;
		else if(grade5 < lowest)
			lowest = grade5;
		else if(grade6 < lowest)
			lowest = grade6;
	}

	if(!grade6)
		lowest = 0;
	
	return lowest;

}

/*******************************************
Function 3: Find average grade
*******************************************/
int Average(int grade1, int grade2, int grade3, int grade4
		,int grade5, int grade6, int lowestGrade)
{
	int average = 0;
	int total = 0;
	total = grade1 + grade2 + grade3 + grade4 + grade5 + grade6;
	
	if(grade6 != 0)
		average = total/6;
	else
		average = total/5;
	return average;
}

/********************************************
Function 4: Provide error message if:
		1. There is a negative grade
		2. There are less than 6 grades
********************************************/
int Error(int grade1, int grade2, int grade3, int grade4,
		int grade5, int grade6)
{
	if(grade6 = 0)
	{
		cout << "Error: There are less than 6 grades.";
		cout << "Terminating program." << endl;
		return -1;
	}

	if(grade1 < 0)
		cout << "Error: Negative grade/n";
	if(grade2 < 0)
		cout << "Error: Negative grade/n";
	if(grade3 < 0)
		cout << "Error: Negative grade/n";
	if(grade4 < 0)
		cout << "Error: Negative grade/n";
	if(grade5 < 0)
		cout << "Error: Negative grade/n";
	if(grade6 < 0)
		cout << "Error: Negative grade/n";

	return 0;
}
