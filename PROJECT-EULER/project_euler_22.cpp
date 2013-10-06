#include <iostream>
#include <stdio.h>

int main()
{
	char file[40];
	scanf("%s",file);
	FILE* fp = fopen(file,"r");
	char name[40];
	long long total = 0;
	int line = 1;
	while(!feof(fp))
	{
		fscanf(fp,"%s",name);
		int val = 0;
		//cout << name << endl;
		for(int i=0;name[i]!='\0';i++)
		{
			val += (name[i]-'0')-16;
			cout << name[i] << "(" << (name[i]-'0')-16 << ")";
		}
		cout << " = " << val  << " : " << line << endl;
		total += (val*line);
		line++;
	}
	fclose(fp);
	cout << total << endl;
}
