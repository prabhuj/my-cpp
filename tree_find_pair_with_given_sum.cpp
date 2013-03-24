/* http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/ */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void push_tree_into_queue(nodeptr root, queue<nodeptr>* myqueue, bool reverse)
{
	if(!root) return;

	stack<nodeptr> mystack;

	while()
	{
		if(root)
		{
			mystack.push(root);
			root = root->left;
		}
		else
		{
			if(mystack.empty())
			{
				flag = true;
			}
			else
			{
				root = mystack.front();
				mystack.pop();
				flag = true;
			}
		}
	}
/*
	mystack.push(root);
	while(!mystack.empty())
	{
		nodeptr top = mystack.top();
		mystack.pop();
		myqueue->push(top);
		if(!reverse) if(top->right) mystack.push(top->right);
		if(top->left)  mystack.push(top->left);
		if(reverse) if(top->right) mystack.push(top->right);
	}
*/
}

void print_queue(queue<nodeptr> myqueue)
{
	cout << "FRONT -> ";
	while(!myqueue.empty())
	{
		cout << myqueue.front()->data << " -> ";
		myqueue.pop();
	}
	cout << "BACK" << endl;
}

void find_pair(nodeptr root)
{
	queue<nodeptr> q1;
	push_tree_into_queue(root, &q1, false);
	cout << "q1 size :: " << q1.size() << endl;
	print_queue(q1);

	queue<nodeptr> q2;
	push_tree_into_queue(root, &q2, true);
	cout << "q2 size :: " << q2.size() << endl;
	print_queue(q2);
}

int main()
{
	node rt_r_r = {7,NULL,NULL};
	node rt_r_l = {6,NULL,NULL};
	node rt_r   = {5,&rt_r_l,&rt_r_r};
	node rt_l_r = {4,NULL,NULL};
	node rt_l_l = {3,NULL,NULL};
	node rt_l   = {2,&rt_l_l,&rt_l_r};
	node rt     = {1,&rt_l,&rt_r};

	find_pair(&rt);

	return 0;
}
