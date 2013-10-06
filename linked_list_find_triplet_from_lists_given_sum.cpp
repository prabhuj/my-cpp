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

void find_triplet(node_ptr_ref head1, node_ptr_ref head2, node_ptr_ref head3, int num)
{
	node_ptr h1 = (*head1);

	while(h1)
	{
		node_ptr h2 = (*head2);
		node_ptr h3 = (*head3);

		while(h2 && h3)
		{
			int sum = h1->data + h2->data + h3->data;
			cout << "analyzing = " << h1->data << " " << h2->data << " " << h3->data << " = " << sum << " :: " << num << endl;
			if(sum == num)
			{
				cout << "triplet = " << h1->data << " " << h2->data << " " << h3->data << endl;
				return;
			}
			else if(sum < num) h2 = h2->next;
			else if(sum > num) h3 = h3->next;
		}
		h1 = h1->next;
	}
	cout << "no triplet" << endl;
}

int main()
{
	node_ptr list1 = NULL;
	node_ptr list2 = NULL;
	node_ptr list3 = NULL;

	append_to_list(&list1,20);
	append_to_list(&list1,4);
	append_to_list(&list1,15);
	append_to_list(&list1,10);

	append_to_list(&list2,1);
	append_to_list(&list2,2);
	append_to_list(&list2,4);
	append_to_list(&list2,8);

	append_to_list(&list3,10);
	append_to_list(&list3,9);
	append_to_list(&list3,4);
	append_to_list(&list3,2);

	print_list(list1);
	print_list(list2);
	print_list(list3);

	find_triplet(&list1, &list2, &list3, 25);

	delete_list(&list1);
	delete_list(&list2);
	delete_list(&list3);
}
