#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define DIGITS 100

int main()
{
	char c[DIGITS+1];
	for(int i=1;i<MAX;i++)
	{
		int n = 1;
		memset(c,0,DIGITS+1);
		int j = 0;
		//c[j++] = '0';
		//c[j++] = '.';
		for(;j<DIGITS;j++)
		{
			if(n==0)
				break;
 			else if(n==i)
			{
				c[j] = '1';
				break;
			}
			n = n*10;
			if(n<i)
			{
				c[j] = '0';
				continue;
			}
			c[j] = n/i + '0';
			n = n%i;
		}
		cout << i << " :: " << c << " :: " << j << endl;
		int itr = c[0] - '0';
		for(int k=1;k<DIGITS;k++)
		{
			if(c[k] == c[k-1])
		}
	}
}
