/*
Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?
http://www.geeksforgeeks.org/archives/110
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

void delete_node(nodeptr n)
{
	if(n && n->next)
	{
		n->data = n->next->data;
		n->next = n->next->next;
	}
	else
	{
		cerr << "not possible" << endl;
	}
}
/*
void delete_node(node** n)
{
	print_list(*n);
	if(*n)
	{
		(*n)->data = (*n)->next->data;
		(*n)->next = (*n)->next->next;
	}
}
*/

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
