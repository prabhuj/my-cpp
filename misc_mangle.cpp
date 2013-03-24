#include <iostream>

using namespace std;

int mangle(int a, int b)
{
	cout << a << " :: " << b << endl;
	int c = a/2;
	if(b <= 1) return a;
	return a * (b-2*c) + mangle(a/2,c);
}

int main()
{
	for(int i=1; i<= 5; i++)
		cout << mangle(i+1,i-1) << endl;
}

