#include <iostream>
#include <vector>
#include <algorithm>

#define TERM 1000000

int main()
{
	vector<int> vec;

	for(int i=0;i<10;i++)
	{
		vec.push_back(i);
	}

	//int cnt = 1;
	while(next_permutation(vec.begin(),vec.end()))
	{
		//cnt++;
		//if(cnt == TERM)
		//{
			copy(vec.begin(),vec.end(),ostream_iterator<int>(cout,""));
			cout << endl;
		//}
	}
}
