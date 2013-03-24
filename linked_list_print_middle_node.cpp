/*
print the middle of a given linked list
http://www.geeksforgeeks.org/archives/821
*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

int print_middle(nodeptr head)
{
	nodeptr slowptr = head;
	nodeptr fastptr = head;

	if(fastptr)
	{
		while(fastptr->next && fastptr->next->next)
		{
			fastptr = fastptr->next->next;
			slowptr = slowptr->next;
		}
		return slowptr->data;
	}

	return -1;
}

int main()
{
	node A = {1,NULL};
	node B = {2,&A};
	node C = {3,&B};
	node D = {4,&C};
	node E = {5,&D};

	cout << print_middle(&E) << endl;
	cout << print_middle(&D) << endl;
	cout << print_middle(&C) << endl;
	cout << print_middle(&B) << endl;
	cout << print_middle(&A) << endl;
	cout << print_middle(NULL) << endl;

	return 0;
}
