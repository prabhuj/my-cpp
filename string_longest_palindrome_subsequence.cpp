#include <iostream>

using namespace std;

int max(int x, int y)
{
	return (x>y)?x:y;
}

int longest_palindrome_length(char* str, int start, int end)
{
	cout << str << " :: " << start << " :: " << end << endl;
	if(start == end)
		return 1;

	if(str[start] == str[end] && start+1 == end)
		return 2;

	if(str[start] == str[end])
		return longest_palindrome_length(str, start+1, end-1) + 2;

	return max(longest_palindrome_length(str, start+1, end), longest_palindrome_length(str, start, end-1));
}

int main()
{
	char str[] = "abcba";
	cout << longest_palindrome_length(str, 0, strlen(str)) << endl;
	return 0;
}
