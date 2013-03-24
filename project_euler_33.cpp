#include <iostream>

int main()
{
	//int i=4,j=8;
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			float y = i/j;
			for(int a=1;a<10;a++)
			{
				int n1 = i*10+a;
				int d1 = j*10+a;
				int n2 = a*10+i;
				int d2 = a*10+j;
				//cout << n1 << " :: " << d1 << " :: " << n2 << " :: " << d2 << endl;
				if((float)i/j == (float)n1/d1)
					cout << i << " :: " << j << " :: " << n1 << " :: " << d1 << " match" << endl;
				else if((float)i/j == (float)n2/d2)
					cout << i << " :: " << j << " :: " << n2 << " :: " << d2 << " match" << endl;
				else if((float)i/j == (float)n1/d2)
					cout << i << " :: " << j << " :: " << n1 << " :: " << d2 << " match" << endl;
				else if((float)i/j == (float)n2/d1)
					cout << i << " :: " << j << " :: " << n2 << " :: " << d1 << " match" << endl;
				//cout << n1 << " :: " << d1 << " :: " << n2 << " :: " << d2 << " match" << endl;
			}
			//cout << i << "/" << j << endl;
		}
	}
}
