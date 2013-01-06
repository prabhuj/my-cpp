#include <iostream>

int main()
{
	unsigned long long x = 28433;
	unsigned long long y = 10000000000ull;
	for(int i=0;i<7830457;i++)
	{
		x = x*2;
		x = x%y;
	}
	cout << x+1 << endl;
}
