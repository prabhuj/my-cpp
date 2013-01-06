#include <iostream>
#include <vector>

#define LIMIT 1000000

bool is_prime(int x)
{
	int s = (int)sqrt(x);
	for(int i=2;i<=s;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	int result_cnt = 0, result_num = 0, result_prime = 0;;
	vector<int> x;
	vector<int> p(LIMIT,0);
	int cnt = 0;
	for(int i=2;i<LIMIT;i++)
	{
		if(is_prime(i)==true)
		{
			x.push_back(i);
			p[i] = 1;
			cnt++;
		}
	}
	for(vector<int>::iterator itr=x.begin();itr!=x.end();itr++)
		cout << *itr << " ";
	cout << endl;
	cout << cnt << endl;

	for(int i=0;i<x.size()-1;i++)
	{
		cout << "considering " << x[i] << endl;
		int sum = x[i];
		int cnt = 1;
		for(int j=i+1;j<x.size();j++)
		{
			sum += x[j];
			cnt++;
			if(sum > x[x.size()-1])
			{
				break;
			}
			else if(p[sum] == 1)
			{
				cout << "combination :: " << sum << " :: count " << cnt << endl;
				if(result_cnt < cnt)
				{
					result_cnt = cnt;
					result_prime = sum;
					result_num = x[i];
				}
			}
			// else - continue
		}
	}
	cout << result_prime << " <===> " << result_cnt << " numbers starting at " << result_num << endl;
}

/*
build a matrix as like
if i<j = 0
if i=j = i or j
if i>j = (i,j-1) + (j,j)
	2	3	5	7	11	13	17
2	2	5	10	17	28	41	58
3	0	3	8	15	26	39	56
5	0	0	5	12	23	36	53
7	0	0	0	7	18	31	48
11	0	0	0	0	11	24	41
13	0	0	0	0	0	13	30
17	0	0	0	0	0	0	17

need to maintain a seperate array having value as 1 for prime
*/
