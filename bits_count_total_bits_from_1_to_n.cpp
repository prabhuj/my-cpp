#include <iostream>

using namespace std;

void count_bits(int num)
{
	int period = 2;
	int bit_cnt = 0;

	int num_dup = num;

	while(num_dup)
	{
		bit_cnt += (num/period)*(period>>1);
        	if( (num & (period-1)) > (period>>1)-1)
			bit_cnt += (num&period-1)) - (period>>1)+1;
		period = period << 1;
		num_dup = num_dup >> 1;
	}
}

int main()
{
	count_bits(1);
	return 0;
}
