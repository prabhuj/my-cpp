#include <iostream>
#include <algorithm>

using namespace std;

bool check_anagram(char* str1, char* str2)
{
	if(strlen(str1) != strlen(str2))
		return false;

	int count[256];
	fill(count, count+256, 0);
	
	while(*str1 != '\0')
	{
		count[*str1]++;
		count[*str2]--;
		str1++; str2++;
	}

	for(int i=0;i<256;i++)
	{
		if(count[i]) return false;
	}
	return true;
}

int main()
{
	cout << check_anagram("prabhu jayaraman", "jayaraman prabhu") << endl;
	cout << check_anagram("prabhujayaramanx", "jayaraman prabhu") << endl;
	cout << check_anagram("", "") << endl;
	return 0;
}
