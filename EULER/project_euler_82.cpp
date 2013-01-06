#include <iostream>

using namespace std;

int min(int a, int b)
{
	return (a<b)?a:b;
}

int min(int a, int b, int c)
{
	return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

int main()
{
	int MAX;
	cin >> MAX;
	int a[MAX][MAX];
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			cin >> a[i][j];

	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int x[MAX][MAX];

	for(int j=0;j<MAX;j++)
	{
		for(int i=0;i<MAX;i++)
		{
			if(j==0)
				x[i][j] = a[i][j];
			else if(i==0)
				x[i][j] = a[i][j] + min(x[i][j-1],x[i+1][j-1]+a[i+1][j]);
			else if(i==MAX-1)
				x[i][j] = a[i][j] + min(x[i-1][j-1]+a[i-1][j],x[i][j-1]);
			else
				x[i][j] = a[i][j] + min(x[i-1][j-1]+a[i-1][j],x[i][j-1],x[i+1][j-1]+a[i+1][j]);
		}
	}

	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
			cout << x[i][j] << " ";
		cout << endl;
	}

	int min = x[0][MAX-1];
	for(int i=1;i<MAX;i++)
	{
		min = (x[i][MAX-1]<min)?x[i][MAX-1]:min;
	}
	cout << min << endl;
}
