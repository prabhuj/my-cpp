#include <iostream>
#include <math.h>

#define MAX 999999

int main()
{
	long long sum_all = 0;
	for(int num_itr=10;num_itr<MAX;num_itr++)
	{
		long long sum = 0;
		int num = num_itr;

		while(num)
		{
			int digit = num%10;
			sum += (long long)pow(digit,5);
			num = num/10;
		}

		if(sum == num_itr)
		{
			sum_all += sum;
		}
	}
	cout << sum_all << endl;
}
