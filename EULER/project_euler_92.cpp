#include <iostream>

#define MAX 10000000

int main()
{
	//int x[567]; //9999999 = 7*81 = 567(max value)
	//x[1] = 1;
	//x[89] = 89;
	int cnt = 0;
	for(int i=1;i<MAX;i++)
	{
		//if(x[i] == 1)
			//continue;
		//else if(x[i] == 89)
			//cnt++;
		//else
		{
			cout << i << " = ";
			//vector<int> y;
			int sum = i;
			while(1)//sum != 89 && sum != 1)// || x[sum] == 89 || x[sum] == 1)
			{
				int t = sum;
				sum = 0;
				while(t>0)
				{
					sum = sum + (t%10)*(t%10);
					t /= 10;
				}
				cout << sum << " :: ";
				if(sum == 89)
				{
					cnt++;
					break;
				}
				else if(sum == 1)
					break;
			}
			cout << endl;
		}
	}
	cout << cnt << endl;
}
