#include <iostream>
#include <vector>

#define MAX 1000000

int main()
{
	for(int i=0;i<MAX;i++)
	{
		int m;
		{
			int t = i;
			vector<int> x;
			while(t>0)
			{
				x.push_back(t%10);
				t /= 10;
			}
			m = 1;
			for(int j=0;j<x.size()/2;j++)
			{
				if(x[j] != x[x.size()-1-j])
				{
					m = 0;
					break;
				}
			}
		}
		if(m==1)
		{
			int t = i;
			vector<int> x;
			while(t>0)
			{
				x.push_back(t%2);
				t /= 2;
			}
			m = 2;
			for(int j=0;j<x.size()/2;j++)
			{
				if(x[j] != x[x.size()-1-j])
				{
					m = 0;
					break;
				}
			}
		}
		if(m==2)
			cout << i << endl;
	}
}
