#include <iostream>
#include <limits.h>

int main() 
{
    unsigned int x=-1;
    int y;
    y = ~0;
    if(x == y)
	cout << "same" << endl;
    if(x==INT_MAX)
	cout << "INT_MAX" << endl;
    if(x==UINT_MAX)
	cout << "UINT_MAX" << endl;
    else
	cout << "not same" << endl;
    return 0;
}

