#include "Board.h"
#include <ctime>
#include <cstdlib>

Board::Board()
{
	maxOneFinish = 50;
	maxTwoFinish = 0;
	maxThreeFinish = 0;
	for (int k = 0; k < 21; k++) twoDartFinishes[k][0] = finishers[k];
	for (int k = 0; k < 43; k++) twoDartFinishes[0][k] = allNums[k];
	for (int k = 1; k < 21; k++)
	{
		for (int i = 1; i < 43; i++)
		{
			twoDartFinishes[k][i] = twoDartFinishes[k][0] + twoDartFinishes[0][i];
			if (twoDartFinishes[k][i] > maxTwoFinish) maxTwoFinish = twoDartFinishes[k][i];
		}
	}

	for (int k = 0; k < 21; k++) threeDartFinishes[k][0][0] = finishers[k];
	for (int k = 0; k < 43; k++) threeDartFinishes[0][k][0] = allNums[k];
	for (int k = 0; k < 43; k++) threeDartFinishes[0][0][k] = allNums[k];
	for (int k = 1; k < 21; k++)
	{
		for (int i = 1; i < 43; i++)
		{
			for (int l = 1; l < 43; l++)
			{
				threeDartFinishes[k][i][l] = threeDartFinishes[k][0][0] + threeDartFinishes[0][i][0] + threeDartFinishes[0][0][l];
				if (threeDartFinishes[k][i][l] > maxThreeFinish) maxThreeFinish = threeDartFinishes[k][i][l];
			}
		}
	}
}

void reverse(int arr[], int n)
{

}

Board::~Board()
{

}

int Board::bullMiss()
{
	return (rand() % 20 + 1);
}

int Board::numberTarget(int target, int numChance)
{
	int chance = rand() % 100 + 1;
	if (chance <= numChance) return target;//the number targeted
	else if (chance <= 100-((100 - numChance) / 2)) return numberNeighbours[1][target];
	else if (chance <= 100) return numberNeighbours[2][target];
}

int Board::fourThrow(int currScore)
{
	for (int k = 1; k < 21; k++)
	{
		for (int i = 1; i < 43; i++)
		{
			for (int l = 1; l < 43; l++)
			{
				for (int currThrow : finishers)
				{
					if (currThrow + threeDartFinishes[k][i][l] == currScore) return currThrow;
				}
			}
		}
	}
}

int Board::threeThrow(int currScore)
{
	for (int k = 1; k < 21; k++)
	{
		for (int i = 1; i < 43; i++)
		{
			for (int l = 1; l < 43; l++)
			{
				if (threeDartFinishes[k][i][l] == currScore) return threeDartFinishes[k][i][0];
			}
		}
	}
}

int Board::twoThrow(int currScore)
{
	for (int k = 1; k < 21; k++)
	{
		for (int i = 1; i < 43; i++)
		{
			if (twoDartFinishes[k][i] == currScore) return twoDartFinishes[k][0];
		}
	}
}

int Board::getMaxOne()
{
	return maxOneFinish;
}

int Board::getMaxTwo()
{
	return maxTwoFinish;
}

int Board::getMaxThree()
{
	return maxThreeFinish;
}
