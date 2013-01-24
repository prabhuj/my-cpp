#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

int tree_size(nodeptr root)
{
	if(!root)
		return 0;
	else
		return (1 + tree_size(root->left) + tree_size(root->right));
}

int main()
{
	node g = {7, NULL, NULL};
	node f = {6, NULL, NULL};
	node e = {5, NULL, NULL};
	node d = {4, NULL, NULL};
	node c = {3, &f, &g};
	node b = {2, &d, &e};
	node a = {1, &b, &c};

	cout << tree_size(&a) << endl;
}
