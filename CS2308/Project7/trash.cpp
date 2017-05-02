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
	int leftBrack = 0;
	int leftParen = 0;
	int rightBrack = 0;
	int rightParen = 0;
	int brackets = 0;
	int parentheses = 0; 


   char str[MAX_SIZE];
    cout<<"Enter parenthesis expression that you wish to check for:"<<endl;
    cin>>str;

	for(int index = 0; index < sizeof(str); index++)
	{
		if(str[index] == '(')
			leftParen++;
		else if(str[index] == '[')
			leftBrack++;  
		else if(str[index] == ')')
			rightParen++;	
		else if(str[index] == ']')
			rightBrack++;
	}

	//Get total number of brackets and parentheses
	brackets = leftBrack - rightBrack;
	parentheses = leftParen - rightParen;

cout << "RP " << rightParen << " LP " << leftParen << " RB " << rightBrack << " LB " <<  leftBrack << endl;

    if(checkBalancedParenthesis(str) == true)
        cout<<"Given expression is balanced";
    else
    {
        cout<<"Given expression is not balanced";
        if((brackets == 0) || (parentheses == 0))
	{
		cout << "Missing: " << leftBrack << " LB " << rightBrack << " RB " << leftParen << " LP " << rightParen << " RP " << endl;
	}
    }
	return 0;
}
