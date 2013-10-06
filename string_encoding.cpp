#include <iostream>

using namespace std;

char* encode(char* x)
{
	if (!x)
		return;
	int i = 0;
	char t = '\0';
	int count = 0;
	for(int i=0;i<strlen(x);i++)
	{
		if(x[i] == t)
		{
			count++;
		}
		else
		{
			cout << t << " :: " << count << endl;
			t = x[i];
			count = 0;
		}
	}
	return x;
}

int main()
{
	char x[] = "aaaaaaaaabbbcccccdefggggggggggg";
	cout << encode(x) << endl;
}
