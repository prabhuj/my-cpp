#include <iostream>

using namespace std;

int word_count(char* str)
{
	int cnt = 0;
	bool word = false;
	while(*str)
	{
		if(*str == ' ' || *str == '\t' || *str == '\n')
		{
			word = false;
		}
		else
		{
			if(!word) cnt++;
			word = true;
		}
		str++;
	}
	return cnt;
}

int main()
{
	{ char x[] = ""   ;      cout << "[" << x << "] :: " << word_count(x) << endl; }

	{ char x[] = " "   ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a"  ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = " a" ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a " ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = " a ";      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a b";      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = " a b";     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a b ";     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = " a b ";    cout << "[" << x << "] :: " << word_count(x) << endl; }

	{ char x[] = "	"   ;    cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a"  ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "	a" ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a	" ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "	a	"; cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a	b";      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "	a	b"; cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a	b	"; cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "	a	b	"; cout << "[" << x << "] :: " << word_count(x) << endl; }

	{ char x[] = "\t"   ;    cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a"  ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\ta" ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\t" ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\ta\t";    cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\tb";     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\ta\tb";   cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\tb\t";   cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\ta\tb\t"; cout << "[" << x << "] :: " << word_count(x) << endl; }

	{ char x[] = "\n"   ;    cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a"  ;      cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\na" ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\n" ;     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\na\n";    cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\nb";     cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\na\nb";   cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "a\nb\n";   cout << "[" << x << "] :: " << word_count(x) << endl; }
	{ char x[] = "\na\nb\n"; cout << "[" << x << "] :: " << word_count(x) << endl; }
}
