#include <iostream>
#include <math.h>

#define MAX 1000000

bool is_prime(int p)
{
	int s = (int)sqrt(p);
	for(int d=2;d<=s;d++)
	{
		if(p%d==0)
			return false;
	}
	return true;
}

int main()
{
	int x[MAX]; x[2] = 1; x[3] = 1; x[5] = 1; x[7] = 1;
	int y[MAX]; y[2] = 2; y[3] = 2; y[5] = 2; y[7] = 2;

	int sum = 0, count = 0;

	for(int i=10;i<MAX;i++)
	{
		x[i] = 0;
		y[i] = 0;

		// check from right to left
		if(x[i/10] == 1 && is_prime(i) == true)
		{
			x[i] = 1;
		}

		// check from left to right
		int t = i;
		int z = 1;
		while(t>10)
		{
			z *= 10;
			t /= 10;
		}
		t = i%z;
		if(y[t] == 2 && is_prime(i) == true)
		{
			y[i] = 2;
		}

		if(x[i] == 1 && y[i] == 2)
		{
			count++;
			sum += i;
			if(count==11)
			{
				cout << sum << endl;
				break;
			}
		}
	}
}
