#include <iostream>
#include <vector>

using namespace std;

struct holder
{
	int i;
	int j;
	int prod;
	int sum;
};

typedef struct holder holder;

int main()
{
	vector<holder> my_holder;

	for(int i=2;i<=100;i++)
	{
		for(int j=i;j<=100-i;j++)
		{
			holder tmp;
			tmp.i = i;
			tmp.j = j;
			tmp.prod = i*j;
			tmp.sum = i+j;
			my_holder.push_back(tmp);
		}
	}

	cout << my_holder.size() << endl;

	for (vector<holder>::iterator itr1 = my_holder.begin() ; itr1 != my_holder.end(); ++itr1)
	{
		for (vector<holder>::iterator itr2 = my_holder.begin() ; itr2 != my_holder.end(); ++itr2)
		{
					{
		}
		}
    		std::cout << ' ' << *itr1;
	}

	cout << my_holder.size() << endl;

	return 0;
}
