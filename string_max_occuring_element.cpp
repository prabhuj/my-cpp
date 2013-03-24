#include <iostream>

using namespace std;

void find_max(char* str)
{
	if(strlen(str) == 0) return;

	int count[256];
	fill(count, count+256, 0);

	while(*str)
	{
		count[*str]++;
		str++;
	}

	int index = 0;
	for(int i=0;i<256;i++)
	{
		if(count[index] < count[i])
		{
			index = i;
		}
	}
	cout << char(index) << " :: " << count[index] << endl;
}

int main()
{
	find_max("dhasflkahdslkjfhasdklfhadskljhajhfgklasdjhflkjadshklj");
	find_max("");
	return 0;
}
