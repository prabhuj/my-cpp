/*Two players A & B play pots of gold game where there are pots of gold arranged in a line, each containing some gold coins. The players can see how many coins are there in each gold pot. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player which has a higher number of coins at the end. The objective is to "maximize" the number of coins collected by A, assuming B also plays optimally. A starts the game.*/

#include <iostream>

using namespace std;

int min(int i, int j)
{
	return (i<j)?i:j;
}

int max(int i, int j)
{
	return (i>j)?i:j;
}

int find_max_coins(int pots[], int start, int end)
{
	if(start > end)
		return 0;
	else
		return max(
			(pots[start] + min(find_max_coins(pots, start+1, end-1), find_max_coins(pots, start+2, end) ) ),
			(pots[end]   + min(find_max_coins(pots, start+1, end-1), find_max_coins(pots, start, end-2) ) )
			);
}

int main()
{
	int pots[] = {1,2,3,4,5};
	cout << find_max_coins(pots, 0, 4) << endl;
	return 0;
}
