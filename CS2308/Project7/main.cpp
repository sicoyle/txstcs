/****************************************************
Name: Samantha Coyle
Date: 4/25/2017
Problem Number: 7
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>
#include "charStack.h"

using namespace std;

int main()
{
	charStack stack(256);	//Class object
	
	//Create file objects
	ifstream fin;	
	ofstream fout;
	string fileName;
	char * equation;
	bool retCode;

	//Open the files
	cout << "Enter file name: ";
	cin >> fileName;
	fin.open(fileName.c_str());
//	fout.open("exp_output.dat");

	if(fin.fail())
	{
		cout << "Error: input file did not open." << endl;
		return -1;
	}
	
	string equationVar;

	//Read in the file
	while(getline(fin,equationVar))	
	{
		int size = equationVar.length();
		equation = new char[size];

		strcpy(equation, equationVar.c_str());

//		cout << "equation from main " << equation << endl;

//		fout << equation;

		retCode = stack.checkBalancedParenthesis(equation);

		if(retCode == false)
			fout << " === missing: " << endl;

		if(retCode == true)
			fout << " === valid expression" << endl;
	}

	fin.close();
	fout.close();

	return 0;
}
