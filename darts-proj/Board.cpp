#include "Board.h"
#include <ctime>
#include <cstdlib>

Board::Board()
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