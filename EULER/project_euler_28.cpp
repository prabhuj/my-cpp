#include <iostream>

#define SIZE 1001
int main()
{
	int sum = 0;

	for(int i=1;i<=SIZE;i++)
	{
		if(i%2 == 0)
			sum += ((i*i)+1);
		else
			sum += (i*i);
	}

	for(int i=2;i<=SIZE;i++)
	{
		sum += ((i*i)-(i-1));
	}

	cout << sum << endl;
}
