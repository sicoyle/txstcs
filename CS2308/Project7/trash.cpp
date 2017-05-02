/*****************************************************
Name: Samantha Coyle
Date: 5/2/2017
Problem Number: 7
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <fstream>
#include <cmath>
#include <iostream>
#include <string.h>
#define MAX_STACK_SIZE 256

using namespace std;

//Create stack
class stack
{
	private:
		char * stackArray; //Dynamic array
		int stackSize;
		int top;
	
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
        		if(top >= 0)
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

        		if (top < (MAX_STACK_SIZE - 1))
        		{
            			top++;
            			(*(stackArray + top)) = c;            
            			check =  true;
        		}
			
			//If stack is full, you can't push to it
			if(isFull())
				check = false;
			
			else
        			return check;
    		}    	

		//Function to check if stack has values in it or not
		bool isEmpty()
    		{
        		if(top < 0)
            			return true;
        		else
				return false;
    		}

		//Function to check if stack is full or not
    		bool isFull()
    		{
    			if(top >= (MAX_STACK_SIZE - 1))
            			return true;
			else
	        		return false;
    		}
};

//Function to return if the chars are elements or not
bool checkElementsMatch(char c1, char c2)
{
	bool check = false;

	if((c1 == ')' && c2 == '(') || (c1 == ']' && c2 == '['))
		check = true;

	return check;
}

//Function to return if the elements in the expression are balanced
bool checkElementsBalanced(char equa[])
{
	//Variables
	stack st(MAX_STACK_SIZE); //Create object
	bool check = true;
	int equationSize = strlen(equa); //Get equation size

	//Loop through every element in expression
	for(int index = 0; index < equationSize; index++)
	{
		//If left element found, push to stack
		if(((*(equa + index)) == '(') || ((*(equa + index)) == '['))
	        	st.push(equa[index]);
        	
		//If right element found, check if its opposite is in stack
		else if(((*(equa + index)) == ')') ||
			((*(equa + index)) == ']'))
        	{
			//If elements do not match, return false
        		if(checkElementsMatch((*(equa + index)), st.pop())
								== false)
            		{
                		check = false; //return false
                		break; //get out of loop
            		}
        	}
    	}
    
	//Last check to see if there is an element missing
	if(st.isEmpty() == false)
        	check = false;

	return check;
}

//Main function to test the functions to see if balanced expression or not
int main(int argc, char* argv[])
{
	//Variables for files
	ofstream fout;
	ifstream fin;
	fout.open("exp_output.dat", ios::app);
	string fileName;
	string equationVar;

	//Get equation
	char * equation;
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

		//Variables for expression and expression size
		int size = equationVar.length();
		equation = new char[size];
		strcpy(equation, equationVar.c_str());

		//Flags to tell me if the element nums are even or odd
		bool BracketFlag = false;
		bool ParenthesesFlag = false;

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
		}

		//Display the equation in output file
		fout << equation << " ";

		//Display that expression is valid if elements are balanced
		if(checkElementsBalanced(equation) == true)
	    		fout << " === valid expression";

		//Display what is wrong with expression if not balanced
	    	else
	    	{
	        	fout<<" === missing: ";

			//Check if brackets are equal in number
			if(leftBrack != rightBrack)
				BracketFlag = true;

			//Check if parenthese are equal in number
			if(leftParen != rightParen)
				ParenthesesFlag = true;

			//Display what is missing if uneven # of brackets
			if(BracketFlag)
			{
				if(rightBrack > leftBrack)
					fout << (rightBrack - leftBrack) << " [ ";
				if(leftBrack > rightBrack)
					fout << (leftBrack - rightBrack) << " ] ";
			}
			
			//Display what is missing if uneven # of parentheses
			if(ParenthesesFlag)
			{
				if(rightParen > leftParen)
					fout << (rightParen - leftParen) << " ( ";
				if(leftParen > rightParen)
					fout << (leftParen - rightParen) << " ) ";
			}
		
			//Display what is missing with equation with same #
			//of elements, but it is not balanced properly
			if(!BracketFlag && !ParenthesesFlag)
			{
				//Display what expression is missing
				if((leftBrack == rightBrack) &&
					(leftBrack != 0) && (rightBrack != 0))
					fout << rightBrack << " ] " << leftBrack << " [ ";
				if((leftParen == rightParen) &&
					(leftParen != 0) && (rightParen != 0))
					fout << rightParen << " ) " << leftParen << " ( ";
			}

			//Error if 6+ errors:
			if((leftBrack + rightBrack + leftParen + rightParen) > 6)
				fout << "    Error: More than 6 missing elements ";
	    	}
		



		//Seperate each line
		fout << endl;
	}
	
	return 0;
}
