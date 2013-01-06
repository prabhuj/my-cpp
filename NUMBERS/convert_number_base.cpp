#include <iostream>

using namespace std;

int fun(int j)
{
	if(j>0)
	{
		j = j%10 + fun(j/10);
		cout << j << " ";
	}
	return j;
}

int main()
{
	for(int i=0;i<50;i++)
	{
		cout << i << " -->";
		cout << " :: " << fun(i) << endl;;
	}
	return 0;
}
