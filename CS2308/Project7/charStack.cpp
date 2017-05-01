/*****************************************************
Name: Samantha Coyle
Date: 4/25/2017
Problem Number: 7
Hours spent solving the problem: 6
Instructor: Komogortsev, TSU
*****************************************************/
#include <cstring>
#include <cmath>
#include "charStack.h"
#include <iostream>
#include <fstream>

using namespace std;

//Function to check that the parenthese match in the equation
bool charStack::checkParenthesisMatch(char ch1, char ch2)
{
	bool result = false;
	
	if((ch1 == ']' && ch2 == '[') || (ch1 == '}' && ch2 == '{') || (ch1 == ')' && ch2 == '('))
		result = true;
	
	return result;
}

//Function to write to the output file
void charStack::writeToFile(char equa[], int s, charStack st)
{
	ofstream fout;
	fout.open("exp_output.dat", ios::app);
cout << "In write to file function." << endl;

	if(fout.fail())
	{
		cout << "Error: output file did not open." << endl;
		return;
	}	
cout << "Equation from write to file function: " << equa << endl;
	fout << equa;	
}

//Function to check if the parentheses are balanced in the equation
bool charStack::checkBalancedParenthesis(char equa[])
{
	ofstream fout;
	fout.open("exp_ouput.dat", ios::app);
	int equationSize = strlen(equa);
	bool check = true;
	charStack st(equationSize);
	int leftBrack = 0;
	int leftParen = 0;
	int rightBrack = 0;
	int rightParen = 0;
	int brackets = 0;
	int parentheses = 0;

	//Display the equation
	fout<< equa;
	cout << "Equation: " << equa << " Equation size: " << equationSize << endl << "What is read into char array in for loop: ";

	//Go through each char in expression
	for(int s = 0; s < equationSize; s++)
	{	
		//If bracket or parenthese encountered push to stack
		if((equa[s] == '[') || (equa[s] == '('))
			st.push(equa[s]);

		//Increment counter for each element encountered
		if(equa[s] == '(')
			leftParen++;
		else if(equa[s] == '[')
			leftBrack++;  
		else if(equa[s] == ')')
			rightParen++;	
		else if(equa[s] == ']')
		{
			rightBrack++;
			cout << "    Increase right bracket counter" << endl;
		}

		//Return false for balanced expression for elements
//		if((equa[s] == ']') || (equa[s] == ')'))
//		{
			if(checkParenthesisMatch(equa[s], st.pop()) == false)
			{
				check = false;
				//break;
//			}
		}
	}

	//Get total number of brackets and parentheses
	brackets = leftBrack - rightBrack;
	parentheses = leftParen - rightParen;	

	//If expression has an element missing, say it is missing something
	if((brackets != 0) || (parentheses != 0))
		fout << " === missing ";

	//If expression has no elements missing, say it is valid
	else if((brackets == 0) && (parentheses == 0))
		fout << " === valid expression";

	//Display what the expression is missing
	if(brackets > 0)
		fout << abs(brackets) << " ] ";
	if(brackets < 0)
		fout << abs(brackets) << " [ ";
	if(parentheses > 0)
		fout << abs(parentheses) << " ) ";
	if(parentheses < 0)
		fout << abs(parentheses) << " ( ";

	//Display results to console
	cout << "    RP " << rightParen << " LP " << leftParen << " RB " << rightBrack << " LB " << leftBrack <</*" RC " << rightCurly << " LC " << leftCurly << */endl;
	
	//Provide error message if more than 6 missing elements
	if((brackets + parentheses) > 6)
		fout << " Error: there are more than 6 elements missing from expression.";

	fout << endl;

	//Last check for balanced elements in expression
	if(st.isEmpty() == false)
		check = false;

	return check;
}

//Constructor to initialize stack
charStack::charStack(int size)
{
	top = -1;
	stackSize = size;
	stackArray = new int(size);
}


//Destructor to get rid of the stack
charStack::~charStack() {delete [] stackArray;}

//Function to add to the stack
void charStack::push(int num)
{
	if(isFull())
		cout << "The stack is full. Nothing is added to the stack." << endl;

	else
	{
		top++;
		stackArray[top] = num;
	}
}

//Function to remove from the stack
char charStack::pop()
{
/*	if(!isEmpty())
		cout << "The stack is empty." << endl;
	
	else
	{
		num = stackArray[top];
		top--;
	}*/

	if(top>=0)
        {
            	char ch = stackArray[top];
            	top--;
            	return ch;
        }
	return '\0';
}

//Check if the stack is full
bool charStack::isFull() const
{
	bool check;
	
	if(top == stackSize - 1)
		check = true;

	else
		check = false;

	return check;
}

//Check if the stack is empty
bool charStack::isEmpty() const
{
	bool check;

	if(top == -1)
		check = true;

	else
		check = false;

	return check;
}
