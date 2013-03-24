#include <iostream>

using namespace std;

struct node
{
	char data;
	struct node* next;
};

typedef struct node* nodeptr;

nodeptr display(nodeptr head)
{
	cout << "HEAD --> ";
	while(head)
	{
		cout << head->data << " --> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

nodeptr find_mid(nodeptr head)
{
	nodeptr fast_ptr = head;
	nodeptr slow_ptr = head;

	while(fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	return slow_ptr;
}

nodeptr reverse(nodeptr head)
{
	if(!head) return head;

	nodeptr new_head = NULL;

	while(head)
	{
		nodeptr tmp = head->next;
		head->next = new_head;
		new_head = head;
		head = tmp;
	}

	return new_head;
}

void compare(nodeptr left, nodeptr right)
{
	display(left);
	display(right);

	while(left && right)
	{
		if(left->data != right->data)
			return;

		left = left->next;
		right = right->next;
	}

	cout << "Match" << endl;
}

void is_palindrome(nodeptr head)
{
	if(!head) return;
	display(head);

	nodeptr mid = find_mid(head);
	display(head);
	//display(mid);

	nodeptr mid_reverse = reverse(mid);
	display(head);
	//display(mid_reverse);

	compare(head, mid_reverse);
}

int main()
{
	node l = {'p', NULL};
	node k = {'r', &l};
	node j = {'a', &k};
	node i = {'b', &j};
	node h = {'h', &i};
	node g = {'u', &h};
	node f = {'u', &g};
	node e = {'h', &f};
	node d = {'b', &e};
	node c = {'a', &d};
	node b = {'r', &c};
	node a = {'p', &b};

	is_palindrome(&a);

	return 0;
};
