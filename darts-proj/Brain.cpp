#include "Brain.h"
#include <iostream>

Brain::Brain()
{
	numOfRounds = 0;
	playerOneWin = false;
	playerTwoWin = false;
	starter = 0;
}

Brain::~Brain()
{

}

bool Brain::wincheck(Player& player)
{
	if (player.getRemaining() == 0) return true;
	else return false;
}

void Brain::starterSetter(int starter, Player* pOne, Player* pTwo)
{
	if (starter == 1) {
		playerOne = pOne;
		playerTwo = pTwo;
	}
	else if (starter == 2) {
		playerOne = pTwo;
		playerTwo = pOne;
	}
	currGame.setPlayers(playerOne, playerTwo);
}

void Brain::winDeclarer()
{
	if (playerOne->getRemaining() == 0)
	{
		playerOne->addWin();
		std::cout << "Player 1 won! It took them " << playerOne->getThrows() << " throws. Player Two had " << playerTwo->getRemaining() << " points remaining. This is Player One's no. " << playerOne->getWins() << " victory." << std::endl;
		playerOne->endOfCurrGame();
		playerTwo->endOfCurrGame();
	}
	else if (playerTwo->getRemaining() == 0)
	{
		playerTwo->addWin();
		std::cout << "Player 2 won! It took them " << playerTwo->getThrows() << " throws. Player One had " << playerOne->getRemaining() << " points remaining. This is Player Two's no. " << playerTwo->getWins() << " victory." << std::endl;
		playerOne->endOfCurrGame();
		playerTwo->endOfCurrGame();
	}
}

void Brain::incrRounds()
{
	numOfRounds++;
}

int Brain::getRounds()
{
	return numOfRounds;
}

Game* Brain::returnGame()
{
	Game* ref = &currGame;
	return ref;
}

