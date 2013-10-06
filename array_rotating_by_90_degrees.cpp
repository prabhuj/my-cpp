#include <iostream>

#define N 3

using namespace std;

void print_rotated_array(int X[N][N])
{
	for(int i=0;i<N;i++) { for(int j=0;j<N;j++) { cout << X[i][j] << " "; } cout << endl; }

	int x_t = N-1;
	int y_t = N-1;

	for(int i=0;i<x_t;i++)
	{
		for(int j=0;j<y_t;j++)
		{
			cout << "(" << 9 << "," << 9 << ") <= (" << i << ","<< j << ")" << std::endl;
			cout << "(" << i << "," << j << ") <= (" << i << ","<< j+y_t << ")" << std::endl;
			cout << "(" << i << "," << j+y_t << ") <= (" << i+x_t << ","<< j+y_t << ")" << std::endl;
			cout << "(" << i+x_t << "," << j+y_t << ") <= (" << i+x_t << ","<< j << ")" << std::endl;
			cout << "(" << i+x_t << "," << j << ") <= (" << 9 << ","<< 9 << ")" << std::endl;
		}
	}

	return;
	//for(int i=0;i<x_t;i++)
	{
		//for(int j=0;j<x_t;j++)
		{
    //a[x,y] = a[y,n-1-x]
    //a[y,n-1-x] = a[n-1-x,n-1-y]
    //a[n-1-x,n-1-y] = a[n-1-y,x]
    //a[n-1-y,x] = temp
			int i=0, j=0;
			int t = X[i][j];
			X[i][j] = X[i][j+y_t];
			X[i][j+y_t] = X[i+x_t][j+y_t];
			X[i+x_t][j+y_t] = X[i+x_t][j];
			X[i+x_t][j] = t;
		}
	}

	for(int i=0;i<N;i++) { for(int j=0;j<N;j++) { cout << X[i][j] << " "; } cout << endl; }
}

int main()
{
	int X[N][N] = {
			{11,12,13},
			{21,22,23},
			{31,32,33}
		};

	print_rotated_array(X);

	return 0;
}
