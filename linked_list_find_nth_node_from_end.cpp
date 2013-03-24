#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

int find_nth_node_from_end(nodeptr head, int n)
{
	nodeptr head_itr = head;
	nodeptr tail_itr = head;

	while(head_itr && n)
	{
		head_itr = head_itr->next;
		--n;
	}

	if(n)
		return -1;
	else
	{
		while(head_itr)
		{
			head_itr = head_itr->next;
			tail_itr = tail_itr->next;
		}
		if (tail_itr)
			return tail_itr->data;
	}
	return -1;
}

int main()
{
	node A = {5,NULL};
	node B = {4,&A};
	node C = {3,&B};
	node D = {2,&C};
	node E = {1,&D};

	cout << find_nth_node_from_end(&E, -1) << endl;
	cout << find_nth_node_from_end(&E, 0) << endl;
	cout << find_nth_node_from_end(&E, 1) << endl;
	cout << find_nth_node_from_end(&E, 2) << endl;
	cout << find_nth_node_from_end(&E, 3) << endl;
	cout << find_nth_node_from_end(&E, 4) << endl;
	cout << find_nth_node_from_end(&E, 5) << endl;
	cout << find_nth_node_from_end(&E, 6) << endl;
	cout << find_nth_node_from_end(&E, 7) << endl;
	cout << find_nth_node_from_end(&E, 8) << endl;
	cout << find_nth_node_from_end(&E, 9) << endl;

	return 0;
}
