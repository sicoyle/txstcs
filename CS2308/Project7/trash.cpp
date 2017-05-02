#include <fstream>
#include <cmath>
#include <iostream>
#include <string.h>
#define MAX_SIZE 256
using namespace std;
class stack{
    char * stackArray;
    int stackSize;
    int top;
public:
    stack(int size)
    {
        top = -1;
	stackSize = size;
	stackArray = new char(size);
    }
    ~stack(){};
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
    bool isFull()
    {
        if(top >= MAX_SIZE-1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if(top < 0)
            return true;
        return false;
    }
};
/*
    checkParenthesisMatch(char,char) would return false if given chars are not appropriate.
*/
bool checkParenthesisMatch(char ch1, char ch2)
{
    bool check = false;
    if(    (ch1 == ']' && ch2 == '[') ||
        (ch1 == '}' && ch2 == '{') ||
        (ch1 == ')' && ch2 == '(') )
        check = true;
    return check;
}
/*
    checkBalancedParenthesis(char[]) would return false if parenthesis are not balanced.
*/
bool checkBalancedParenthesis(char equa[])
{
    int len = strlen(equa);
    bool check = true;
    stack st(MAX_SIZE);
    for(int i=0;i<len;i++)
    {
        if(    (equa[i] == '[') ||
            (equa[i] == '{') ||
            (equa[i] == '(') )
        {
            st.push(equa[i]);
        }
        else if((equa[i] == ']') ||
                (equa[i] == '}') ||
                (equa[i] == ')') )
        {
            if(checkParenthesisMatch(equa[i],st.pop()) == false)
            {
                check = false;
                break;
            }
        }
    }
    /*There exists a case where even after successful check from above statements
    still the possibility of imbalance exists; e.g., [{}()[()]  -->Missed one more 
    closing parenthesis. Check this case by checking stack space
    */
    if(st.isEmpty()== false)
        check = false;

    return check;
}
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
