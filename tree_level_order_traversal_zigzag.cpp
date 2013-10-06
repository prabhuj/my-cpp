#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

typedef struct node* nodeptr;

int max(int x, int y)
{
	return (x>y)?x:y;
}

int height(nodeptr root)
{
	if (!root)
		return 0;
	else
		return 1+max(height(root->left), height(root->right));
}

void print_zizzag(nodeptr root)
{
	cout << height(root) << endl;
	if (!root)
		return;

	bool direction = false;
}

int main()
{
	node rt_r_r_r = {15,NULL,NULL};
	node rt_r_r_l = {14,NULL,NULL};
	node rt_r_l_r = {13,NULL,NULL};
	node rt_r_l_l = {12,NULL,NULL};
	node rt_l_r_r = {11,NULL,NULL};
	node rt_l_r_l = {10,NULL,NULL};
	node rt_l_l_r = {9,NULL,NULL};
	node rt_l_l_l = {8,NULL,NULL};
	node rt_r_r   = {7,&rt_r_r_l,&rt_r_r_r};
	node rt_r_l   = {6,&rt_r_l_l,&rt_r_l_r};
	node rt_l_r   = {5,&rt_l_r_l,&rt_l_r_r};
	node rt_l_l   = {4,&rt_l_r_l,&rt_l_l_r};
	node rt_r     = {3,&rt_r_l,&rt_r_r};
	node rt_l     = {2,&rt_l_l,&rt_l_r};
	node rt       = {1,&rt_l,&rt_r};

	print_zizzag(&rt);

	return 0;
}
