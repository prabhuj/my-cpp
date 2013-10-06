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

node_ptr get_new_node(int data)
{
	node_ptr new_node = new node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void append_node(node_ptr_ref head_ref, int data)
{
	if ((*head_ref) == NULL)
	{
		(*head_ref) = get_new_node(data);
		return;
	}

	node_ptr head_tmp = (*head_ref);
	while (head_tmp->next)
	{
		head_tmp = head_tmp->next;
	}
	head_tmp->next = get_new_node(data);
}

void delete_list(node_ptr_ref head_ref)
{
	node_ptr tmp1 = (*head_ref);
	while(tmp1)
	{
		node_ptr tmp2 = tmp1;
		tmp1 = tmp1->next;
		delete tmp2;
	}
	(*head_ref) = NULL;
}

void display_list(node_ptr head)
{
	cout << "HEAD";
	while(head)
	{
		cout << " -> " << head->data;
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

int main()
{
	node_ptr list1 = NULL;
	node_ptr list2 = NULL;
	node_ptr list3 = NULL;

	append_node(&list1, 1);
	append_node(&list1, 2);
	append_node(&list1, 3);

	append_node(&list2, 1);
	append_node(&list2, 2);
	append_node(&list2, 3);

	display_list(list1);
	display_list(list2);

	delete_list(&list1);
	delete_list(&list2);
}
