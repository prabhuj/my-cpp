#include <iostream>
#include <vector>
#include <algorithm>

#define LIMIT 1000000

bool is_prime(long long num)
{
	long long x = (long long)sqrt(num);

	for(long long i=2;i<=x;i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	return true;
}

bool check(int x, int y)
{
	int div = 1;
	for(int i=1;i<y;i++)
		div *= 10;
	//cout << x << " :: " << y << " :: " << div << endl;
	while(y--)
	{
		int k = x/div;
		x = ((x%div)*10) + k;
		if(is_prime(x) == false)
			return false;
		//cout << "sub :: " << x << endl;
	}

	return true;
}

int get_digit_cnt(int x)
{
	int a=0;
	while(x>0)
	{
		x=x/10;
		a++;
	}
	return a;
}
int main()
{
	int cnt = 0;
	for(int i=2;i<LIMIT;i++)
	{
		cout << "--------------------iterating " << i << endl;
		//cout << get_digit_cnt(i) << endl;
		if(check(i,get_digit_cnt(i))==true)
		{
			cout << i << " is all prime" << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
}
