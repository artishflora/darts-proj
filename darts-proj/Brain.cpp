#include "Brain.h"
#include <iostream>

Brain::Brain()
{
	numOfRounds = 0;
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
		playerOne->addCurrWin();
		//std::cout << playerOne->getName() << " won! It took them " << playerOne->getThrows() << " throws. " << std::endl << playerTwo->getName() << " had " << playerTwo->getRemaining() << " points remaining. This is " << playerOne->getName() << "'s no. " << playerOne->getCurrWins() << " victory in the current Best of 5." << std::endl;
	}
	else if (playerTwo->getRemaining() == 0)
	{
		playerTwo->addCurrWin();
		//std::cout << playerTwo->getName() << " won! It took them " << playerTwo->getThrows() << " throws. " << std::endl << playerOne->getName() << " had " << playerOne->getRemaining() << " points remaining. This is " << playerTwo->getName() << "'s no. " << playerTwo->getCurrWins() << " victory in the current Best of 5." << std::endl;
	}
	playerOne->endOfCurrGame();
	playerTwo->endOfCurrGame();
}

void Brain::BO5won()
{
	if (playerOne->getCurrWins() == 3)
	{
		playerOne->addBO5Win();
		//std::cout << playerOne->getName() << " won the Best of 5 with " << playerOne->getCurrWins() << " game victories!" << std::endl;
		//std::cout << playerOne->getName() << " now has " << playerOne->getBO5Wins() << " Best of 5 victories while " << playerTwo->getName() << " has " << playerTwo->getBO5Wins() << " Best of 5 victories." << std::endl;
	}
	else if (playerTwo->getCurrWins() == 3)
	{
		playerTwo->addBO5Win();
		//std::cout << playerTwo->getName() << " won the Best of 5 with " << playerTwo->getCurrWins() << " game victories!" << std::endl;
		//std::cout << playerTwo->getName() << " now has " << playerTwo->getBO5Wins() << " Best of 5 victories while " << playerOne->getName() << " has " << playerOne->getBO5Wins() << " Best of 5 victories." << std::endl;
	}
	playerOne->endOfBO5();
	playerTwo->endOfBO5();
}

void Brain::SETSwon()
{
	if (playerOne->getBO5Wins() == 7)
	{
		playerOne->addSETWin();
		//std::cout << playerOne->getName() << " won the Set of 13 games with " << playerOne->getBO5Wins() << " Best of 5 victories!" << std::endl;
		//std::cout << playerOne->getName() << " now has " << playerOne->getSETWins() << " Set of 13 games victories while " << playerTwo->getName() << " has " << playerTwo->getSETWins() << " Set of 13 games victories." << std::endl;
		//std::cout << playerOne->getName() << " won with " << playerOne->getBO5Wins() << " : " << playerTwo->getBO5Wins() << std::endl;
	}
	else if (playerTwo->getBO5Wins() == 7)
	{
		playerTwo->addSETWin();
		//std::cout << playerTwo->getName() << " won the Set of 13 games with " << playerTwo->getBO5Wins() << " Best of 5 victories!" << std::endl;
		//std::cout << playerTwo->getName() << " now has " << playerTwo->getSETWins() << " Set of 13 games victories while " << playerOne->getName() << " has " << playerOne->getSETWins() << " Set of 13 games victories." << std::endl;
		//std::cout << playerTwo->getName() << " won with " << playerTwo->getBO5Wins() << " : " << playerOne->getBO5Wins() << std::endl;
	}
	playerOne->endOfSet();
	playerTwo->endOfSet();
}

void Brain::starterDeclarer()
{
	std::cout << playerOne->getName() << " starts this game!" << std::endl;
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

