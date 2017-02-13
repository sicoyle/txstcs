/****************************************
Name: Samantha Coyle
Date: February 14, 2017
Problem Number: 2
Hours spent solving the problem: 4
Instructor: Komogortsev, TSU
****************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//Prototypes
char * Token(char * line, int position, char * tokenReturnBuffer);
void AssignInfo(char line[], char First[], char Last[],
	    char ID[], char g1[], char g2[], char g3[],
	     char g4[], char g5[], char g6[], char * returningBuf);

//Create file objects
ifstream fin;
ofstream fout;

int main()
{
	//Declare variables
	const int SIZE = 256;
	const int SIZE2 = 15;
	char line[SIZE];
	char buffer[SIZE2];
	int position = 0;
	char First[11];
	char Last[13];
	char ID[7], g1[5], g2[5], g3[5], g4[5], g5[5];
	char g6[5] = {0,0,0,0,'\0'};

	//Open the files
	fin.open("student_input.dat");
	fout.open("student_results.dat");

	//Read in data
	while(!fin.eof())
	{	
		fin.getline(line, SIZE, '\0');
char * returnBuffer = new char[256];
		cout << "This is what I read in: " << line << endl;
		
		//cout << "This is what is returned from token (NAME): " << 
		

		cout << "position: ";
	//	cin >> position;

		//First = Token(line, 0,); 

		//atoi(Token(line, 2, returnBuffer)) << endl;
		AssignInfo(line, First, Last, ID, g1, g2, g3, g4, g5, g6, returnBuffer);
		cout << "ID " << ID << endl;	
	}

	//Close the files
	fin.close();
	fout.close();

	return 0;
	}

/***********************************************
Function 1: Create tokenizer to split string
***********************************************/
char * Token(char * line, int position, char * tokenReturnBuffer)
{
	char delimiter = ' ';
	char delimiter2 = '\t';	
	char * iterator = line;
	int count = 0;
	int letterCount = 0;
	do
	{
		if(( * iterator == delimiter) || (* iterator == delimiter2))
		{
			count++;
		}

		while (( * iterator == delimiter) || ( * iterator == delimiter2))
		{
			iterator++;
		}
			
	} while((* iterator++) && (count != position));
	iterator--;
//we're pointing to the first char of the word we want.
//Make new iterator. While not delimiter, iterator2 ++, once == to delimiter *iterator2 = '\0'
	char * iterator2 = iterator;

	while ((* iterator2 != delimiter) && (* iterator2 != delimiter2))
	{
		tokenReturnBuffer[letterCount++] = * iterator2;
		iterator2++;
	}

	tokenReturnBuffer[letterCount] = '\0';
cout << "returning token: " << tokenReturnBuffer << endl;
return tokenReturnBuffer;
}

void AssignInfo(char line[], char First[], char Last[], char ID[], 
		char g1[], char g2[], char g3[], char g4[], char g5[], char g6[], char * returningBuf)
{
	First = Token(line, 0, returningBuf);

	cout << "Name1: " << First << endl;

	Last = Token(line, 1, returningBuf);
	cout << "Last: " << Last << endl;
	ID = Token(line, 2, returningBuf);
	g1 = Token(line, 3, returningBuf);
	g2 = Token(line, 4, returningBuf);
	g3 = Token(line, 5, returningBuf);
	g4 = Token(line, 6, returningBuf);
	g5 = Token(line, 7, returningBuf);
	g6 = Token(line, 8, returningBuf);

	cout << "Info: " << Last << " " << ID << " " << g1 << " " << g2 << " " << g3 << " " << g4 << " " << g5 << " " << g6 << endl;
}





/*****************************************************
Function One: Reads in the contents of one line
*****************************************************/
//void readLine(char line[], const int SIZE)
//{
//	fin.getline(line, SIZE);
//	return;
//}

/*****************************************************
Function Two: Parse the line into words/numbers
*****************************************************/
//void parseLine(char line[])
//{
//	const int NAME1 = 11;
//	const int NAME2  = 12;
//	char firstName[NAME1] = {'0','0','0','0','0','0','0','0','0','0','\0'};
//	char lastName[NAME2];
//	int i = 0;
//	
//	while(line[i] != '\0')
//	{
//		cout << "This is what is in line[i]: " << line[i] << endl;
//		if(isalpha(line[i]))
//		{
//			firstName[i] = line[i];
//			if(isspace(line[i++]))
//				break;
//		}
		
			
//		i++;
		
		
//	}
//	cout << "This is what's in first name array: " << firstName << endl;
//	return;
//}*/
