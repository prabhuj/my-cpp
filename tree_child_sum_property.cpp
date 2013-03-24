#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

bool check_child_sum_property(nodeptr root)
{
	if(!root || (!root->left && !root->right))
		return true;
	else
	{
		return (
			(root->data == (((root->left)?root->left->data:0) + ((root->right)?root->right->data:0))) && 
			check_child_sum_property(root->left) && 
			check_child_sum_property(root->right));
	}
}

int main()
{
	node g = {1, NULL, NULL};
	node f = {2, NULL, NULL};
	node e = {3, NULL, NULL};
	node d = {4, NULL, NULL};
	node c = {3, &f, &g};
	node b = {7, &d, &e};
	node a = {10, &b, &c};

	cout << check_child_sum_property(&a) << endl;
}
