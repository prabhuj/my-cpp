/*
------------
  |1 |2 |3 |
------------
1 |1 |3 |6 |
2 |3 |9 |18|
3 |6 |18|36|
------------

for(x,y)
	if x=0, z = (x,y-1)+y
	if y=0, z = x+(x-1,y)
	else,   z = x*y;
*/

#include <iostream>

#define MAX 100

int main()
{
	int x[MAX][MAX];

	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(i==0 && j==0)
				x[i][j] = 1;
			else if(i==0)
				x[i][j] = x[i][j-1]+j+1;
			else if(j==0)
				x[i][j] = x[i-1][j]+i+1;
			else
				x[i][j] = x[i][0] * x[0][j];

			if(x[i][j] >= 2000000)
			{
				cout << "Solution is :: Dimensions [" << i+1 << " x " << j+1 << "] Rectangles :: [" << x[i][j] << "] Area :: [" << (i+1)*(j+1) << "]" << endl;
				return 0;
			}
			//cout << x[i][j] << " ";
		}
		//cout << endl;
	}
}
