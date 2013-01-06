#include <iostream>
#include <math.h>

#define MAX 1000

int main()
{
	int num = 0, cnt = 0;
	for(int p=3;p<=MAX;p++)
	{
		int c = 0;
		for(int i=1;i<=p-2;i++)
		{
			for(int j=i+1;j<=(p-i-1);j++)
			{
				for(int k=j+1;k<=(p-i-j);k++)
				{
					if(i+j+k==p && (k==sqrt(i*i+j*j))||(j==sqrt(i*i+k*k))||(i==sqrt(k*k+j*j)))
					{
						c++;
					}
				}
			}
		}
		if(c>cnt)
		{
			cnt = c;
			num = p;
		}
	}
	cout << num << " " << cnt << endl;
}
