#include <iostream>
#include <vector>

int main()
{
	//int a = 9, b = 9;
	for(int a=1;a<10;a++)
	{
		vector<int> x;
		x.push_back(a);

		for(int b=1;b<9;b++)
		{
			int temp = 0;
			for(int i=0;i<x.size();i++)
			{
				x[i] = x[i] * a + temp;
				temp = x[i]/10;
				x[i] = x[i]%10;
			}

			while(temp>0)
			{
				x.push_back(temp%10);
				temp = temp/10;
			}

			if((b+1)==x.size())
			{
				cout << a << "^" << b+1 << " = ";

				for(int i=x.size()-1;i>=0;i--)
					cout << x[i];

				cout << " :: is " << x.size() << " digit positive integer" << endl;
			}
		}
	}
}
