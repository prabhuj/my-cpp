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

void delete_list(node_ptr_ref head)
{
	node_ptr tmp1 = (*head);
	while(tmp1)
	{
		node_ptr tmp2 = tmp1->next;
		delete tmp1;
		tmp1 = tmp2;
	}
	(*head) = NULL;
}

void append_to_list(node_ptr_ref head, int data)
{
	if((*head) == NULL)
	{
		(*head) = get_new_node(data);
		return;
	}

	node_ptr head_tmp = (*head);
	while(head_tmp->next)
	{
		head_tmp = head_tmp->next;
	}

	head_tmp->next = get_new_node(data);
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

void add_lists(node_ptr_ref head3, node_ptr_ref head1, node_ptr_ref head2)
{
	reverse_list(head1);
	reverse_list(head2);

	node_ptr h1 = (*head1);
	node_ptr h2 = (*head2);

	int carry = 0;
	int sum = 0;

	while(h1 && h2)
	{
		sum = (h1->data + h2->data + carry)%10;
		carry = (h1->data + h2->data + carry)/10;
		append_to_list(head3, sum);
		h1 = h1->next;
		h2 = h2->next;
	}
	while(h1)
	{
		sum = (h1->data + carry)%10;
		carry = (h1->data + carry)/10;
		append_to_list(head3, sum);
		h1 = h1->next;
	}
	while(h2)
	{
		sum = (h2->data + carry)%10;
		carry = (h2->data + carry)/10;
		append_to_list(head3, sum);
		h2 = h2->next;
	}
	if(carry) append_to_list(head3, carry);

	reverse_list(head1);
	reverse_list(head2);
	reverse_list(head3);
}

int main()
{
	node_ptr list1 = NULL;
	node_ptr list2 = NULL;
	node_ptr list3 = NULL;

	append_to_list(&list1,9);
	append_to_list(&list1,9);
	append_to_list(&list1,9);
	append_to_list(&list1,9);

	append_to_list(&list2,5);
	append_to_list(&list2,6);
	append_to_list(&list2,7);
	append_to_list(&list2,8);
	append_to_list(&list2,9);

	add_lists(&list3, &list1, &list2);

	print_list(list1);
	print_list(list2);
	print_list(list3);

	delete_list(&list1);
	delete_list(&list2);
	delete_list(&list3);
}
