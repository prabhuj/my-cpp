#include <iostream>
#include <map>

int main()
{
	map<int,int> x;

	for(int n=1;n<100;n++)
	{
		int p = n*((3*n)-1)/2;
		x[p] = 1;
	}
}
