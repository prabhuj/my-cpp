#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

void display(nodeptr head)
{
	while(head)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

nodeptr reverse_k(nodeptr head, int k)
{
	if(!head) return head;

	nodeptr org_head = head;
	nodeptr new_head = NULL;
	nodeptr new_tail = NULL;
	int count = k;
	while(head && count)
	{
		nodeptr tmp = head->next;
		head->next = new_head;
		new_head = head;
		head = tmp;
		new_tail = tmp;
		--count;
	}

	cout << "org_head  ==> "; display(org_head);
	cout << "new_head  ==> "; display(new_head);
	cout << "new_tail  ==> "; display(new_tail);

	nodeptr new_tail_rev = reverse_k(new_tail, k);

	org_head->next = new_tail_rev;

	return new_head;
}

int main()
{
	node node10 = {10,NULL};
	node node9 = {9,&node10};
	node node8 = {8,&node9};
	node node7 = {7,&node8};
	node node6 = {6,&node7};
	node node5 = {5,&node6};
	node node4 = {4,&node5};
	node node3 = {3,&node4};
	node node2 = {2,&node3};
	node node1 = {1,&node2};

	cout << "inp_head  ==> "; display(&node1);

	nodeptr rev = reverse_k(&node1, 3);

	cout << "out_head  ==> "; display(rev);

	return 0;
}
