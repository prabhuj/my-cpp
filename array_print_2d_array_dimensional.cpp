#include <iostream>

using namespace std;

void print_diagnol(int X[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout << X[i][j] << " ";
		}
		cout << endl;
	}

	int imin=0, imax=0, jmin=0, jmax=0;

	while(imin < 5 && jmin < 5)
	{
		for(int i=imax, j=jmin;i>=imin && j<=jmax;i--, j++)
		{
			cout << X[i][j] << " ";
		}
		cout << endl;
		if(imax==4 && jmax==4) {imin++;jmin++;}
		if(imin==0 && jmin==0) {imax++;jmax++;}
	}
}

int main()
{
	int X[5][5] = {
			{11,12,13,14,15},
			{21,22,23,24,25},
			{31,32,33,34,35},
			{41,42,43,44,45},
			{51,52,53,54,55}
		};

	print_diagnol(X);

	return 0;
}
