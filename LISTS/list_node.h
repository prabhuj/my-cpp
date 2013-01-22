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
	std::cout << "HEAD -> ";
	while(head)
	{
		std::cout << head->data << " -> ";
		head = head->next;
	}
	std::cout << "NULL" << std::endl;
}

#endif // _LIST_NODE_H_
