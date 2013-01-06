#include <iostream>
#include <vector>

#define MAX 10000

int lychrel[MAX];

int inverse(int x)
{
	int y = 0;
	while(x>0)
	{
		y = y*10 + x%10;
		x /= 10;
	}
	return y;
}

bool is_palindrome(int num)
{
	vector<int> x;
	while(num>0)
	{
		x.push_back(num%10);
		num /= 10;
	}
	for(int i=0;i<x.size()/2;i++)
	{
		if(x[i] != x[x.size()-i-1])
		{
			return false;
		}
	}
	return true;
}

bool iterate_until_palindrome(int num)
{
	//cout << "num :: " << num << endl;
	vector<int> x;
	int dup = num;
	while(dup>0)
	{
		x.push_back(dup%10);
		dup /= 10;
	}

	int itr = 0;
	while(1)
	{
		if(itr++ == 50)
			return false;
		vector<int> y = x;
		for(int i=x.size()-1;i>=0;i--)
		{
			//cout << x[i];
		}
		//cout << " + ";
		for(int i=0;i<y.size();i++)
		{
			//cout << y[i];
		}
		//cout << " = ";
		int t = 0;
		for(int i=0;i<x.size();i++)
		{
			x[i] = y[i] + y[y.size()-i-1] + t;
			t = x[i]/10;
			x[i] = x[i]%10;
		}
		while(t>0)
		{
			x.push_back(t%10);
			t /= 10;
		}
		for(int i=x.size()-1;i>=0;i--)
		{
			//cout << x[i];
		}
		//cout << endl;

		//cout << "size :: " << x.size() << endl;
		bool palindrome = true;
		for(int i=0;i<x.size()/2;i++)
		{
			//cout << x[i] << "::" << x[x.size()-i-1] << endl;
			if(x[i] != x[x.size()-i-1])
			{
				palindrome = false;
				break;
			}
		}
		if(palindrome==true)
		{
			//cout << endl << num << " took " << itr << " iterations " << endl;
			return true;
		}
	}
}

int main()
{
	int sum_of_non_lychrels = 0;
	for(int i=MAX-1;i>0;i--)
	{
		if(iterate_until_palindrome(i) == true)
		{
			//cout << i << " is lychrel" << endl;
		}
		else
		{
			if(is_palindrome(i)==true)
				cout << i << " is non lychrel palindrome" << endl;
			else
				//cout << i << " is non lychrel" << endl;
			sum_of_non_lychrels += i;
		}
	}
	cout << sum_of_non_lychrels << endl;
}
