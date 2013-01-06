#include <iostream>
#include <vector>
#include <algorithm>

int is_prime(int x)
{
	int s = (int)sqrt(x);
	for(int i=2;i<=s;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	int p[9877];
	for(int i=1234;i<9877;i++)
	{
		p[i] = is_prime(i);
	}

	for(int i=1;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			for(int k=j+1;k<10;k++)
			{
				for(int l=k+1;l<10;l++)
				{
					int c = 0;
					vector<int> x;
					x.push_back(i);
					x.push_back(j);
					x.push_back(k);
					//cout << i << j << k << l << " = ";
					x.push_back(l);
					do {
						int num = 0;
						for(vector<int>::iterator itr=x.begin();itr!=x.end();itr++)
							num = num*10 + (*itr);
						//int num = (x[0])+(x[1])+(x[2])+(x[3]);
						if(p[num] == 1)
							c++;
						//cout << num << "[" << c << "] :: ";
					} while(next_permutation(x.begin(),x.end()));
					cout << i << j << k << l << " = " << c << endl;
					//cout << endl;
				}
			}
		}
	}
}
