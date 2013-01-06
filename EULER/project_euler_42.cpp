#include<iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	char filename[40];

	scanf("%s",filename);

	FILE* fp = fopen(filename,"r");

	if(fp == NULL)
	{
		cerr << "Could not open file" << endl;
		exit(1);
	}

	char word[20];
	int triangle_words = 0;

	while(fscanf(fp,"%s",word) != EOF)
	{
		int word_value = 0;

		for(int i=0;word[i]!='\0';i++)
		{
			word_value += ((word[i]-'0')-16);
		}

		double x = 0, y = 0;
		int a = 1, b = 1, c = -(word_value*2);

		x=((-b+(sqrt((b*b)-(4*a*c)))))/(2*a);
		y=((-b-(sqrt((b*b)-(4*a*c)))))/(2*a);

		//cout << word << " :: " << word_value << " => " << x << " & " << y << endl;

		if(x==(int)x)
		{
			triangle_words++;
		}
	}
	cout << triangle_words << endl;

	fclose(fp);

	return 0;
}
