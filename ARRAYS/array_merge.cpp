/*
	PROBLEM: Given two arrays A[] of length N and B[] of length M+N; merge the arrays and store the results in B[]
	ALGORITHM: start comparing elements of two arrays from end i(n->0); j(m->0), which ever is greater copy it to B[k] for k(m+n->0) and decrement i or j accordingly
*/
#include <iostream>

using namespace std;

void display(int a[], int n)
{
	cout << "array = ";
	for(int i=0;i<n;i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void merge(int a[], int n, int b[], int m)
{
	for(int j=0;j<m;j++)
	{
		b[m+n-j-1] = b[m-j-1];
	}

	int i=0,j=0,k=0;
	while(i<n && j<m)
	{
		if(a[i] < b[n+j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = b[n+j];
			j++;
		}
		k++;
	}
	while(i<n)
	{
		b[k] = a[i];
		i++;
		k++;
	}
}

int main()
{
	{
		int x[] = {2,3,10};
		int y[] = {1,4,7,11,0,0,0,0};

		cout << "input x "; display(x,3);
		cout << "input y "; display(y,4);

		merge(x,3,y,4);

		cout << "output y "; display(y,7);
		cout << "------------------------------------------------"<<endl;
	}
	{
		int x[] = {1,4,7,11};
		int y[] = {2,3,10,0,0,0,0,0};

		cout << "input x "; display(x,4);
		cout << "input y "; display(y,3);

		merge(x,4,y,3);

		cout << "output y "; display(y,7);
		cout << "------------------------------------------------"<<endl;
	}
	{
		int x[] = {0,0,0,0,0,1,1,1,1,1};
		int y[] = {0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0};

		cout << "input x "; display(x,10);
		cout << "input y "; display(y,10);

		merge(x,10,y,10);

		cout << "output y "; display(y,20);
		cout << "------------------------------------------------"<<endl;
	}

	return 0;
}
