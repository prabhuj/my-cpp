#include <iostream>

#define LIMIT 999

int main()
{
	int n_3 = LIMIT/3;
	int n_5 = LIMIT/5;
	int n_15 = LIMIT/15;

	cout << (3*(n_3*(n_3+1)/2)) + (5*(n_5*(n_5+1)/2)) - (15*(n_15*(n_15+1)/2)) << endl;
}
