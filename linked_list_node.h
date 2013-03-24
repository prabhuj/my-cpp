#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

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
	cout << "HEAD -> ";
	while(head)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

nodeptr new_node(int data)
{
	nodeptr new_node = new node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void delete_list(nodeptr head)
{
	while(head)
	{
		nodeptr tmp = head->next;
		delete(head);
		head = tmp;
	}
}

void append(nodeptr head, int data)
{
	cout << __FILE__ << __LINE__ << endl;
	if(head == NULL)
	{
		head = new_node(data);
		return;
	}

	while(head->next)
	{
		head = head->next;
	}

	nodeptr tmp = new_node(data);
	head->next = tmp;
}

#endif // _LIST_NODE_H_
