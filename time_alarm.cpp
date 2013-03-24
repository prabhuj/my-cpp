#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	{
	unsigned int secs = alarm(10);
	cout << getppid() << " :: " << getpid() << " :: alarm #1 :: " << secs << endl;
	}
	{
	sleep(5);
	unsigned int secs = alarm(20);
	cout << getppid() << " :: " << getpid() << " :: alarm #2 :: " << secs << endl;
	}
	{
	sleep(15);
	unsigned int secs = alarm(30);
	cout << getppid() << " :: " << getpid() << " :: alarm #3 :: " << secs << endl;
	}
}
