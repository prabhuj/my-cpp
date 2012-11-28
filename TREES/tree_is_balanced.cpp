#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int height(nodeptr root)
{
	if(!root)
	{
		return -1;
	}
	else
	{
		return 1+max(height(root->left), height(root->right));
	}
}

bool is_balanced(nodeptr root)
{
	if(!root)
	{
		return true;
	}
	else
	{
		int rh = height(root->right);
		int lh = height(root->left);

		if(abs(rh-lh) <= 1)
		{
			return (is_balanced(root->right) && is_balanced(root->left));
		}
	}
	return false;
}

int main()
{
	node node7 = {7,NULL,NULL};
	node node6 = {6,NULL,NULL};
	node node5 = {5,NULL,NULL};
	node node4 = {4,&node7,NULL};
	node node3 = {3,&node6,NULL};
	node node2 = {2,&node4,&node5};
	node node1 = {1,&node2,&node3};

	cout << is_balanced(&node1) << endl;

	return 0;
}
