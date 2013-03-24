#include <iostream>
#include <vector>

int main()
{
	vector<int> sam(10);
	for(int i=0; i<sam.size(); i++)
		sam.push_back(i);

	for(int i=0; i<6; i++)
		cout << i << " :: " << sam[i] << endl;

	for(int i=0; i<sam.size(); i++)
		cout << i << " :: " << sam.at(i) << endl;
}
