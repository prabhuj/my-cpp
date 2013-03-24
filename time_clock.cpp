#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	clock_t start = clock();
	clock_t end;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<1000000;i++){}
	end = clock(); cout << "Elapsed :: " << ((double)end-start)/CLOCKS_PER_SEC << endl;
}
