#include <iostream>

using namespace std;

typedef struct BUS
{
	int route_no;
	char src;
	char dst;
}BUS;

bool find_bus(BUS blist[], int x, int y, char s, char d)
{
	for(int i=x;i<y;i++)
	{
		if(blist[i].src != s)
		{
			continue;
		}
		else if(blist[i].src == s && blist[i].dst == d)
		{
			cout << blist[i].route_no << " from " << s << " to " << d << endl;
			continue;
		}
		else if(blist[i].src == s)
		{
			if(find_bus(blist, i, y, blist[i].dst, d) == true)
			{
				cout << blist[i].route_no << " from " << s << " to " << blist[i].dst << " -> " << endl;
			}
			else
			{
				continue;
			}
		}
	}
	return true;
}

int main()
{
	BUS bus_list[10] = {
					{1,'A','B'},
					{2,'B','C'},
					{3,'C','D'},
					{4,'D','E'},
					{5,'A','E'},
					{6,'B','D'},
					{7,'C','E'},
					{8,'D','X'},
					{9,'B','Y'},
					{10,'A','Z'}};

	find_bus(bus_list, 0, 10, 'A', 'E');
}
