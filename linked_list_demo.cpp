#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node* next;
}node;

class LinkedList
{
	public:
		node* head;
		int length;

		LinkedList():head(NULL),length(0){}
		~LinkedList();
		void add_start(int x);
		void add_end(int x);
		void print();
		node* reverse();
		int size();
		void add(LinkedList& list);
};

LinkedList::~LinkedList()
{
	while(head != NULL)
	{
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void LinkedList::add_start(int x)
{
	if(head == NULL)
	{
		head = new node();
		head->data = x;
		head->next = NULL;
	}
	else
	{
		node* tmp = new node();
		tmp->data = x;
		tmp->next = head;
		head = tmp;
	}
	++length;
}

void LinkedList::add_end(int x)
{
	if(head == NULL)
	{
		head = new node();
		head->data = x;
		head->next = NULL;
	}
	else
	{
		node* tmp = head;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		node* nw = new node();
		nw->data = x;
		nw->next = tmp->next;
		tmp->next = nw;
	}
	++length;
}

void LinkedList::print()
{
	node* tmp = head;
	while(tmp != NULL)
	{
		//cout << " -> " << tmp->data;
		cout << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}

node* LinkedList::reverse()
{
	node* tmp = NULL;
	while(head != NULL)
	{
		node* next = head->next;
		head->next = tmp;
		tmp = head;
		head = next;
	}
	head = tmp;
}

int LinkedList::size()
{
	return length;
}

void LinkedList::add(LinkedList& list)
{
	reverse();
	list.reverse();

	node* n1 = head;
	node* n2 = list.head;
	int x = 0;
	while(n1 != NULL && n2 != NULL)
	{
		x = n1->data + n2->data + x;
		n1->data = x%10;
		x = x/10;
		n1 = n1->next;
		n2 = n2->next;
	}
	int y = x;
	while(n1 != NULL && y > 0)
	{
		y = n1->data + y;
		n1->data = y%10;
		y = y/10;
		n1 = n1->next;
	}
	while(n2 != NULL && y > 0)
	{
		y = n2->data + y;
		add_end(y%10);
		y = y/10;
		n2 = n2->next;
	}
	if(y>0)
	{
		add_end(y);
	}
	reverse();
}

int main()
{
	LinkedList l1;
	l1.add_start(9);
	l1.add_start(9);
	l1.add_start(9);
	l1.add_start(9);
	l1.add_start(9);
	l1.add_start(9);
	l1.print();

	LinkedList l2;
	l2.add_start(9);
	l2.add_start(9);
	l2.add_start(9);
	l2.add_start(9);
	l2.print();

	l1.add(l2);
	l1.print();
}
