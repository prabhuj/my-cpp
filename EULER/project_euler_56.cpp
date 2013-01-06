#include <iostream>
#include <vector>

#define MAX 100

int main()
{
	//int a = 1, b = 10;
	int max_digital_sum = 0;
	for(int a=1;a<MAX;a++)
	{
		for(int b=1;b<MAX;b++)
		{
			vector<int> x;
			x.push_back(a);

			//for(int i=x.size()-1;i>=0;i--)
			//{
				//cout << x[i];
			//}
			//cout << endl;

			for(int k=0;k<b;k++)
			{
				int temp = 0;
				for(int j=0;j<x.size();j++)
				{
					int t = (x[j]*a)+temp;
					x[j] = t%10;
					temp = t/10;
				}
				while(temp>0)
				{
					x.push_back(temp%10);
					temp /= 10;
				}

				//for(int i=x.size()-1;i>=0;i--)
				//{
					//cout << x[i];
				//}
				//cout << endl;
			}
			int sum = 0;
			for(int i=x.size()-1;i>=0;i--)
			{
				sum += x[i];
			}
			cout << a << "^" << b << " = " << sum << endl;
			if(max_digital_sum < sum)
				max_digital_sum = sum;
		}
	}
	cout << max_digital_sum << endl;
}
