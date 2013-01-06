#include <iostream>
#include <math.h>

#define DIVISORS 500

int find_divisors(long long x)
{
	int divisors = 2;//1 & x

	int sqroot = (int)sqrt(x);

	for(long long i=2;i<=sqroot;i++)
	{
		if(x%i==0)
			divisors += 2;
	}

	return divisors;
}

int main()
{
	long long triangle_num = 0;

	for(long long i=1;;i++)
	{
		triangle_num += i;

		int div = find_divisors(triangle_num);

		if(div>=DIVISORS)
		{
			break;
		}
	}
	cout << triangle_num << endl;
}
