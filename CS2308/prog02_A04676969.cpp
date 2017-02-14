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
int FindLowest(int grade[], const int NumGrades);
double Average(int grade[], int lowestGrade, const int NumGrades);
//int Errors(int grade[], const int NumGrades);
char CalculateLetterGrade(double AverageGrade);
void OutputStudentData(int grade[], const int NumGrades, char * first,
		char * last, int ID, double AverageGrade, char letterGrade);
void OutputGradeTotals(char letterGrade);

//Create file objects
ifstream fin;
ofstream fout;

int main()
{
	//Declare variables
	const int SIZE = 256;
	const int NumGrades = 6;
	char line[SIZE];
	int position = 0;
	char *first;
	char *last;
	int ID = 0;
	int grade[NumGrades];
	grade[5] = 1000;
	int lowestGrade = 0;
	double AverageGrade = 0.0;
	int ErrorVariable = 0;
	char letterGrade;
	//Open the files
	fin.open("student_input.dat");
	fout.open("student_results.dat");

	//Check that the files open properly
	if(fin.fail())
	{
		cout << "Input file did not open. Terminating program.";
		cout << endl;
		return -1;
	}
	
	if(fout.fail())
	{
		cout << "Output file did not open. Terminating program.";
		cout << endl;
		return -1;
	}

	fout << setw(35) << "Grade Report\n\n";
	fout << left << setw(15) << "Last Name" << left << setw(15) << "First Name";
	fout << left << setw(15) << "ID" << left << setw << "Average Score";
	fout << left << setw(15) << "Grade" << endl;
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
		grade[0] = atoi(Token(line, 3, returnBuffer));
		grade[1] = atoi(Token(line, 4, returnBuffer));
		grade[2] = atoi(Token(line, 5, returnBuffer));
		grade[3] = atoi(Token(line, 6, returnBuffer));
		grade[4] = atoi(Token(line, 7, returnBuffer));
		grade[5] = atoi(Token(line, 8, returnBuffer));
		
		lowestGrade = FindLowest(grade, NumGrades);	
		cout << "Lowest grade: " << lowestGrade << endl;

		AverageGrade = Average(grade, lowestGrade, NumGrades);
		cout << "average: " << fixed << setprecision(1) << AverageGrade << endl;

		if(grade[5] == 1000)
			cout << "There are only 5 grades.\n";
		for(int index = 0; index < NumGrades; index++)
		{
			if(grade[index] < 0)
			{
				cout << "Error: Negative grade.\n";
				cout << "Terminating program.\n";
				return -1;
			}
		}

		letterGrade = CalculateLetterGrade(AverageGrade);		
		OutputStudentData(grade, NumGrades, * first, * last, ID, AverageGrade, letterGrade);
	}

		OutputGradeTotals(letterGrade);
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
int FindLowest(int grade[], const int NumGrades)
{
	int lowest = grade[0];

	if(grade[5] != 1000)
	{
		for(int index = 0; index < NumGrades; index++)
		{
			if(grade[index] < lowest)
				lowest = grade[index];
		}
	}
	if(grade[5] == 1000)
		lowest = 0;
	
	return lowest;

}

/*******************************************
Function 3: Find average grade
*******************************************/
double Average(int grade[], int lowestGrade, const int NumGrades)
{
	double average = 0.0;
	int total = 0;

	for(int index = 0; index < NumGrades; index++)
		total += grade[index];
	
	if (grade[5] != 1000)
	{
		total = total - lowestGrade;
		average = total/5;
	}
	if(grade[5] == 1000)
	{
		total = total - grade[5];
		average = total/5;
	
	}
	average = total /5;
	return average;
}

/*****************************************************
Function 4: Find the letter grade totals
*****************************************************/
char CalculateLetterGrade(double AverageGrade)
{
	char letter;
	
	if(AverageGrade >= 89.5)
		letter = 'A';
	if(AverageGrade >= 79.5 && AverageGrade < 89.5)
		letter = 'B';
	if(AverageGrade >= 69.5 && AverageGrade < 79.5)
		letter = 'C';
	if(AverageGrade >= 59.5 && AverageGrade < 69.5)
		letter = 'D';
	else
		letter = 'F';
	return letter;
}

/*****************************************************
Function 5: Print all data to output file
*****************************************************/
void OutputStudentData(int grade[], const int NumGrades, char * first,
		char * last, int ID, double AverageGrade, char letterGrade)
{
	fout << left << setw(15) << last << left << setw(15) << first;
	fout << left << setw(15) << ID << left << setw(15) << fixed << setprecision(1) << AverageGrade;
	fout << left << setw(15) << letterGrade << endl;
} 
/***************************************************
Function 6: Display grade letter totals)
***************************************************/
void OutputGradeTotals(char letterGrade)
{

	int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0;
	if(letterGrade == 'A')
		totalA++;
	if(letterGrade == 'B')
		totalB++;
	if(letterGrade == 'C')
		totalC++;
	if(letterGrade == 'D')
		totalD++;
	if(letterGrade == 'F')
		totalF++;

	fout << setw(5) << "Grade Totals:" << endl;
	fout << setw(5) << "A - " << totalA << endl;
	fout << setw(5) << "B - " << totalB << endl;
	fout << setw(5) << "C - " << totalC << endl;
	fout << setw(5) << "D - " << totalD << endl;
	fout << setw(5) << "F - " << totalF << endl;
}
