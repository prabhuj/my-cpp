#include <iostream>
#include <queue>

using namespace std;

struct node
{
    char* data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

/*
node* treeToList(node* r) 
{
	cout << "treeToList(" << r->data << ")" << endl;
    // Terminating Condition of Recursion
    if (r == NULL){ return NULL; }

    // Convert to list the left and right subtrees recursively
    node *prev = treeToList(r->left);
    node *next = treeToList(r->right);

    // Making the root node a separate list
    r->left = NULL;
    r->right = NULL;

    // Append everything together in sorted order
    prev = append(prev, r);
    prev = append(prev, next);

    return(prev);
}

node* append(node *a, node *b)
{

    // If any of the two lists is null return the 2nd list.
    if (a == NULL) return b;
    if (b == NULL) return a;

    node* head = a;

    while(a->right != NULL){ a = a->right; }

    a->right = b;
    b->left = a;

    return(head);
}
*/

void display_depth_first(node *root)
{
    if(root!=NULL)
    {
	display_depth_first(root->left);
	cout << root->data << endl;
	display_depth_first(root->right);
    }
}

void display_breadth_first(node *root)
{
    queue<node *> myqueue;
    myqueue.push(root);
    while(!myqueue.empty())
    {
	node* t = myqueue.front();
	myqueue.push(t->left);
	myqueue.push(t->right);
	myqueue.pop();
	cout << t->data << endl;
    }
}

int main()
{
    //node n = {"0111",NULL,NULL};
    //node m = {"0110",NULL,NULL};
    //node l = {"0101",NULL,NULL};
    //node k = {"0100",NULL,NULL};
    //node j = {"0011",NULL,NULL};
    //node i = {"0010",NULL,NULL};
    //node h = {"0001",NULL,NULL};
    //node g = {"0000",NULL,NULL};
    //node f = {"011",&m,&n};
    //node e = {"010",&k,&l};
    //node d = {"001",&i,&j};
    //node c = {"000",&g,&h};
    node f = {"011",NULL,NULL};
    node e = {"010",NULL,NULL};
    node d = {"001",NULL,NULL};
    node c = {"000",NULL,NULL};
    node b = {"01",&e,&f};
    node a = {"00",&c,&d};
    node x = {"0" ,&a,&b};

    node* root = &x;

    cout << "depth first" << endl;
    display_depth_first(root);

    cout << "breadth first" << endl;
    display_breadth_first(root);

	cout << "tree-to-list" << endl;

    return 0;
}

		/*
#include<stdio.h>
#include<malloc.h>
node *parent = NULL;

node *getnode();
void insert(node*,node*);
void display(node*);
int choice,no,item;
node *s,*temp,*root;
root=NULL;
while(1)
{
printf("\n @@@@@@@");
printf("\n 1.Create");
printf("\n 2.Display");
printf("\n 3.exit");
printf("enter the choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("No.of.elements:");
scanf("%d",&no);
while(no>0)
{
s=getnode();
printf("\n enter the element:");
scanf("%d",&s->data);
if(root==NULL)
root=s;
else
insert(root,s);
no--;
}
break;
case 2:
printf("elements are");
display(root);
break;
case 3:
//exit();
break;
}
}
}
node *getnode()
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
return(temp);
}
void insert(node *root,node *new_node)
{
if((new_node->data)<(root->data))
{
if(root->left==NULL)
root->left=new_node;
else
insert(root->left,new_node);
}
if(new_node->data > root->data)
{
if(root->right==NULL)
root->right=new_node;
else
insert(root->right,new_node);
}
}
void display(node *root)
{
    if(root!=NULL)
    {
	display(root->left);
	printf("%d\t",root->data);
	display(root->right);
    }
}
*/
