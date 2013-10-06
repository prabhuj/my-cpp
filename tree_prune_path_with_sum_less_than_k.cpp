#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

typedef struct Node Node;
typedef struct Node* NodePtr;

void print(NodePtr node)
{
	if (!node) return;
	print(node->left);
	cout << node->data << endl;
	print(node->right);
}

NodePtr new_node(int data)
{
	NodePtr node = new Node;
	node->data = data;
	return node;
}

int max(int x, int y)
{
	return (x>y)?x:y;
}

NodePtr prune_path(NodePtr node, int k, int* sum)
{
	if(!node) return node;

	int left_sum = (*sum) + (node->data);
	int right_sum = left_sum;

	node->left = prune_path(node->left, k, &left_sum);
	node->right = prune_path(node->right, k, &right_sum);

	*sum = max(left_sum, right_sum);

	if(*sum < k)
	{
		delete node;
		node = NULL;
	}

	return node;
}

NodePtr prune(NodePtr node, int k)
{
	int sum = 0;
	return prune_path(node, k, &sum);
}

int main()
{
	int k = 45;
	struct Node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	root->left->left->left = new_node(8);
	root->left->left->right = new_node(9);
	root->left->right->left = new_node(12);
	root->right->right->left = new_node(10);
	root->right->right->left->right = new_node(11);
	root->left->left->right->left = new_node(13);
	root->left->left->right->right = new_node(14);
	root->left->left->right->right->left = new_node(15);

	print(root);
	cout << "------" << endl;
	root = prune(root, k);
	print(root);

	return 0;
}
