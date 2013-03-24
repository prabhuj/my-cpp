#include <iostream>

using namespace std;

class double_linked_list
{
	private:
		struct node
		{
			int data;
			node* next;
			node* prev;
		}*ptr;
	public:
		double_linked_list();
		~double_linked_list();

		void add_node(int val);
		void del_node();
		void display();
		int count();
};

double_linked_list::double_linked_list()
{
	ptr = NULL;
}

double_linked_list::~double_linked_list()
{
	while(ptr != NULL)
	{
		node* t = ptr->next;
		delete t;
		ptr = t;
	}
}

double_linked_list::add_node(int val)
{
	
}

int main()
{
	double_linked_list dll;
}
