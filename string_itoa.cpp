#include <iostream>

using namespace std;

void reverse(char s[])
{
	int len = strlen(s);
	for(int i=0;i<len/2;i++)
	{
		char t = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = t;
	}
}

void itoa(int n, char s[])
{
	int i = 0, sign;
	if ((sign = n) < 0)
		n = -n;
	while(n>0)
	{
		s[i++] = n%10 + '0';
		n /= 10;
	}

	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[10];
	itoa(-12340,s);
	cout << s << endl;
}
