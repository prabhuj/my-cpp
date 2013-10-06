#include <iostream>
#include <stack>

using namespace std;

void check_exp(char *exp)
{
	cout << "expression " << exp << " - ";
	stack<char> mystack;
	while(*exp != '\0')
	{
		char ch = *exp;
		if(ch == '[' || ch == '{' || ch == '(')
		{
			mystack.push(ch);
		}
		else if (ch == ']')
		{
			if(mystack.top() != '[')
			{
				cout << "expression not balanced" << endl;
				return;
			}
			mystack.pop();
		}
		else if (ch == '}')
		{
			if(mystack.top() != '{')
			{
				cout << "expression not balanced" << endl;
				return;
			}
			mystack.pop();
		}
		else if (ch == ')')
		{
			if(mystack.top() != '(')
			{
				cout << "expression not balanced" << endl;
				return;
			}
			mystack.pop();
		}
		exp++;
	}
	cout << "expression is balanced" << endl;
}

int main()
{
	check_exp("[{()}]");
	check_exp("[{((}]");
	return 0;
}
