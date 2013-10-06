#include <iostream>

using namespace std;

void reverse_int(int num)
{
	cout << num << " ==> ";
	long result = 0;
	while(num)
	{
		result = (result*10) + (num%10);
		if(result > INT_MAX || result < INT_MIN)
		{
			cout << "can not reverse" << endl;
			return;
		}
		num = num/10;
	}
	cout << result << endl;
}

int main()
{
	reverse_int(0);
	reverse_int(2);
	reverse_int(0001);
	reverse_int(1000);
	reverse_int(1234);
	reverse_int(-1234);
	reverse_int(-12345);
	reverse_int(INT_MIN);
	reverse_int(INT_MAX);
	return 0;
}
