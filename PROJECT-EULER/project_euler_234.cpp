#include <iostream>
#include <math.h>

bool is_prime(int n)
{
	if(n<2)
		return false;
	int s = (int)sqrt(n);
	for(int i=2;i<=s;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int lps(int n)
{
	int s = (int)sqrt(n);
	for(int i=s;i>0;i--)
	{
		if(is_prime(i))
			return i;
	}
	return -1;
}

int ups(int n)
{
	int s = (int)sqrt(n);
	if(sqrt(n) > (int)sqrt(n))
		s = s+1;
	for(int i=s;;i++)
	{
		if(is_prime(i))
			return i;
	}
	return -1;
}

bool is_semidivisible(unsigned long long n)
{
	//cout << n << " = " << lps(n) << " :: " << ups(n) << endl;
	if(n%lps(n)==0 && n%ups(n)==0)
		return false;
	else if(n%lps(n)==0)
		return true;
	else if(n%ups(n)==0)
		return true;
	else
		return false;
}

int main()
{
	unsigned long long sum = 0;
	//for(unsigned long long i=4;i<999966663333ull;i++)
	for(unsigned long long i=4;i<100;i++)
	{
		if(is_semidivisible(i))
		{
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum << endl;
}
