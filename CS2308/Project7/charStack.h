/****************************************************
Name: Samantha Coyle
Date: 4/25/2017
Problem Number: 7
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef charStack_h
#define charStack_h
#include "charStack.h"

using namespace std;

class charStack
{
	private:
		int top;
		int * stackArray;
		int stackSize;

	public:
		charStack(int size); //Constructor
		~charStack(); //Destructor

		//Functions
		void writeToFile(char equa[], int s, charStack st);
		bool checkParenthesisMatch(char, char);
		bool checkBalancedParenthesis(char []);
		void push(int);
		char pop();
		bool isFull() const;
		bool isEmpty() const;
};

#endif
