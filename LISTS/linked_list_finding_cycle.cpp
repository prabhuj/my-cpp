#include <iostream>
#include "list_node.h"

bool is_cyclic(nodeptr head)
{
	nodeptr fast_ptr = head;
	nodeptr slow_ptr = head;

	while(fast_ptr && fast_ptr->next && slow_ptr)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if(fast_ptr == slow_ptr)
			return true;

	}
	return false;
}

int main()
{
	node a = {8, NULL};
	node b = {7, &a};
	node c = {6, &b};
	node d = {5, &c};
	node e = {4, &d};
	node f = {3, &e};
	node g = {2, &f};
	node h = {1, &g};

	a.next = &f;

	//display(&h);

	cout << is_cyclic(&h) << endl;

	node x = {9, &x};

	cout << is_cyclic(&x) << endl;
	cout << is_cyclic(NULL) << endl;
}
