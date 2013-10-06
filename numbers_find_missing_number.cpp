#include <iostream>

using namespace std;

void find_missing_number(int *arr, int n)
{
	int sum_expected = n * (n+1) / 2;
	int sum_actual = 0;
	int repeated = 0;
	for(int i=0;i<n;i++)
		sum_actual += arr[i];

	cout << "input ["; for(int i=0;i<n;i++) cout << arr[i] << " "; cout << "] ";

	for(int i=0;i<n;i++)
	{
		int index = (arr[i]>0)?arr[i]:-arr[i];
		if(arr[index-1] < 0)
		{
			repeated = index;
			break;
		}
		else
		{
			arr[index-1] *= -1;
		}
	}

	cout << " sum expected :: " << sum_expected;
	cout << " sum actual   :: " << sum_actual;
	cout << " repeated     :: " << repeated;
	cout << " missing      :: " << sum_expected - (sum_actual - repeated) << endl;
}

int main()
{
	{ int arr[10] = {1,2,3,4,5,6,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,1,3,4,5,6,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,1,4,5,6,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,1,5,6,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,1,6,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,5,1,7,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,5,6,1,8,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,5,6,7,1,9,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,5,6,7,8,1,10}; find_missing_number(arr, 10); }
	{ int arr[10] = {1,2,3,4,5,6,7,8,9,1 }; find_missing_number(arr, 10); }
	{ int arr[10] = {1,10,2,9,3,8,4,7,5,1}; find_missing_number(arr, 10); }
	return 0;
}
