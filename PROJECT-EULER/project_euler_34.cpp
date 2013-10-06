#include <iostream>

#define MAX 100000000

int main()
{
	int x[10] = {1,1,2,6,24,120,720,5040,40320,362880};
	for(unsigned long long i=3;i<MAX;i++)
	{
		unsigned long long t = i;
		unsigned long long sum = 0;
		while(t>0)
		{
			sum = sum + x[t%10];
			t /= 10;
		}
		if(i==sum)
			cout << i << endl;
	}
}
