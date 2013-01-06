#include <iostream>

int main()
{
	//int i=39,j=186,k=7254;
	//for(int i=12;i<=98;i++)
	for(int i=2;i<=98;i++)
	{
		//for(int j=123;j<=987;j++)
		for(int j=i+1;j<=9876;j++)
		{
			for(int k=1234;k<=9876;k++)
			{
				int sum = 0;
				int product = 1;
				if(i*j==k)
				{
					int a=i,b=j,c=k;
					while(a>0)
					{
						sum += a%10;
						product *= a%10;
						a /= 10;
					}
					while(b>0)
					{
						sum += b%10;
						product *= b%10;
						b /= 10;
					}
					while(c>0)
					{
						sum += c%10;
						product *= c%10;
						c /= 10;
					}
					//cout << sum << endl;
					//cout << product << endl;
					if(sum == 45 && product == 362880)
					{
						cout << i << ":" << j << ":" << k << endl;
					}
				}
			}
		}
	}
}
