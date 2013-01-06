#include <iostream>

int main()
{
	for(int i=2;i<=9876;i++)
	{
		int sum = 0;
		int prod  = 1;
		for(int j=1;j<10;j++)
		{
			int t = i*j;
			while(t>0)
			{
				sum += t%10;
				prod *= t%10;
				t /= 10;
			}
			if(sum == 45 && prod == 362880)
			{
				cout << i << " :: 1 to " << j << " :: ";
				for(int k=1;k<=j;k++)
					cout << i*k;
				cout << endl;
			}
			else if(sum > 45 || prod > 362880)
				break;
		}
	}
}
