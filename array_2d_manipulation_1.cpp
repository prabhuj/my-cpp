/* Modify a boolean matrix such that if a matrix cell X[i][j] is 1, make all the cells of i-th row and j-th column as 1 */

#include <iostream>

using namespace std;

void print_array(bool X[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout << X[i][j] << " ";
		cout << endl;
	}
}

void manipulate_array(bool X[5][5])
{
	bool row = 0;
	bool col = 0;
	for(int j=0;j<5;j++)
	{
		if(X[0][j] == 1)
		{
			row = 1;
			break;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(X[i][0] == 1)
		{
			col = 1;
			break;
		}
	}

	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(X[i][j] == 1)
			{
				X[0][j] = 1;
				X[i][0] = 1;
			}
		}
	}

	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(X[0][j] == 1 || X[i][0] == 1)
			{
				X[i][j] = 1;
			}
		}
	}

	if(row == 1)
		for(int j=1;j<5;j++)
			X[0][j] = 1;
	if(col == 1)
		for(int i=1;i<5;i++)
			X[i][0] = 1;
}

int main()
{
	bool X[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
	};

	cout << "INPUT" << endl;
	print_array(X);
	manipulate_array(X);
	cout << "OUTPUT" << endl;
	print_array(X);

	return 0;
}
