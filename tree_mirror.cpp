#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void tree_mirror(nodeptr root)
{
	if(!root) return;

	tree_mirror(root->left);
	tree_mirror(root->right);
	nodeptr tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

void display_inorder(nodeptr root)
{
	if(!root) return;
	display_inorder(root->left);
	cout << root->data << " ";
	display_inorder(root->right);
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

	cout << "in order  :: "; display_inorder(&a);   cout << endl;
	tree_mirror(&a);
	cout << "in order  :: "; display_inorder(&a);   cout << endl;
}
