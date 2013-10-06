/* http://www.geeksforgeeks.org/print-left-view-binary-tree/ */

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* nodeptr;

void print_left_view(nodeptr root, int level, int *max_level)
{
	if(root == NULL)
	{
		return;
	}

	if(*max_level < level)
	{
		cout << root->data << endl;
		*max_level = level;
	}

	print_left_view(root->left, level+1, max_level);
	print_left_view(root->right, level+1, max_level);

}

int main()
{
	node rt_r_r = {7,NULL,NULL};
	node rt_r_l = {5,NULL,NULL};
	node rt_r   = {6,&rt_r_l,&rt_r_r};
	node rt_l_r = {3,NULL,NULL};
	node rt_l_l = {1,NULL,NULL};
	node rt_l   = {2,&rt_l_l,&rt_l_r};
	node rt     = {4,&rt_l,&rt_r};

	int max_level = 0;
	print_left_view(&rt, 1, &max_level);

	return 0;
}
