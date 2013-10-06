#include <iostream>

using namespace std;

int main()
{
	float f;
	double d;
	cin >> d;
	f = d;
	if(f==((float)((int)f))) cout << "integer" << endl;
	else cout << "float" << endl;
	if(d==((double)((int)d))) cout << "integer" << endl;
	else cout << "double" << endl;
/*
	int i = (int)f;
	float x = (float)i;
	if(x==f) cout << "integer" << endl;
	else cout << "float" << endl;
	cout << EPSILON << endl;
*/
}
