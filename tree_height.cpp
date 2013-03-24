#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

int max(int i, int j)
{
	return (i>j)?i:j;
}

int tree_height(nodeptr root)
{
	if(!root)
		return 0;
	else
		return 1 + max(tree_height(root->left), tree_height(root->right));
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

	cout << tree_height(&a) << endl;
}
