#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void print_list(Node* root)
{
	while(root)
	{
		cout << root->data << " -> ";
		root = root->next;
	}
	cout << endl;
}

Node* reverse(Node* root)
{
	Node* new_root = 0;
	while(root)
	{
		Node* next = root->next;
		root->next = new_root;
		new_root = root;
		root = next;
	}
	return new_root;
}

int main()
{
	Node a = {1,0};
	Node b = {2,&a};
	Node c = {3,&b};
	Node d = {4,&c};
	Node e = {5,&d};

	Node* root = &e;
	print_list(root);
	root = reverse(root);
	print_list(root);

	return 0;
}
