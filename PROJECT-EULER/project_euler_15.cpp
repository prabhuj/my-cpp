#include <iostream>

#define GRID 20

int main()
{
	long long x[GRID][GRID+1];

	for(int i=0;i<GRID;i++)
	{
		for(int j=0;j<=GRID;j++)
		{
			if(i==0)
				x[i][j] = 1;
			else
				x[i][j] = 0;
		}
	}

	long long total_routes = 0;

	for(int i=1;i<GRID;i++)
	{
		for(int j=0;j<=GRID;j++)
		{

			for(int k=0;k<=j;k++)
				x[i][j] += x[i-1][k];

			if(i==GRID-1)
				total_routes += x[i][j];
		}
	}

	cout << total_routes << endl;
}
