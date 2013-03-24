#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void display_inorder(nodeptr root)
{
	if(!root)
		return;
	display_inorder(root->left);
	cout << root->data << " ";
	display_inorder(root->right);
}

void update_child_sum_property_to_top(nodeptr root)
{
	if(!root || (!root->left && !root->right))
		return;
	else
	{
		update_child_sum_property_to_top(root->left);
		update_child_sum_property_to_top(root->right);

		int left_value = root->left ? root->left->data : 0;
		int right_value = root->right ? root->right->data : 0;

		if(root->data < (left_value +right_value))
			root->data = left_value +right_value;
	}
}

void update_child_sum_property_to_bottom(nodeptr root)
{
	if(!root || (!root->left && !root->right))
		return;
	else
	{
		int left_value = root->left ? root->left->data : 0;
		int right_value = root->right ? root->right->data : 0;

		if(root->data > (left_value + right_value))
		{
			if(root->left)
				root->left->data = root->data - right_value;
			else
				root->right->data = root->data - right_value;
		}

		update_child_sum_property_to_bottom(root->left);
		update_child_sum_property_to_bottom(root->right);

	}
}

int main()
{
	node g = {30, NULL, NULL};
	node f = {1, NULL, NULL};
	node e = {5, NULL, NULL};
	node d = {3, NULL, NULL};
	node c = {2, &f, &g};
	node b = {7, &d, &e};
	node a = {50, &b, &c};

	display_inorder(&a); cout << endl;
	update_child_sum_property_to_top(&a);
	display_inorder(&a); cout << endl;
	update_child_sum_property_to_bottom(&a);
	display_inorder(&a); cout << endl;
}
