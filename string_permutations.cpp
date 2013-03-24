#include <iostream>

using namespace std;

void permute(char* str, int i, int n)
{
	if(i==n)
	{
		cout << str << endl;
	}
	else
	{
		for(int j=i;j<=n;j++)
		{
			swap(str[i], str[j]);
			permute(str, i+1, n);
			swap(str[i], str[j]);
		}
	}
}

int main()
{
	char str[] = "abc";
	permute(str, 0, 2);
	return 0;
}
