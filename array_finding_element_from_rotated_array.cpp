#include <iostream>

using namespace std;

int find_index(int x[] , int start, int end, int e)
{
	int mid = (end+start)/2;
	cout << start << " :: " << mid << " :: " << end << endl;

	if(e == x[mid]) return mid;
	else if(e == x[start]) return start;
	else if(e == x[end]) return end;
	else if(start == end) return -1;
	if(e < x[start])
	{
		return find_index(x, mid+1, end-1, e);
	}
	else
	{
		return find_index(x, start+1, mid-1, e);
	}
}

int main()
{
	{int x[1] = {2}; cout << find_index(x, 0, 0, 2) << endl;}
	{int x[1] = {3}; cout << find_index(x, 0, 0, 2) << endl;}
	{int x[10] = {0,1,2,3,4,5,6,7,8,9}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {1,2,3,4,5,6,7,8,9,0}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {2,3,4,5,6,7,8,9,0,1}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {3,4,5,6,7,8,9,0,1,2}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {4,5,6,7,8,9,0,1,2,3}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {5,6,7,8,9,0,1,2,3,4}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {6,7,8,9,0,1,2,3,4,5}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {7,8,9,0,1,2,3,4,5,6}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {8,9,0,1,2,3,4,5,6,7}; cout << find_index(x, 0, 9, 2) << endl;}
	{int x[10] = {9,0,1,2,3,4,5,6,7,8}; cout << find_index(x, 0, 9, 2) << endl;}
}
