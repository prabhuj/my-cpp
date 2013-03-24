#include <iostream>

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

int max(int i, int j, int k)
{
	return (i>j)?((i>k)?i:k):((j>k)?j:k);
}

int height(nodeptr root)
{
	if(!root)
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

int tree_diameter(nodeptr root)
{
	if(!root)
		return 0;
	else
		return max((1 + height(root->left) + height(root->right)), tree_diameter(root->left), tree_diameter(root->right));
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

	cout << tree_diameter(&a) << endl;
}
