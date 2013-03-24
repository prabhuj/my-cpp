#include <iostream>
#include <vector>

#define AMIN 2
#define AMAX 100
#define BMIN 2
#define BMAX 100

int main()
{
	for(int a=AMIN;a<=AMAX;a++)
	{
		for(int b=BMIN;b<=BMAX;b++)
		{
			vector<int> x;

			x.push_back(a);

			for(int i=1;i<b;i++)
			{
				int t = 0;
				for(int j=0;j<x.size();j++)
				{
					x[j] = x[j]*a + t;
					t = x[j]/10;
					x[j] = x[j]%10;
				}
				while(t>0)
				{
					x.push_back(t%10);
					t /= 10;
				}
			}
			//cout << a << "^" << b << " = ";
			for(int j=x.size()-1;j>=0;j--)
			{
				cout << x[j];
			}
			cout << endl;
		}
	}
}
