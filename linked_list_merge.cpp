#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node node;
typedef struct node* nodeptr;

void display(nodeptr head)
{
	cout << "HEAD";
	while(head != NULL)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

nodeptr merge_list_iterative(nodeptr list1, nodeptr list2)
{
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;

	nodeptr new_head = NULL;
	if(list1->data < list2->data)
	{
		new_head = list1;
		list1 = list1->next;
	}
	else
	{
		new_head = list2;
		list2 = list2->next;
	}
	nodeptr tmp = new_head;
	while(list1 && list2)
	{
		if(list1->data < list2->data)
		{
			tmp->next = list1;
			list1 = list1->next;
		}
		else
		{
			tmp->next = list2;
			list2 = list2->next;
		}
		tmp = tmp->next;
	}
	if(list1)
	{
		tmp->next = list1;
	}
	if(list2)
	{
		tmp->next = list2;
	}
	return new_head;
}

nodeptr merge_list_recursive(nodeptr list1, nodeptr list2)
{
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;

	if(list1->data < list2->data)
	{
		list1->next = merge_list_recursive(list1->next, list2);
		return list1;
	}
	else
	{
		list2->next = merge_list_recursive(list1, list2->next);
		return list2;
	}
}

int main()
{
	node a1 = {20,NULL};
	node b1 = {19,&a1};
	node c1 = {18,&b1};
	node d1 = {17,&c1};
	node e1 = {16,&d1};
	node f1 = {15,&e1};
	node g1 = {14,&f1};
	node h1 = {13,&g1};
	node i1 = {12,&h1};
	node k1 = {11,&i1};
	nodeptr list1 = &k1;

	node a2 = {30,NULL};
	node b2 = {29,&a2};
	node c2 = {28,&b2};
	node d2 = {27,&c2};
	node e2 = {26,&d2};
	node f2 = {25,&e2};
	node g2 = {24,&f2};
	node h2 = {23,&g2};
	node i2 = {22,&h2};
	node k2 = {21,&i2};
	nodeptr list2 = &k2;

	display(list1);
	display(list2);

	nodeptr list3 = merge_list_iterative(list1, list2);

	display(list1);
	display(list2);
	display(list3);

	return 0;
}
