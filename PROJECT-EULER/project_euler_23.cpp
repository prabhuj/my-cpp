/* PROBLEM 23

 A perfect number is a number for which the sum of its proper divisors is
 exactly equal to the number. For example, the sum of the proper divisors
 of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
 number.

 A number n is called deficient if the sum of its proper divisors is less
 than n and it is called abundant if this sum exceeds n.

 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 number that can be written as the sum of two abundant numbers is 24. By
 mathematical analysis, it can be shown that all integers greater than 28123
 can be written as the sum of two abundant numbers. However, this upper limit
 cannot be reduced any further by analysis even though it is known that the
 greatest number that cannot be expressed as the sum of two abundant numbers
 is less than this limit.

 Find the sum of all the positive integers which cannot be written as the sum
 of two abundant numbers.

*/

#include <iostream>

#define MAX 28123

int main()
{
	int x[MAX+1];
	for(int i=0;i<=MAX;i++)
	{
		if(i%2==0)
			continue;
		else if(i%5==0)
			continue;
		else
			x[i] = 1;
	}

	//int perfect_num = 0;
	//int abundant_num = 0;
	//int deficient_num = 0;
	//for(int i=1;i<=MAX;i++)
	//{
		//if(i%2==0 || i%5==0)
		//{
			//sum += i;
			//continue;
		//}

		//int divisor_sum = 1;
		//for(int j=2;j<=i/2;j++)
		//{
			//if(i%j==0)
				//divisor_sum += j;
		//}
		//if(i==divisor_sum)
		//{
			//perfect_num++;
			//cout << i << " :: " << divisor_sum << " :: is perfect" << endl;
		//}
		//if(divisor_sum>i && i%2==1)
		//{
			//abundant_num++;
			//cout << i << " :: " << divisor_sum << " :: is abundant" << endl;
		//}
		//if(divisor_sum<i)
		//{
			//deficient_num++;
			//cout << i << " :: " << divisor_sum << " :: is deficient" << endl;
		//}
	//}
	//cout << perfect_num << endl;
	//cout << abundant_num << endl;
	//cout << deficient_num << endl;
}
