#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

int find_nth_node(nodeptr head, int n)
{
	while(head && n > 0)
	{
		if(1 == n)
			return head->data;
		head = head->next;
		n--;
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

	cout << find_nth_node(&E, -1) << endl;
	cout << find_nth_node(&E, 0) << endl;
	cout << find_nth_node(&E, 1) << endl;
	cout << find_nth_node(&E, 2) << endl;
	cout << find_nth_node(&E, 3) << endl;
	cout << find_nth_node(&E, 4) << endl;
	cout << find_nth_node(&E, 5) << endl;
	cout << find_nth_node(&E, 6) << endl;
	cout << find_nth_node(&E, 7) << endl;

	return 0;
}
