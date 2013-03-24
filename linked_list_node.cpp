#include <iostream>
#include "linked_list_node.h"

using namespace std;

int main()
{
cout << __FILE__ << __LINE__ << endl;
	nodeptr list = NULL;
cout << __FILE__ << __LINE__ << endl;
	display(list);
cout << __FILE__ << __LINE__ << endl;
	append(list,1);
cout << __FILE__ << __LINE__ << endl;
	append(list,2);
cout << __FILE__ << __LINE__ << endl;
	append(list,3);
cout << __FILE__ << __LINE__ << endl;
	append(list,4);
cout << __FILE__ << __LINE__ << endl;
	append(list,5);
cout << __FILE__ << __LINE__ << endl;
	display(list);
cout << __FILE__ << __LINE__ << endl;
}
