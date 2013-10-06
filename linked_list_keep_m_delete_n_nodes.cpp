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

void keep_m_delete_n(node_ptr_ref head_ref, int m, int n)
{
	node_ptr head = (*head_ref);
	while(head)
	{
		int m_i = m;
		while(--m_i && head)
		{
			head = head->next;
		}
		int n_i = n;
		node_ptr tmp = head->next;
		while(--n_i && tmp)
		{
			tmp = tmp->next;
		}
		head->next = tmp->next;
	}
	(*head_ref) = head;
}

int main()
{
	node n10 = {10,NULL};
	node n9 = {9,&n10};
	node n8 = {8,&n9};
	node n7 = {7,&n8};
	node n6 = {6,&n7};
	node n5 = {5,&n6};
	node n4 = {4,&n5};
	node n3 = {3,&n4};
	node n2 = {2,&n3};
	node n1 = {1,&n2};

	node_ptr x = &n1;

	print_list(x);

	keep_m_delete_n(&x, 2, 1);

	print_list(x);
}
