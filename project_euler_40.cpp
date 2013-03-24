#include <iostream>
#include <vector>

#define LIMIT 1000000

int get_digit_count(int num)
{
	int cnt = 0;
	while(num>0)
	{
		cnt++;
		num /= 10;
	}
	return cnt;
}

int get_digit_at_pos(int pos, int num)
{
	vector<int> vec;
	while(num>0)
	{
		vec.push_back(num%10);
		num /= 10;
	}
	return vec[vec.size()-pos];
}

int main()
{
	int result = 1;
	int index = 1;
	int positive_integer=1;

	for(int new_pos = 0; index < LIMIT; positive_integer++)
	{
		int prev_pos = new_pos;
		new_pos += get_digit_count(positive_integer);

		if(index >= prev_pos+1 && index <= new_pos)
		{
			result *= get_digit_at_pos(index-prev_pos,positive_integer);
			index = index*10;
		}
	}

	cout << result << endl;

	return 0;
}
