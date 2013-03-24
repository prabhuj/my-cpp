#include <iostream>

using namespace std;

unsigned int swap_bits(int x)
{
	return (((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1));
}

int main()
{
	unsigned int x = 23;
	cout << swap_bits(x) << endl;
	return 0;
}
