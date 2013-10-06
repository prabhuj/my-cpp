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

node_ptr find_kth_node(node_ptr head, int k)
{
	if(!head) return head;

	while(k)
	{
		head = head->next;
		--k;
	}
	return head;
}

void swap(node_ptr head, int k)
{
	if(!k || !head) return;
	int n = length(head);
	if(n < k) return;

	int nitr = n-k;
	int kitr = k-1;

	node_ptr knode = head;
	while(kitr)
	{
		knode = knode->next;
		--kitr;
	}

	node_ptr nnode = head;
	while(nitr)
	{
		nnode = nnode->next;
		--nitr;
	}

	int tmp = knode->data;
	knode->data = nnode->data;
	nnode->data = tmp;
}

int main()
{
	node_ptr list = NULL;

	print_list(list); swap(list, 2); print_list(list); cout << endl;

	append_to_list(&list,1);
	append_to_list(&list,2);
	append_to_list(&list,3);
	append_to_list(&list,4);
	append_to_list(&list,5);

	print_list(list); swap(list, 0); print_list(list); cout << endl;
	print_list(list); swap(list, 1); print_list(list); cout << endl;
	print_list(list); swap(list, 2); print_list(list); cout << endl;
	print_list(list); swap(list, 3); print_list(list); cout << endl;
	print_list(list); swap(list, 4); print_list(list); cout << endl;
	print_list(list); swap(list, 5); print_list(list); cout << endl;
	print_list(list); swap(list, 6); print_list(list); cout << endl;
	print_list(list); swap(list, 7); print_list(list); cout << endl;

	append_to_list(&list,6);

	print_list(list); swap(list, 0); print_list(list); cout << endl;
	print_list(list); swap(list, 1); print_list(list); cout << endl;
	print_list(list); swap(list, 2); print_list(list); cout << endl;
	print_list(list); swap(list, 3); print_list(list); cout << endl;
	print_list(list); swap(list, 4); print_list(list); cout << endl;
	print_list(list); swap(list, 5); print_list(list); cout << endl;
	print_list(list); swap(list, 6); print_list(list); cout << endl;
	print_list(list); swap(list, 7); print_list(list); cout << endl;

	delete_list(&list);
}
