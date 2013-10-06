/* http://www.geeksforgeeks.org/check-leaves-level/ */

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

int depth(nodeptr root, int d)
{
	if(root == NULL)
	{
		return d;
	}

	return depth(root->left, d) - depth(root->right, d);
}

int main()
{
	//node rt_r_r = {7,NULL,NULL};
	//node rt_r_l = {5,NULL,NULL};
	//node rt_r   = {6,&rt_r_l,&rt_r_r};
	node rt_l_r = {3,NULL,NULL};
	node rt_l_l = {1,NULL,NULL};
	node rt_l   = {2,&rt_l_l,&rt_l_r};
	node rt     = {4,&rt_l,NULL};//&rt_r};

	cout << depth(&rt, 0) << endl;

	return 0;
}
