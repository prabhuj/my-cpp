#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
}nodeptr;

void print(node* head)
{
	node* tmp = head;
	while(tmp != NULL)
	{
		cout << " -> " << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}

node* reverse(node* head)
{
	node* new_head = NULL;
	while(head != NULL)
	{
		node* next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	return new_head;
}

node* reverse_by_block(node* head, int block)
{
	if(head == NULL)
		return head;

	node* tmp = head;
	node* new_head = head;
	node* new_tail = NULL;

	int count = block;
	while(tmp != NULL && count--)
	{
		new_tail = tmp;
		tmp = tmp->next;
	}

	new_tail->next = NULL;

	//cout << "1--------------------------------" << endl; print(new_head); print(new_tail); print(tmp);

	new_tail = new_head;
	new_head = reverse(new_head);
	new_tail->next = reverse_by_block(tmp,block);

	return new_head;
}

int main()
{
	node a = {1,NULL};
	node b = {2,&a};
	node c = {3,&b};
	node d = {4,&c};
	node e = {5,&d};
	node f = {6,&e};
	node g = {7,&f};
	node h = {8,&g};
	node i = {9,&h};
	node k = {10,&i};
	node *list = &k;

	print(list);

	list = reverse_by_block(list, 4);

	print(list);
}
