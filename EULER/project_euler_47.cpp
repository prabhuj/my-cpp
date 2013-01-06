#include <iostream>
#include <math.h>

#define FACTORS 4
#define NUMBERS 4

bool is_prime(int x)
{
	if(x<2)
		return false;
	int s = (int)sqrt(x);
	for(int i=2;i<=s;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	int result = 0;
	for(int num=2;;num++)
	{
		//cout << num << " :: ";
		int prime_factors = 0;
		int s = (int)sqrt(num);
		for(int i=2;i<=s;i++)
		{
			if(num%i==0)
			{
			 	if(is_prime(i) == true)
				{
					//cout << i << " - ";
					prime_factors++;
				}
			 	if(i != num/i && is_prime(num/i) == true)
				{
					prime_factors++;
				}
			}
		}

		//cout << " :: " << prime_factors << endl;
		cout << num << " :: " << prime_factors << endl;

		if(prime_factors == FACTORS)
			result++;
		else
			result = 0;

		if(result == NUMBERS)
			return 0;
	}
}
