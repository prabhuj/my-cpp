#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

bool is_prime(int x)
{
	int s = (int)sqrt(x);
	for(int i=2;i<=s;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	vector<int> x;
	for(int i=1;i<10;i++)
	{
		x.push_back(i);
	}

	int result = 0;
	int check_sum = 45;
	int check_prod = 362880;
	for(int i=9;i>1;i--)
	{
		do
		{
			int num = 0;
			int sum = 0;
			int prod = 1;
			for(vector<int>::iterator itr=x.begin();itr!=x.end();itr++)
			{
				num = num*10 + (*itr);
				sum += *itr;
				prod *= *itr;
			}
			cout << num << " :: " << sum << " :: " << prod << endl;
			if(sum == check_sum && prod == check_prod && is_prime(num) == true)
			{
				//cout << num << endl;
				if(result<num)
					result = num;
				//return 0;
			}
		}while(next_permutation(x.begin(),x.end()));
		check_sum -= x.back();
		check_prod /= x.back();
		x.pop_back();
	}
	cout << result << endl;
}
