#include <iostream>

using namespace std;

void print_longest_palindrome(char* str)
{
	int n = strlen(str);

	bool X[n][n];

	memset(X, 0, sizeof(X));

	int start = 0, length = 0;

	// j=0
	for(int i=0;i<n;i++)
	{
		X[i][i] = true;
		start = 0; length = 1;
	}

	// j=1
	for(int i=0;i<n-1;i++)
	{
		if(str[i] == str[i+1])
		{
			X[i][i+1] = true;
			start = i; length = 2;
		}
	}

	for(int j=2;j<n;j++)
	{
		for(int i=0;i<n-j;i++)
		{
			if(str[i] == str[i+j] && X[i+1][i+j-1])
			{
				X[i][i+j] = true;
				if(j > length)
				{
					start = i; length = j+1;
				}
			}
		}
	}

	//for(int i=0;i<n;i++) { for(int j=0;j<n;j++) cout << X[i][j] << " "; cout << endl; }

	for(int i=start;i<start+length;i++)
		cout << str[i];
	cout << endl;
	
}

int main()
{
	{ char str[] = "abcdefghiihgfedabc"; print_longest_palindrome(str); }
	{ char str[] = ""; print_longest_palindrome(str); }
	{ char str[] = "a"; print_longest_palindrome(str); }
	{ char str[] = "aa"; print_longest_palindrome(str); }
	{ char str[] = "abcdefghijklmn"; print_longest_palindrome(str); }
	{ char str[] = "abababababababab"; print_longest_palindrome(str); }
	return 0;
}
