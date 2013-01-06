#include <iostream>

#define MAX 100

int nCr(int n, int r)
{
	r = (r<(n-r))?r:n-r;
	int a[r], b[r];

	for(int i=0;i<r;i++)
	{
		a[i] = n-i;
		//cout << a[i] << " ";
	}
	//cout << endl;
	for(int j=0;j<r;j++)
	{
		b[j] = r-j;
		//cout << b[j] << " ";
	}
	//cout << endl;

	for(int j=0;j<r;j++)
	{
		if(b[j]==1)
			break;
		for(int i=0;i<r;i++)
		{
			if(a[i]%b[j]==0)
			{
				a[i] = (a[i]/b[j]);
				b[j] = 1;
				break;
			}
		}
	}

/*
	for(int i=0;i<r;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for(int j=0;j<r;j++)
	{
		cout << b[j] << " ";
	}
	cout << endl;
*/

	unsigned long long den = 1;
	for(int j=0;j<r;j++)
	{
		den *= b[j];
	}
	//cout << "den :: " << den << endl;
	unsigned long long num = 1;
	for(int i=0;i<r;i++)
	{
		num *= a[i];
		//cout << "num :: " << num << endl;
		if(num/den >= 1000000)
		{
			//cout << "value crossed million" << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	int count = 0;
	for(int i=1;i<=MAX;i++)
	{
		for(int j=0;j<=i;j++)
		{
			//cout << i << "C" << j << endl;
			if(j==1 || j==i)
				continue;
			if(nCr(i,j)==true)
			{
				count++;
				cout << i << "C" << j << " is above million" << endl;
			}
		}
	}
	cout << count << endl;
}
