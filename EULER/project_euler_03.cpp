#include <iostream>
#include <math.h>

#define NUM 600851475143ULL

bool isprime(long long z)
{
	int x = (int)sqrt(z);

	for(int i=2;i<=x;i++)
		if(z%i==0)
			return false;

	return true;
}

int main()
{
	int x = (int)sqrt(NUM);
	int prime_fac = 1;

	for(long long i=2;i<=x;i++)
	{
		if(NUM%i==0)
		{
			if(isprime(i))
				if(prime_fac < i)
					prime_fac = i;
			if(isprime(NUM/i))
				if(prime_fac < (NUM/i))
					prime_fac = NUM/i;
		}
	}

	cout << prime_fac << endl;
}
