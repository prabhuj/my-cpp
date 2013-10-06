#include <iostream>

using namespace std;

void find_ways(int *den, int n, int sum)
{
	int X[sum+1][n];
	for(int i=0;i<sum+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			X[i][j] = 0;
			//cout << X[i][j] << " ";
		}
		//cout << endl;
	}

	for(int i=1;i<sum+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<den[j] && i%den[j] == 0)
			{
				X[i][j] = 1;
			}
		}
	}

	for(int i=0;i<sum+1;i++) { for(int j=0;j<n;j++) { cout << X[i][j] << " "; } cout << endl; }
}

int main()
{
	int den[4] = {1,2,5,10};
	find_ways(den, 4, 10);
	return 0;
}
