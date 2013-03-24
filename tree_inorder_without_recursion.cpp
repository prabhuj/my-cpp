#include <iostream>
#include <stack>

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
	stack<nodeptr> mystack;

	while(1)
	{
		if(root)
		{
			mystack.push(root);
			root = root->left;
		}
		else
		{
			if(!mystack.empty())
			{
				root = mystack.top();
				mystack.pop();
				cout << root->data << " ";
				root = root->right;
			}
			else
			{
				break;
			}
		}
	}
	cout << endl;
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

	display_inorder(&a);
}
