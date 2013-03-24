#include <iostream>

using namespace std;

void sigHandler(int sig_num)
{
	if(sig_num == SIGINT)
	{
		cout << "not catching Ctrl+C" << endl;
	}
}

int main()
{
	signal(SIGINT, sigHandler);

	while(1)
	{
	}

	return 0;
}
