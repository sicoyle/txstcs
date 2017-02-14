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
	    grade4 = 0, grade5 = 0, grade6 = 0;
	//char *firstName, lastName;

	//Open the files
	fin.open("student_input.dat");
	fout.open("student_results.dat");

	//Read in data
	while (fin.getline(line, SIZE)) {
		char *returnBuffer = new char[256];
		//Read in the data
		cout << "This is what I read in: " << line << endl;

		first = Token(line, 0, returnBuffer);
		last = Token(line, 1, returnBuffer);
		ID = atoi(Token(line, 2, returnBuffer));
		grade1 = atoi(Token(line, 3, returnBuffer));
		grade2 = atoi(Token(line, 4, returnBuffer));
		grade3 = atoi(Token(line, 5, returnBuffer));
		grade4 = atoi(Token(line, 6, returnBuffer));
		grade5 = atoi(Token(line, 7, returnBuffer));
		grade6 = atoi(Token(line, 8, returnBuffer));

		cout << "ID " << ID << endl;
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
	do {
		if ((*iterator == delimiter) || (*iterator == delimiter2)) {
			count++;
		}

		while ((*iterator == delimiter) || (*iterator == delimiter2)) {
			iterator++;
		}

	} while ((*iterator++) && (count != position));
	iterator--;
	//we're pointing to the first char of the word we want.
	//Make new iterator. While not delimiter, iterator2 ++, once == to delimiter *iterator2 = '\0'
	char *iterator2 = iterator;

	while ((*iterator2 != delimiter) && (*iterator2 != delimiter2)) {
		tokenReturnBuffer[letterCount++] = *iterator2;
		iterator2++;
	}

	tokenReturnBuffer[letterCount] = '\0';
	cout << "returning token: " << tokenReturnBuffer << endl;
	return tokenReturnBuffer;
}

/*
void AssignInfo(char line[], char First[], char Last[], int ID, 
		int grade1, int grade2, int grade3, int grade4, int grade5, int grade6, char * returningBuf)
{

	cout << "Name1: " << First << endl;

	cout << "Last: " << Last << endl;

	cout << "Info: " << First << " " << Last << " " << ID << " " << grade1 << " " << grade2 << " " << grade3 << " " << grade4 << " " << grade5 << " " << grade6 << endl;
}
*/

/*****************************************************
Function One: Reads in the contents of one line
*****************************************************/
//void readLine(char line[], const int SIZE)
//{
//      fin.getline(line, SIZE);
//      return;
//}

/*****************************************************
Function Two: Parse the line into words/numbers
*****************************************************/
//void parseLine(char line[])
//{
//      const int NAME1 = 11;
//      const int NAME2  = 12;
//      char firstName[NAME1] = {'0','0','0','0','0','0','0','0','0','0','\0'};
//      char lastName[NAME2];
//      int i = 0;
//      
//      while(line[i] != '\0')
//      {
//              cout << "This is what is in line[i]: " << line[i] << endl;
//              if(isalpha(line[i]))
//              {
//                      firstName[i] = line[i];
//                      if(isspace(line[i++]))
//                              break;
//              }

//              i++;

//      }
//      cout << "This is what's in first name array: " << firstName << endl;
//      return;
//}*/
