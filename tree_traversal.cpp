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

void display_preorder(nodeptr root)
{
	if(!root) return;
	cout << root->data << " ";
	display_preorder(root->left);
	display_preorder(root->right);
}

void display_inorder(nodeptr root)
{
	if(!root) return;
	display_inorder(root->left);
	cout << root->data << " ";
	display_inorder(root->right);
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
	nodeptr tmp = root;

	queue<nodeptr> myq;

	while(tmp)
	{
		cout << tmp->data << " ";
		if(tmp->left)  myq.push(tmp->left);
		if(tmp->right) myq.push(tmp->right);
		tmp = myq.front();
		myq.pop();
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

	cout << "pre order   :: "; display_preorder(&a);  cout << endl;
	cout << "in order    :: "; display_inorder(&a);   cout << endl;
	cout << "post order  :: "; display_postorder(&a); cout << endl;
	cout << "level order :: "; display_levelorder(&a);
}
