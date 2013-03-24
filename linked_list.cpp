#include <iostream>

using namespace std;

class linked_list
{
	private:
		struct node
		{
			int data;
			node* next;
		}*ptr;
	public:
		linked_list();
		~linked_list();

		void add_node(int x);
		void del_node(int y);
		void display();
		int  count();
};

linked_list::linked_list()
{
	ptr = NULL;
}

linked_list::~linked_list()
{
	while(ptr != NULL)
	{
		node* t = ptr->next;
		delete ptr;
		ptr = t;
	}
}

/*+---------------------------------------------------------+
 | Insert a node based on the increasing order of its value |
 +----------------------------------------------------------+*/
void linked_list::add_node(int x)
{
	if(ptr == NULL)
	{
		ptr = new node;
		ptr->data = x;
		ptr->next = NULL;
	}
	else
	{
		node *t, *q;
		node* n = new node;
		n->data = x;
		for(t=ptr;t->data<x;t=t->next)
		{
			if(t->next == NULL)
			{
				n->next = NULL;
				t->next = n;
				return;
			}
			q = t;
		}
		n->next = t;
		q->next = n;
	}
}

/*+----------------------------------------------------+
 | Delete a node based on value provided from the list |
 +-----------------------------------------------------+*/
void linked_list::del_node(int x)
{
	if(ptr == NULL)
	{
		cout << "No such element to delete" << endl;
		return;
	}
	node *t = ptr;
	if(t->data == x)
	{
		ptr = t->next;
		delete t;
		return;
	}

	node* q = t;
	while(t!=NULL)
	{
		if(t->data == x)
		{
			q->next = t->next;
			delete t;
			return;
		}
		q = t;
		t = t->next;
	}
	cout << "No such element to delete" << endl;
}

/*+---------------------------------+
 | Display the contents of the list |
 +----------------------------------+*/
void linked_list::display()
{
	node* t;
	for(t=ptr;t!=NULL;t=t->next)
	{
		cout << " -> " << t->data;
	}
	cout << "NULL" << endl;
}

/*+-------------------------+
 | Get the size of the list |
 +--------------------------+*/
int linked_list::count()
{
	node* t;
	int cnt = 0;
	for(t=ptr;t!=NULL;t=t->next)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	linked_list mylist;
	int ch = 1;
	while(ch != 0)
	{
		cout << "List operations you can perform ::

 0. Exit
 1. Add Node
 2. Delete Node
 3. Size
 4. Is Empty
 5. Display

Enter your choice : ";

		cin >> ch;
		int num = 0;
		switch(ch)
		{
			case 0:
				exit(1);
			case 1:
				cout << "Enter a number to insert :: ";
				cin >> num;
				cout << "------------------------------" << endl;
				mylist.add_node(num);
				cout << "Node with value " << num << " inserted" << endl;
				break;
			case 2:
				cout << "Enter a number to delete :: ";
				cin >> num;
				cout << "------------------------------" << endl;
				mylist.del_node(num);
				break;
			case 3:
				cout << "------------------------------" << endl;
				cout << "Size of list is :: " << mylist.count() << endl;
				break;
			case 4:
				cout << "------------------------------" << endl;
				if(mylist.count() == 0)
					cout << "List is empty" << endl;
				else
					cout << "List is not empty" << endl;
				break;
			case 5:
				cout << "------------------------------" << endl;
				mylist.display();
				break;
			default:
				cout << "------------------------------" << endl;
				cout << "Invalid Option" << endl;
		}
		cout << "------------------------------" << endl;
	}

	return 0;
}
