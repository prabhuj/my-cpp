#include <iostream>

using namespace std;

void print_string_transformation(char* str)
{
	cout << str << endl;
	int len = strlen(str);
	//cout << len << endl;

	if(len < 2)
	{
		cout << str << endl;
		return;
	}

	int odd = len%2;
	for(int j=1;j<(len+1)/2;j++)
	{
		for(int i=j;i<len-j-1+odd;)
		{
			char tmp = str[i];
			str[i] = str[i+1];
			str[i+1] = tmp;
			i = i+2;
		}
		//cout << str << endl;
	}
	cout << str << endl;
}

int main()
{
	{ char str[] = ""; print_string_transformation(str); }
	{ char str[] = "a"; print_string_transformation(str); }
	{ char str[] = "a1"; print_string_transformation(str); }
	{ char str[] = "a1b2c3d4e5f6g7h8i9"; print_string_transformation(str); }
	{ char str[] = "a1b2c3d4e5f6g7h8i"; print_string_transformation(str); }
	return 0;
}

/*
if( old_index is odd )
	new_index = len / 2 + old_index / 2;
else
        new_index = old_index / 2;
*/
