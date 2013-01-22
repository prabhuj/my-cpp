#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

void print_list_iterative(nodeptr head)
{
	cout << "HEAD ";
	while(head)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

void print_list_recursive(node* list)
{
	if(!list)
	{
		cout << "NULL" << endl;
		return;
	}
	cout << list->data << " -> ";
	print_list_recursive(list->next);
}

int main()
{
	node E = {5,NULL};
	node D = {4,&E};
	node C = {3,&D};
	node B = {2,&C};
	node A = {1,&B};

	nodeptr head = &A;

	print_list_iterative(head);
	print_list_recursive(head);
	print_list_iterative(head);
	print_list_recursive(head);
	print_list_iterative(head);

	return 0;
}
