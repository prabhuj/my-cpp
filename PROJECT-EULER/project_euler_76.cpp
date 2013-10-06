/*
http://en.wikipedia.org/wiki/Partition_function_(number_theory)
*/

#include <iostream>

int x[101][101];

int calculate(int n, int k)
{
	if(k>n)
		return 0;
	else if(k==n)
		return 1;
	else if(k==0)
		return 0;

	if(x[n][k] != 0)
		return x[n][k];

	x[n][k] = calculate(n-1,k-1)+calculate(n-k,k);
	return x[n][k];
}

int main()
{
	for(int n=0;n<=100;n++)
		for(int k=0;k<=100;k++)
			x[n][k] = 0;
	
	int count = 0;
	for(int i=2;i<=100;i++)
	{
		count += calculate(100,i);
	}
	cout << count << endl;
}
