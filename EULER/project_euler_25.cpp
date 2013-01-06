#include <iostream>

#define DIGITS 1000

int main()
{
	int f_n_2[DIGITS];
	int f_n_1[DIGITS];
	int f_n[DIGITS];

	int term = 2;

	for(int i=0;i<DIGITS;i++)
	{
		f_n_2[i] = 0;
		f_n_1[i] = 0;
		f_n[i] = 0;
	}

	f_n_2[0] = 1;
	f_n_1[0] = 1;

	cout << "f[n] = ";
	for(int i=DIGITS-1;i>=0;i--)
	{
		cout << f_n_2[i];
	}
	cout << endl;
	cout << "f[n] = ";
	for(int i=DIGITS-1;i>=0;i--)
	{
		cout << f_n_1[i];
	}
	cout << endl;

	for(;;)
	{
		term++;

		for(int i=0;i<DIGITS;i++)
		{
			//if(f_n_2[i] == 0 && f_n_1[i] == 0)
			//{
				//break;
			//}

			f_n[i] = f_n_2[i] + f_n_1[i] + f_n[i];

			if(f_n[i] >= 10)
			{
				f_n[i+1] = f_n[i+1] + (f_n[i]/10);
				f_n[i] = f_n[i]%10;
			}
		}

		cout << "f[n] = ";
		for(int i=DIGITS-1;i>=0;i--)
		{
			cout << f_n[i];
		}
		cout << endl;

		f_n_2 = f_n_1;
		f_n_1 = f_n;

		if(f_n[DIGITS-1] != 0)
			break;

		for(int i=0;i<DIGITS;i++)
		{
			f_n[i] = 0;
		}
	}
	cout << "RESULT :: ";
	for(int i=DIGITS-1;i>=0;i--)
	{
		cout << f_n[i];
	}
	cout << endl;
	cout << "TERM :: " << term << endl;
}
