#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node node;
typedef struct node* node_ptr;
typedef struct node** node_ptr_ref;

void print_list(node_ptr head)
{
	cout << "HEAD";
	while(head)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

node_ptr get_new_node(int data)
{
	node_ptr new_node = new node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void reverse_list(node_ptr_ref head_ref)
{
	node_ptr new_head = NULL;
	node_ptr head = (*head_ref);
	while(head)
	{
		node_ptr tmp = head->next;
		head->next = new_head;
		new_head = head;
		head = tmp;
	}
	(*head_ref) = new_head;
}

void delete_list(node_ptr_ref head_ref)
{
	while((*head_ref))
	{
		node_ptr tmp = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		delete tmp;
	}
/*
	node_ptr tmp1 = (*head_ref);
	while(tmp1)
	{
		print_list(tmp1);
		node_ptr tmp2 = tmp1->next;
		tmp2->next = NULL;
		delete tmp1;
		tmp1 = tmp2;
	}
	(*head_ref) = NULL;
*/
}

void append_to_list(node_ptr_ref head_ref, int data)
{
	if((*head_ref) == NULL)
	{
		(*head_ref) = get_new_node(data);
		return;
	}

	node_ptr head_tmp = (*head_ref);
	while(head_tmp->next)
	{
		head_tmp = head_tmp->next;
	}

	head_tmp->next = get_new_node(data);
}

unsigned int length(node_ptr head)
{
	int length = 0;
	while(head)
	{
		++length;
		head = head->next;
	}
	return length;
}

void find_merge_pont(node_ptr head1, node_ptr head2)
{
	int len1 = length(head1);
	int len2 = length(head2);

	int len = len2
}

int main()
{
	node c1 = {31,NULL};
	node c2 = {32,&c1};

	node a1 = {11,&c2};
	node a2 = {12,&a1};
	node a3 = {13,&a2};

	node b1 = {21,&c2};
	node b2 = {22,&b1};
	node b3 = {23,&b2};

	node_ptr list1 = &a3;
	node_ptr list2 = &b3;

	print_list(list1);
	print_list(list2);

	find_merge_pont(list1, list2);
}
