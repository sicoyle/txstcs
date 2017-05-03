/*****************************************************
Name: Samantha Coyle
Date: 5/2/2017
Problem Number: 7
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#define MAX_STACK_SIZE 256

#include <string.h>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

//Create stack
class stack
{
	//Declare private members for stack
	private:
		int top;
		int stackSize;
		char * stackArray; //Dynamic array
	
	//Declare public members for stack
	public:
		//Constructor
		stack(int size)
    		{
			stackSize = size;
			stackArray = new char(size);
        		top = -1;
    		}
	
		//Destructor
    		~stack(){};

		//Function to remove characters from the stack
		char pop()
    		{
        		if((top > 0) || (top == 0))
        		{
            			char c = (*(stackArray + top));
            			top--;
            			return c;
        		}

        		else
				return '\0';
    		}

		//Function to push characters to stack
    		bool push(char c)
    		{
			bool check = false;

        		if(top < (MAX_STACK_SIZE - 1))
        		{
            			check =  true;
            			top++;
            			(*(stackArray + top)) = c;            
        		}
			
			//If stack is full, you can't push to it
			if(isFull())
				check = false;
			
        		return check;
    		}    	

		//Function to check if stack has values in it or not
		bool isEmpty()
    		{
			bool check = false;

        		if(top < 0)
            			check = true;
        		
			return check;
    		}

		//Function to check if stack is full or not
    		bool isFull()
    		{
			bool check = false;

    			if((top > (MAX_STACK_SIZE - 1)) ||
			   (top == (MAX_STACK_SIZE - 1)))
            			check = true;
			
	        	return check;
    		}
};

//Function to return if the chars are elements or not
bool Match(char c1, char c2)
{
	bool check = false;

	if((c1 == ')') && (c2 == '('))
		check = true;

	if((c1 == ']') && (c2 == '['))
		check = true;
	
	return check;
}

//Function to return if the elements in the expression are balanced
bool checkBalance(char * equa)
{
	//Variables
	bool check = true;
	stack haystack(MAX_STACK_SIZE); //Create object
	int equationSize = strlen(equa); //Get equation size

	//Loop through every element in expression
	for(int index = 0; index < equationSize; index++)
	{
		//If left element found, push to stack
		if(((*(equa + index)) == '(') || ((*(equa + index)) == '['))
	        	haystack.push((*(equa + index)));
        	
		//If right element found, check if its opposite is in stack
		else if(((*(equa + index)) == ')') ||
			((*(equa + index)) == ']'))
        	{
			//If elements do not match, return false
        		if(Match((*(equa + index)), 
			   haystack.pop()) == false)
                		check = false; //return false
        	}
    	}
    
	//Last check to see if there is an element missing
	if(haystack.isEmpty() == false)
        	check = false;

	return check;
}

//Main function to test the functions to see if balanced expression or not
int main(int arg1, char * arg2[])
{
	//Variables for files
	ofstream fout;
	ifstream fin;
	fout.open("exp_output.dat", ios::app);
	string fileName;
	string equationVar;

	//Get equation
	char * equation;

	//Open input file
	cout << "Enter file name: ";
	cin >> fileName;
	fin.open(fileName.c_str());

	//Check input file opens
	if(fin.fail())
	{
		cout << "Error: input file did not open." << endl;
		return -1;
	}

	//Check output file opens
	if(fout.fail())
	{
		cout << "Error: output file did not open." << endl;
		return -1;
	}

	//Read in the file
	while(getline(fin,equationVar))
	{
		//Variables for counting elements
		int leftBrack = 0;
		int leftParen = 0;
		int rightBrack = 0;
		int rightParen = 0;
		int brackDifference = 0;
		int parenDifference = 0;

		//Flags are true if right element preceeds left element
		bool rightBrackFlag = false;
		bool rightParenFlag = false;

		//Flag for if there are more than 6 errors in equation
		bool errorFlag = false;

		//Variables for expression and expression size
		int size = equationVar.length();
		equation = new char[size];
		strcpy(equation, equationVar.c_str());

		//Loop through each char in expression
		for(int index = 0; index < size; index++)
		{
			//Increment count for each element
			if(equation[index] == '(')
				leftParen++;
			else if(equation[index] == '[')
				leftBrack++;  
			else if(equation[index] == ')')
				rightParen++;	
			else if(equation[index] == ']')
				rightBrack++;

			//Create a flag for if there is a right element
			//before left element		
			if(rightBrack > leftBrack)
				rightBrackFlag = true;

			if(rightParen > leftParen)
				rightParenFlag = true;


		}
cout << "Equation: " << equation << " LP: " << leftParen << " RP: " << rightParen << " LB: " << leftBrack << " RB: " << rightBrack << endl;
		//Display the equation in output file
		fout << equation << " ";

		//Display that expression is valid if elements are balanced
		if(checkBalance(equation) == true)
	    		fout << " === valid expression";

		//Display what is wrong with expression if not balanced
	    	else
	    	{
			//Error if 6+ errors:
			if((leftBrack + rightBrack + leftParen + rightParen) > 6)
			{
				fout << "    Error: More than 6 missing elements ";
	        		errorFlag = true;
			}
			fout<<" === missing: ";

			brackDifference = leftBrack - rightBrack;
			parenDifference = leftParen - rightParen;
cout << "Brackdifference: " << brackDifference << " parendifference: " << parenDifference << endl;
			//Display what is missing if uneven # of brackets
			if((leftBrack != rightBrack) && !errorFlag)
			{
				if(rightBrack > leftBrack)
					fout << (rightBrack - leftBrack) << " [ ";
				if(leftBrack > rightBrack)
					fout << (leftBrack - rightBrack) << " ] ";
			}
			
			//Display what is missing if uneven # of parentheses
			if((leftParen != rightParen) && !errorFlag)
			{
				if(rightParen > leftParen)
					fout << (rightParen - leftParen) << " ( ";
				if(leftParen > rightParen)
					fout << (leftParen - rightParen) << " ) ";
			}
			
			//Display what is missing with equation with same #
			//of elements, but it is not balanced properly
			if((leftBrack == rightBrack) && (leftParen == rightParen) && !errorFlag)
			{
				//Display what expression is missing
				if((leftBrack == rightBrack) &&
				(leftBrack != 0) && (rightBrack != 0) && rightBrackFlag)
					fout << rightBrack << " ] " << leftBrack << " [ ";
				if((leftParen == rightParen) &&
				(leftParen != 0) && (rightParen != 0) && rightParenFlag)
					fout << rightParen << " ) " << leftParen << " ( ";
			}

	    	}
		
		//Seperate each line
		fout << endl;
	}//Close the while loop reading in the input file
	
	return 0;
}
