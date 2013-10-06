#include <iostream>

using namespace std;

typedef struct
{
	int *contents;
	int max_size;
	int top;
} stack;

typedef stack* stack_ptr;

void init(stack_ptr my_stack, int max_size)
{
	int *new_contents;

	new_contents = new (std::nothrow) int[max_size];

	if(new_contents == NULL) exit(1);

	my_stack->contents = new_contents;
	my_stack->max_size = max_size;
	my_stack->top = -1;
}

void destroy(stack_ptr my_stack)
{
	delete[] my_stack->contents;

	my_stack->contents = NULL;
	my_stack->max_size = 0;
	my_stack->top = -1;
}

bool full(stack_ptr my_stack)
{
	return my_stack->top >= my_stack->max_size - 1;
}

bool empty(stack_ptr my_stack)
{
	return my_stack->top < 0;
}

void push(stack_ptr my_stack, int element)
{
	if (full(my_stack))
	{
		cout << "stack is full" << endl;
		return;
	}

	my_stack->contents[++my_stack->top] = element;
}

int pop(stack_ptr my_stack)
{
	if (empty(my_stack))
	{
		cout << "stack is empty" << endl;
		return -999;
	}

	return my_stack->contents[my_stack->top--];
}

int middle(stack_ptr my_stack)
{
	if (empty(my_stack))
	{
		cout << "stack is empty" << endl;
		return -999;
	}

	return my_stack->contents[my_stack->top/2];
}

void print(stack_ptr my_stack)
{
	cout << "TOP";
	for(int i=0;i<=my_stack->top;i++)
	{
		cout << " -> " << my_stack->contents[i];
	}
	cout << " -> END" << endl;
}

int main()
{
	stack_ptr mystack;

	init(mystack, 5);

	for(int i=1;i<=5;i++)
		push(mystack, i);

	{
		              print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
		pop(mystack); print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
		pop(mystack); print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
		pop(mystack); print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
		pop(mystack); print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
		pop(mystack); print(mystack); cout << "is empty :: " << empty(mystack) << endl; cout << "middle :: " << middle(mystack) << endl;
	}

	destroy(mystack);

	return 0;
}
