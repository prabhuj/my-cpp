#include <iostream>
#include <math.h>

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

bool is_square(int x)
{
	double d = sqrt(x);
	int    i = static_cast<int>(d);
	if(i==d)
		return true;
	else
		return false;
}

int main()
{
	for(int i=5;i<6000;i+=2)
	{
		cout << "traversing :: " << i << endl;
		bool odd_composite = false;
		for(int j=i-2;j>1;j--)
		{
			if(is_prime(j)==true)
			{
				int k = i-j;
				k = k/2;
				if(is_square(k) == true)
				{
					cout << i << " = " << j << " + 2x" << k << endl;
					odd_composite = true;
					break;
				}
			}
		}
		if(odd_composite == true)
			continue;
		cout << "RESULT :: " << i-2 << endl;
		break;
	}
}
