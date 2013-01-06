#include <iostream>

bool check_digit(unsigned long long x)
{
	//cout << "x :: " << x << endl;
	if(x%10!=0) return false;
	x = x/100;
	if(x%10!=9) return false;
	x /= 100;
	if(x%10!=8) return false;
	x /= 100;
	if(x%10!=7) return false;
	x /= 100;
	if(x%10!=6) return false;
	x /= 100;
	if(x%10!=5) return false;
	x /= 100;
	if(x%10!=4) return false;
	x /= 100;
	if(x%10!=3) return false;
	x /= 100;
	if(x%10!=2) return false;
	x /= 100;
	if(x%10!=1) return false;

	return true;
}

int main()
{
//1010101010.1010100960050505050505
//1389026623.1062635719505241093123
//1020304050607080900
//1929394959697989990

	//if(check_digit(1010304050607080900ull) == true)
		//cout << "match" << endl;
	//exit(1);

	for(int i=1010101010;i<1389026625;i+=10)
	{
		unsigned long long s = (unsigned long long)i*i;
		//cout << i << " :: " << s << endl;
		int j;
		if(check_digit(s) == true)
		{
			cout << i << " :: " << s << endl;
			break;
		}
	}
}
