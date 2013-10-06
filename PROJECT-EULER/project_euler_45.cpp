#include <iostream>

int main()
{
	int i=1,j=1,k=1;
	for(;;)
	{
		unsigned long long tri = (unsigned long long)i*(i+1)/2;
		unsigned long long pen = (unsigned long long)j*((3*j)-1)/2;

		if(tri == pen)
		{
			unsigned long long hex = (unsigned long long)k*((2*k)-1);

			if(tri == hex)
			{
				cout << "T<" << i << "> = P<" << j << "> = H<" << k << "> = " <<  tri << endl;
				cout << "would you like to continue (y/n) :";
				char ch;
				cin >> ch;
				if(ch == 'y')
				{
					i++;
					continue;
				}
				else
				{
					return 0;
				}
			}
			else if(tri < hex)
			{
				i++;
			}
			else if(tri > hex)
			{
				k++;
			}
		}
		else if(tri < pen)
		{
			i++;
		}
		else if(tri > pen)
		{
			j++;
		}
	}
}
