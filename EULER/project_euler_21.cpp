#include <iostream>

int main()
{
	int total = 0;
	for(int num=10000;num>1;num--)
	{
		int a_sum = 0;
		//cout << num << " = ";
		for(int j=1;j<num/2+1;j++)
		{
			if(num%j==0)
			{
				//cout << j << " ";
				a_sum += j;
			}
		}
		//cout << " = " << a_sum << " = ";

		int b_sum = 0;
		for(int j=1;j<a_sum/2+1;j++)
		{
			if(a_sum%j==0)
			{
				//cout << j << " ";
				b_sum += j;
			}
		}
		//cout << " = " << b_sum << endl;

		if(num == b_sum && num != a_sum)
		{
			cout << "AMICABLE NUMBERS :: " << num << " :: " << a_sum << endl;
			total += num;
		}
	}
	cout << total << endl;
}
