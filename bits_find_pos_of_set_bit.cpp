#include <iostream>

using namespace std;

int find_pos(int num)
{
	if(!(num & (num-1)))
	{
		unsigned int pos = 0;
		while(num)
		{
			pos++;
			num = num >> 1;
		}
		return pos;
	}
	return -1;
}

int main()
{
	for(int i=0;i<20;i++)
		cout << i << " :: " << find_pos(i) << endl;
	return 0;
}
