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
	cout << "HEAD -> ";
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
	int count = k;
	while(head && count)
	{
		nodeptr tmp = head->next;
		head->next = new_head;
		new_head = head;
		head = tmp;
		--count;
	}

	org_head->next = reverse_k(head, k);

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

	nodeptr rev = &node1;

	display(rev);
	rev = reverse_k(rev, 1); display(rev); rev = reverse_k(rev, 1);
	rev = reverse_k(rev, 2); display(rev); rev = reverse_k(rev, 2);
	rev = reverse_k(rev, 3); display(rev); rev = reverse_k(rev, 3);
	rev = reverse_k(rev, 4); display(rev); rev = reverse_k(rev, 4);
	rev = reverse_k(rev, 5); display(rev); rev = reverse_k(rev, 5);
	rev = reverse_k(rev, 6); display(rev); rev = reverse_k(rev, 6);
	rev = reverse_k(rev, 7); display(rev); rev = reverse_k(rev, 7);
	rev = reverse_k(rev, 8); display(rev); rev = reverse_k(rev, 8);
	rev = reverse_k(rev, 9); display(rev); rev = reverse_k(rev, 9);
	rev = reverse_k(rev, 10); display(rev); rev = reverse_k(rev, 10);
	rev = reverse_k(rev, 11); display(rev); rev = reverse_k(rev, 11);

	return 0;
}
