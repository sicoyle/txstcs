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
#define MAX_SIZE 256

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
        		top = -1;
			stackSize = size;
			stackArray = new char(size);
    		}
	
		//Destructor
    		~stack(){};

		//Function to push characters to stack
    		bool push(char c)
    		{
        		if (top < MAX_SIZE-1)
        		{
            			top++;
            			stackArray[top] = c;            
            			return true;
        		}
        		return false;
    		}
    	
		//Function to remove characters from the stack
		char pop()
    		{
        		if(top>=0)
        		{
            			char c = stackArray[top];
            			top--;
            			return c;
        		}
        		return '\0';
    		}

		//Function to check if stack is full or not
    		bool isFull()
    		{
    			if(top >= MAX_SIZE-1)
            			return true;
        		return false;
    		}
   
		//Function to check if stack has values in it or not
		bool isEmpty()
    		{
        		if(top < 0)
            			return true;
        		return false;
    		}
};

//Function to return if the chars are elements or not
bool checkParenthesisMatch(char ch1, char ch2)
{
	bool check = false;
	if((ch1 == ']' && ch2 == '[') || (ch1 == '}' && ch2 == '{') ||
    		(ch1 == ')' && ch2 == '(') )
		check = true;
	return check;
}

//Function to return if the elements in the expression are balanced
bool checkBalancedParenthesis(char equa[])
{
	//Variables
	int equationSize = strlen(equa);
	bool check = true;
	stack st(MAX_SIZE);

	//Loop through every element in expression
	for(int index = 0; index < equationSize; index++)
	{
		//If ( or [ found, push to stack
		if(((*(equa + index)) == '(') || ((*(equa + index)) == '['))
	        	st.push(equa[index]);
        
		else if(((*(equa + index)) == ')') || ((*(equa + index)) == ']'))
        	{
        		if(checkParenthesisMatch((*(equa + index)),st.pop()) == false)
            		{
                		check = false;
                		break;
            		}
        	}
    	}
    
	//Last check to see if there is an element missing
	if(st.isEmpty()== false)
        	check = false;

	return check;
}

//Main function to test the functions to see if balanced expression or not
int main(int argc, char* argv[])
{
	
	ofstream fout;
	ifstream fin;
	fout.open("exp_output.dat", ios::app);
	string fileName;
	string equationVar;
	char * equation;
	cout << "Enter file name: ";
	cin >> fileName;
	fin.open(fileName.c_str());

	if(fin.fail())
	{
		cout << "Error: file did not open" << endl;
		return -1;
	}

	while(getline(fin,equationVar))
	{
		int leftBrack = 0;
		int leftParen = 0;
		int rightBrack = 0;
		int rightParen = 0;
		int size = equationVar.length();
		equation = new char[size];
		bool BracketFlag = false;
		bool ParenthesesFlag = false;

		strcpy(equation, equationVar.c_str());

		for(int index = 0; index < size; index++)
		{
			if(equation[index] == '(')
				leftParen++;
			else if(equation[index] == '[')
				leftBrack++;  
			else if(equation[index] == ')')
				rightParen++;	
			else if(equation[index] == ']')
				rightBrack++;
		}

		int brackets = 0;
		int parentheses = 0; 
	
		//Get total number of brackets and parentheses
		brackets = leftBrack + rightBrack;
		parentheses = leftParen + rightParen;

		fout << equation << " ";

	    if(checkBalancedParenthesis(equation) == true)
	        fout << " === valid expression";
	    else
	    {
	        fout<<" === missing: ";

		if(leftBrack != rightBrack)
			BracketFlag = true;

		if(leftParen != rightParen)
			ParenthesesFlag = true;

		//Display what the expression is missing if uneven # of elements
		if(BracketFlag)
		{
			if(rightBrack > leftBrack)
				fout << (rightBrack - leftBrack) << " [ ";
			if(leftBrack > rightBrack)
				fout << (leftBrack - rightBrack) << " ] ";
		}
		
		if(ParenthesesFlag)
		{
			if(rightParen > leftParen)
				fout << (rightParen - leftParen) << " ( ";
			if(leftParen > rightParen)
				fout << (leftParen - rightParen) << " ) ";
		}
		if(!BracketFlag && !ParenthesesFlag)
		{
			//Display what expression is missing with same # of elements
			if((leftBrack == rightBrack) && (leftBrack != 0) && (rightBrack != 0))
				fout << rightBrack << " ] " << leftBrack << " [ ";
			if((leftParen == rightParen) && (leftParen != 0) && (rightParen != 0))
				fout << rightParen << " ) " << leftParen << " ( ";
		}
	    }
		fout << endl;
	}
	
	
return 0;
}
