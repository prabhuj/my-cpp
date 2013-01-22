#include <iostream>

using namespace std;

int main()
{
	unsigned long long i = 0x0000001 | 0x00000002;
	cout << i << endl;
	cout << (i & (i-1)) << endl;
}
