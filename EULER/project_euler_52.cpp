#include <iostream>

bool compare(unsigned long long x, unsigned long long y)
{
	int a[10] = {0,0,0,0,0,0,0,0,0,0};
	int b[10] = {0,0,0,0,0,0,0,0,0,0};
	while(x>0)
	{
		a[x%10]++;
		x = x/10;
	}
	while(y>0)
	{
		b[y%10]++;
		y = y/10;
	}
	for(int i=1;i<10;i++)
	{
		if(a[i] != b[i])
			return false;
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
	for(int i=1;i<142859;i++)
	{
		//int i = 142857;
		unsigned long long x_1 = i;
		unsigned long long x_6 = 6*i;
		if(get_digit_cnt(x_1) != get_digit_cnt(x_6))
			continue;
		if(compare(x_1,x_6)==true)
		{
			unsigned long long x_5 = 5*i;
			if(compare(x_1,x_5)==true)
			{
				unsigned long long x_4 = 4*i;
				if(compare(x_1,x_4)==true)
				{
					unsigned long long x_3 = 3*i;
					if(compare(x_1,x_3)==true)
					{
						unsigned long long x_2 = 2*i;
						if(compare(x_1,x_2)==true)
						{
							cout << i << endl;
							break;
						}
					}
				}
			}
		}
	}
}
