/*
delete a Linked List
http://www.geeksforgeeks.org/archives/832
*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

void print_list(nodeptr head)
{
	while(head)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << endl;
}

void delete_list(nodeptr n)
{
	while(head)
	{
		nodeptr tmp = head;
		head = head->next;
		//delete tmp;
	}
}

int main()
{
	node A = {1,NULL};
	node B = {2,&A};
	node C = {3,&B};
	node D = {4,&C};
	node E = {5,&D};

	print_list(&E);
	delete_node(&A);
	//nodeptr head = &C;
	//delete_node(&head);
	print_list(&E);

	return 0;
}
