/* http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/ */

#include <iostream>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void push_tree_into_stack(nodeptr root, stack<nodeptr>* mystack, bool reverse)
{
	if(!root) return;

	if(root)
	{
		mystack->push(root);
		if(!reverse) push_tree_into_stack(root->left, mystack, reverse);
		push_tree_into_stack(root->right, mystack, reverse);
		if(reverse) push_tree_into_stack(root->left, mystack, reverse);
	}
}

void print_stack(stack<nodeptr> mystack)
{
	cout << "TOP -> ";
	while(!mystack.empty())
	{
		cout << mystack.top()->data << " -> ";
		mystack.pop();
	}
	cout << "END" << endl;
}

void find_pair(nodeptr root, int k)
{
	stack<nodeptr> s1;
	push_tree_into_stack(root, &s1, false);
	cout << "s1 size :: " << s1.size() << endl;
	print_stack(s1);

	stack<nodeptr> s2;
	push_tree_into_stack(root, &s2, true);
	cout << "s2 size :: " << s2.size() << endl;
	print_stack(s2);
}

int main()
{
	node rt_r_r = {7,NULL,NULL};
	node rt_r_l = {5,NULL,NULL};
	node rt_r   = {6,&rt_r_l,&rt_r_r};
	node rt_l_r = {3,NULL,NULL};
	node rt_l_l = {1,NULL,NULL};
	node rt_l   = {2,&rt_l_l,&rt_l_r};
	node rt     = {4,&rt_l,&rt_r};

	find_pair(&rt, 10);

	return 0;
}
