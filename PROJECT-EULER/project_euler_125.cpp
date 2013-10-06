#include <iostream>

using namespace std;

#define MAX 500
#define uint unsigned long long

bool is_palindrome(int x)
{
	if(x<10)
		return false;
	int t = x;
	int y = 0;
	while(t>0)
	{
		y = (y*10) + (t%10);
		t /= 10;
	}
	return (x==y)?true:false;
}

int main()
{
	uint sum = 0;
	for(int i=1;i<=MAX;i++)
	{
		sum = i*i;
		for(int j=i+1;j<=MAX;j++)
		{
			sum += (j*j);
			if(sum > 1000)
				break;
			if(is_palindrome(sum))
			{
				cout << i << " to " << j << " :: " << endl;
				cout << sum << " is palindromic" << endl;
			}
		}
	}
}
