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
	cout << "HEAD";
	while(head)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

nodeptr reverse_iteration(nodeptr head)
{
	nodeptr new_head = NULL;
	while(head)
	{
		nodeptr tmp = head->next;
		head->next = new_head;
		new_head = head;
		head = tmp;
	}
	return new_head;
}

nodeptr reverse_recursion(nodeptr head)
{
	if(head == NULL || head->next == NULL)
		return head;

	nodeptr new_head = reverse_recursion(head->next);

	head->next->next = head;

	head->next = NULL;

	return new_head;
}

int main()
{
	node E = {5,NULL};
	node D = {4,&E};
	node C = {3,&D};
	node B = {2,&C};
	node A = {1,&B};

	nodeptr head = &A;

	print_list(NULL);
	print_list(head);
	head = reverse_iteration(head);
	print_list(head);
	head = reverse_recursion(head);
	print_list(head);
	head = reverse_iteration(head);
	print_list(head);
	head = reverse_recursion(head);
	print_list(head);

	return 0;
}
