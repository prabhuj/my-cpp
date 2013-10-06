#include <iostream>

#define LIMIT 4000000

int main()
{
	long long sum = 0;

	long long f_n_2 = 0;
	long long f_n_1 = 1;

	while(f_n_1<LIMIT)
	{
		long long f_n = f_n_1 + f_n_2;

		if(f_n%2==0)
			sum += f_n;

		f_n_2 = f_n_1;
		f_n_1 = f_n;

	}

	cout << sum << endl;
}
