#include "Board.h"
#include <ctime>
#include <cstdlib>

Board::Board()
{
	//Board neighbours including slot zero
	int bd[2][21] = { 
		{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
		{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1}
	};

	/*maxOneFinish = 50;
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
	}*/
}

Board::~Board()
{

}

int Board::throw_bull(int p) {

	//  Throw for the bull with accuracy p%  (20<p<85)

	int r = rand() % 100;

	if (r < (p - 20))
		return 50;
	else if (r < 85)
		return 25;
	else
		return 1 + rand() % 20;
}


int Board::throw_treble(int d, int p) {

	//  return result of throwing for treble d with accuracy p%  (o<90)
	int r = rand() % 100;

	if (r < p)
		return 3 * d;
	else if (r < 90)
		return d;
	else if (r < 93)
		return 3 * bd[0][d];
	else if (r < 96)
		return 3 * bd[1][d];
	else if (r < 98)
		return bd[0][d];
	else
		return bd[1][d];
}


int Board::throw_double(int d) {

	//  return result of throwing for double d with accuracy 80%

	int r = rand() % 100;

	if (r < 80)
		return 2 * d;
	else if (r < 85)
		return 0;
	else if (r < 90)
		return d;
	else if (r < 93)
		return 2 * bd[0][d];
	else if (r < 96)
		return 2 * bd[1][d];
	else if (r < 98)
		return bd[0][d];
	else
		return bd[1][d];
}



int Board::throw_single(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	int r = rand() % 100;

	if (d == 25) {		// outer  80%
		if (r < 80)
			return 25;
		else if (r < 90)
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (r < 88)
			return d;
		else if (r < 92)
			return bd[0][d];
		else if (r < 96)
			return bd[1][d];
		else if (r < 98)
			return 3 * d;
		else
			return 2 * d;
}

/*int Board::bullMiss()
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
}*/
