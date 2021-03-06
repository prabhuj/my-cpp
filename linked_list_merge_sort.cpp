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
	node_ptr tmp1 = (*head_ref);
	while(tmp1)
	{
		node_ptr tmp2 = tmp1->next;
		delete tmp1;
		tmp1 = tmp2;
	}
	(*head_ref) = NULL;
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

node_ptr merge_list(node_ptr h1, node_ptr h2)
{
}

void split_list(node_ptr head, node_ptr_ref h1, node_ptr_ref h2)
{
	if(!head || !head->next)
	{
		(*h1) = head;
		(*h2) = NULL;
	}

	node_ptr slow_ptr = head;
	node_ptr fast_ptr = head;

	while(fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	(*h1) = head;
	(*h2) = slow_ptr->next;
	slow_ptr->next = NULL;
}

void merge_sort_list(node_ptr_ref head_ref)
{
	node_ptr head = (*head_ref);

	if(!head || !head->next)
		return;

	node_ptr first_half = NULL;
	node_ptr second_half = NULL;

	split_list(head, &first_half, &second_half);

	print_list(first_half);
	print_list(second_half);
}

int main()
{
	node_ptr list = NULL;

	append_to_list(&list,10);
	append_to_list(&list,9);
	append_to_list(&list,8);
	append_to_list(&list,7);
	append_to_list(&list,6);
	append_to_list(&list,5);
	append_to_list(&list,4);
	append_to_list(&list,3);
	append_to_list(&list,2);
	append_to_list(&list,1);

	print_list(list);

	merge_sort_list(&list);

	print_list(list);

	delete_list(&list);
}
