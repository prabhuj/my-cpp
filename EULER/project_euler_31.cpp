#include <iostream>

#define AMOUNT 5
#define COINS  8

int main()
{
	int coin_001 = 0;
	int coin_002 = 0;
	int coin_005 = 0;
	int coin_010 = 0;
	int coin_020 = 0;
	int coin_050 = 0;
	int coin_100 = 0;
	int coin_200 = 0;

	coin_001 = AMOUNT/1;
	for(;;)
	{
		coin_002 = 1;
	}

	int x[COINS] = {1,2,5,10,20,50,100,200};
	int comb[AMOUNT];

	comb[0] = 0;
	for(int i=1;i<=AMOUNT;i++)
	{
		comb[i] = 999999999;
		for(int j=0;j<COINS,j++)
		{
			if(x[j]<=i && comb[i-x[j]]+1 < comb[i])
			{
			}
		}
	}
}
