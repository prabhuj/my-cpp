// http://forums.thedailywtf.com/forums/t/3045.aspx
#include <iostream>

using namespace std;

typedef struct node
{
	char* data;
	node* left;
	node* right;
}node;

node* find_left_most(node* tree)
{
	if(!tree->left)
		return tree;
	return find_left_most(tree->left);
}

node* find_right_most(node* tree)
{
	if(!tree->right)
		return tree;
	return find_right_most(tree->right);
}

node* btree_2_list(node* tree)
{
	if(!tree)
		return tree;

	if(tree->left)
	{
		tree->left = find_right_most(btree_2_list(tree->left));
		tree->left->right = tree;
	}

	if(tree->right)
	{
		tree->right = btree_2_list(tree->right);
		tree->right->left = tree;
	}

	return find_left_most(tree);
}

node* btree_2_list_queue(node* tree)
{
	queue<node*> hold;
	node* list;
	hold.push(tree);
	node* new_node = NULL;
	while(!hold.empty())
	{
		for(int i=0;i<hold.size();i++)
		{
			cout << hols.front(0.data << endl;
			hold.push(hold.front().left);
			hold.push(hold.front().right);
			//list->right = hold.front();
			//list->left = new_node;
			//new_node = list->right;
			hold.pop();
		}
	}
}

void display_tree(node* tree)
{
	if(!tree)
	{
		cout << "NULL" << endl;
		return;
	}
	cout << tree->data << endl;
	display_tree(tree->left);
	display_tree(tree->right);
}

void display_list(node* list)
{
	while(list)
	{
		if(!list->left)
			cout << "  NULL :: ";
		else
			cout << list->left->data << " :: ";
		cout << list->data << " :: ";

		if(!list->right)
			cout << "NULL" << endl;
		else
			cout << list->right->data << endl;

		list = list->right;
	}
}

int main()
{
	node tree[7];

	tree[0].data = "node-0";
	tree[1].data = "node-1";
	tree[2].data = "node-2";
	tree[3].data = "node-3";
	tree[4].data = "node-4";
	tree[5].data = "node-5";
	tree[6].data = "node-6";

	for(int i=0;i<3;i++)
	{
		tree[i].left = tree+(2*i+1);
		tree[i].right = tree+(2*i+2);
	}

	for(int i=3;i<7;i++)
	{
		tree[i].left = NULL;
		tree[i].right = NULL;
	}

	cout << endl << "=====> DISPLAY TREE <=====" << endl;
	display_tree(tree);

	//node* list = btree_2_list(tree);

	cout << endl << "=====> DISPLAY LIST <=====" << endl;
	//display_list(list);

	node* list = btree_2_list_queue(tree);

	display_list(list_0);

	return 0;
}
