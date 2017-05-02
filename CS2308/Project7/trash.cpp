#include <fstream>
#include <cmath>
#include <iostream>
#include <string.h>
#define MAX_SIZE 100
using namespace std;
class stack{
    char data[MAX_SIZE];
    int top;
public:
    stack()
    {
        top = -1;
    }
    bool push(char ch)
    {
        if (top < MAX_SIZE-1)
        {
            top++;
            data[top] = ch;            
            return true;
        }
        return false;
    }
    char pop()
    {
        if(top>=0)
        {
            char ch = data[top];
            top--;
            return ch;
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
    bool result = false;
    if(    (ch1 == ']' && ch2 == '[') ||
        (ch1 == '}' && ch2 == '{') ||
        (ch1 == ')' && ch2 == '(') )
        result = true;
    return result;
}
/*
    checkBalancedParenthesis(char[]) would return false if parenthesis are not balanced.
*/
bool checkBalancedParenthesis(char exp[])
{
    int len = strlen(exp);
    bool result = true;
    stack st;
    for(int i=0;i<len;i++)
    {
        if(    (exp[i] == '[') ||
            (exp[i] == '{') ||
            (exp[i] == '(') )
        {
            st.push(exp[i]);
        }
        else if((exp[i] == ']') ||
                (exp[i] == '}') ||
                (exp[i] == ')') )
        {
            if(checkParenthesisMatch(exp[i],st.pop()) == false)
            {
                result = false;
                break;
            }
        }
    }
    /*There exists a case where even after successful result from above statements
    still the possibility of imbalance exists; e.g., [{}()[()]  -->Missed one more 
    closing parenthesis. Check this case by checking stack space
    */
    if(st.isEmpty()== false)
        result = false;

    return result;
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
