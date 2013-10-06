#include <iostream>
#include <string>
#include <vector>

string convert(int num)
{
	string numbers[1001];

	for(int i=0;i<1001;i++)
		numbers[i] = " ";

	numbers[0]  = "zero";
	numbers[1]  = "one";
	numbers[2]  = "two";
	numbers[3]  = "three";
	numbers[4]  = "four";
	numbers[5]  = "five";
	numbers[6]  = "six";
	numbers[7]  = "seven";
	numbers[8]  = "eight";
	numbers[9]  = "nine";
	numbers[10] = "ten";
	numbers[11] = "eleven";
	numbers[12] = "twelve";
	numbers[13] = "thirteen";
	numbers[14] = "fourteen";
	numbers[15] = "fifteen";
	numbers[16] = "sixteen";
	numbers[17] = "seventeen";
	numbers[18] = "eighteen";
	numbers[19] = "nineteen";
	numbers[20] = "twenty";
	numbers[30] = "thirty";
	numbers[40] = "forty";
	numbers[50] = "fifty";
	numbers[60] = "sixty";
	numbers[70] = "seventy";
	numbers[80] = "eighty";
	numbers[90] = "ninety";
	numbers[100] = "onehundred";
	numbers[200] = "twohundred";
	numbers[300] = "threehundred";
	numbers[400] = "fourhundred";
	numbers[500] = "fivehundred";
	numbers[600] = "sixhundred";
	numbers[700] = "sevenhundred";
	numbers[800] = "eighthundred";
	numbers[900] = "ninehundred";
	numbers[1000] = "onethousand";

	if((numbers[num].length()) != 1)
	{
		return numbers[num];
	}
	//return "coding";

	string word("");

	// one's place
	if(num%100 <= 20)
	{
		word = numbers[num%100];
		num = num/100;
	}
	else
	{
		int x_1 = num%10;
		if(x_1)
			word += numbers[x_1];

		num = num/10;

		// tens's place
		int x_10 = num%10;
		if(x_10)
			word = numbers[x_10*10] + word;

		if(num<10)
			return word;

		num = num/10;
	}

	// hund's place
	int x_100 = num%10;
	word = numbers[x_100] + "hundredand" + word;

	return word;
}

int main()
{
	int num = 1000;
	long long int cnt = 0;
	for(int i=1;i<=num;i++)
	{
		cnt += convert(i).length();
		cout << i << " :: " << convert(i) << " :: " << convert(i).length() << endl;;
	}
	cout << cnt << endl;
}
