#include <iostream>

using namespace std;

typedef unsigned long long ullong;

int main()
{
	ullong a = 17360190137181430ull;
	ullong b = 17293822569102704640ull;
	ullong c = 9223372036854775808ull;

	cout << (a&b) << endl;

	return 0;
}
