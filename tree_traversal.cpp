#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void display_preorder(nodeptr root)
{
	if(!root) return;
	cout << root->data << " ";
	display_preorder(root->left);
	display_preorder(root->right);
}

void display_inorder_recursive(nodeptr root)
{
	if(!root) return;
	display_inorder_recursive(root->left);
	cout << root->data << " ";
	display_inorder_recursive(root->right);
}

void display_inorder_iterative(nodeptr root)
{
	if(!root) return;

	stack<nodeptr> mystack;

	bool flag = true;

	while(flag)
	{
		if(!root)
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
				flag = false;
			}
		}
	}
}

void display_postorder(nodeptr root)
{
	if(!root) return;
	display_postorder(root->left);
	display_postorder(root->right);
	cout << root->data << " ";
}

void display_levelorder(nodeptr root)
{
	if(!root) return;

	queue<nodeptr> myq;
	myq.push(root);

	while(!myq.empty())
	{
		nodeptr tmp = myq.front();
		myq.pop();
		cout << tmp->data << " ";
		if(tmp->left) myq.push(tmp->left);
		if(tmp->right) myq.push(tmp->right);
	}
	cout << endl;
}

int main()
{
	node g = {7, NULL, NULL};
	node f = {5, NULL, NULL};
	node e = {3, NULL, NULL};
	node d = {1, NULL, NULL};
	node c = {6, &f, &g};
	node b = {2, &d, &e};
	node a = {4, &b, &c};

	cout << "pre order   :: "; display_preorder(&a);  cout << endl;
	cout << "in order    :: "; display_inorder_recursive(&a);   cout << endl;
	cout << "in order    :: "; display_inorder_iterative(&a);   cout << endl;
	cout << "post order  :: "; display_postorder(&a); cout << endl;
	cout << "level order :: "; display_levelorder(&a);
}
