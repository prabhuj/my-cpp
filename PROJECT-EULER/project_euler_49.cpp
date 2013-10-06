#include <iostream>
#include <vector>
#include <algorithm>

bool is_permutation(int x, int y)
{
	int z = 0;
	while(x>0) {
		z = z^(x%10);
		x /= 10;
	}
	while(y>0) {
		z = z^(y%10);
		y /= 10;
	}
	if(z==0)
		return true;
	return false;
}

int is_prime(int x)
{
	int s = (int)sqrt(x);
	for(int i=2;i<=s;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	unsigned int a,b,c;
	for (a=1000; a<=3340 /* 10000-3330-3330 */ ; a++)
	{
		if (a==1487)
			continue;
 
		b = a+3330;
		c = b+3330;
 
		if (is_prime(a) && is_prime(b) && is_prime(c) && is_permutation(a,b) && is_permutation(b,c))
		{
			std::cout << a << b << c << std::endl;		
			break;
		}
	}
}
