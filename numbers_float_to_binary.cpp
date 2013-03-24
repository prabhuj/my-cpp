#include <iostream>
#include <bitset>

using namespace std;

union data
{
	float input;
	int output;
};

int main()
{
	union data x;
	x.input = 0.1; // 2.25125;
	bitset<sizeof(float) * CHAR_BIT> bits(x.output);
	cout << x.input << endl;
	cout << x.output << endl;
	cout << bits << endl;
}
