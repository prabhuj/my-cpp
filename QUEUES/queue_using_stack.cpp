#include <iostream>

using namespace std;

struct stack_node
{
	int data;
	struct stack_node* next;
};

typedef struct stack_node* stack_nodeptr;

void stack_push(stack_nodeptr* top, int data)
{
	cout << "check #7" << endl;
	if((*top) == NULL)
	{
		cout << "check #8" << endl;
		stack_nodeptr tmp = new stack_node();
		cout << "check #9" << endl;
		tmp->data = data;
		cout << "check #10" << endl;
		tmp->next = NULL;
		cout << "check #11" << endl;
		(*top) = tmp;
		cout << "check #12" << endl;
	}
	else
	{
		stack_nodeptr tmp = new stack_node();
		tmp->data = data;
		tmp->next = (*top);
		(*top) = tmp;
	}
}

int stack_pop(stack_nodeptr* top)
{
	if(!(*top))
	{
		return -1;
	}
	else
	{
		stack_nodeptr tmp = (*top)->next;
		int data = (*top)->data;
		delete((*top));
		(*top) = tmp;
		return data;
	}
}

void display(stack_nodeptr top)
{
	cout << "check #13" << endl;
	stack_nodeptr tmp = top;
	while(tmp)
	{
		cout << " -> " << tmp->data;
		tmp = tmp->next;
	}
	cout << " -> NULL" << endl;
}

struct queue_node
{
	stack_nodeptr stack1;
	stack_nodeptr stack2;
};

typedef struct queue_node* queue_nodeptr;

void queue_enqueue(queue_nodeptr head, int data)
{
	cout << "enqueue " << data << endl;
	if(!head)
	{
		cout << "check #1 " << endl;
		queue_nodeptr tmp = new queue_node();
		cout << "check #2 " << endl;
		tmp->stack1 = NULL;
		cout << "check #3 " << endl;
		tmp->stack2 = NULL;
		cout << "check #4 " << endl;
		head = tmp;
		cout << "check #5 " << endl;
	}
	cout << "check #6 " << endl;
	stack_push(&head->stack1, data);
}

int queue_dequeue(queue_nodeptr head)
{
	if(!head->stack1 && !head->stack2)
	{
		return -1;
	}

	if(!head->stack2)
	{
		while(head->stack1)
		{
			int data = stack_pop(&head->stack1);
			stack_push(&head->stack2, data);
		}
	}

	int data = stack_pop(&head->stack2);
	return data;
}

int main()
{
/*
	stack_nodeptr mystack = NULL;
	display(mystack);
	stack_push(&mystack, 1); display(mystack);
	stack_push(&mystack, 2); display(mystack);
	stack_push(&mystack, 3); display(mystack);
	stack_push(&mystack, 4); display(mystack);
	stack_push(&mystack, 5); display(mystack);
	stack_pop(&mystack); display(mystack);
	stack_pop(&mystack); display(mystack);
	stack_pop(&mystack); display(mystack);
	stack_pop(&mystack); display(mystack);
	stack_pop(&mystack); display(mystack);
*/

	queue_nodeptr q = NULL;

	queue_enqueue(q, 1); display(q->stack1); display(q->stack2);
	queue_enqueue(q, 2); display(q->stack1); display(q->stack2);
	queue_enqueue(q, 3); display(q->stack1); display(q->stack2);
	queue_enqueue(q, 4); display(q->stack1); display(q->stack2);
	queue_enqueue(q, 5); display(q->stack1); display(q->stack2);
}
