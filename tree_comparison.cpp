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

bool compare_tree(nodeptr root1, nodeptr root2)
{
	if(!root1 && !root2)
		return true;
	else if(root1 && root2)
		return ((root1->data == root2->data) &&
			compare_tree(root1->left, root2->left) &&
			compare_tree(root1->right, root2->right));
	else
		return false;
}

int main()
{
	node g1 = {7, NULL, NULL};
	node f1 = {6, NULL, NULL};
	node e1 = {5, NULL, NULL};
	node d1 = {4, NULL, NULL};
	node c1 = {3, &f1, &g1};
	node b1 = {2, &d1, &e1};
	node a1 = {1, &b1, &c1};
	node g2 = {7, NULL, NULL};
	node f2 = {6, NULL, NULL};
	node e2 = {5, NULL, NULL};
	node d2 = {4, NULL, NULL};
	node c2 = {3, &f2, &g2};
	node b2 = {2, &d2, &e2};
	node a2 = {1, &b2, &c2};

	cout << compare_tree(&a1, &a2) << endl;
	cout << compare_tree(&a1, &b2) << endl;
}
