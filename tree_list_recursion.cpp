#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

nodeptr append(nodeptr x, nodeptr y)
{
	if(!x) return y;
	if(!y) return x;

	nodeptr x_last = x->left;
	nodeptr y_last = y->left;

	x_last->right = y;
	y->left = x_last;

	y_last->right = x;
	x->left = y_last;

	return x;
}

nodeptr tree_to_list(nodeptr root)
{
	if(!root) return root;
	nodeptr left = tree_to_list(root->left);
	nodeptr right = tree_to_list(root->right);

	root->left = root;
	root->right = root;

	left = append(left, root);
	right = append(left, right);

	return left;
}

void print_list(nodeptr head)
{
	nodeptr tmp = head;
	while(head)
	{
		cout << head->left->data << " :: " << head->data << " :: " << head->right->data << endl;
		head = head->right;
		if(tmp == head) break;
	}
}

void print_tree(nodeptr root)
{
	if(!root) return;
	print_tree(root->left);
	cout << root->data << endl;
	print_tree(root->right);
}

int main()
{
	node g = {1,NULL,NULL};
	node f = {3,NULL,NULL};
	node e = {2,&g,&f};
	node d = {7,NULL,NULL};
	node c = {5,NULL,NULL};
	node b = {6,&c,&d};
	node a = {4,&e,&b};

	print_tree(&a);

	nodeptr list = tree_to_list(&a);

	print_list(list);
}
