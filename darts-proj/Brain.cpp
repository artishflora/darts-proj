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

bool Brain::wincheck(Player& player) //functions to confirm if player has won
{
	if (player.getRemaining() == 0) return true;
	else return false;
}

void Brain::starterSetter(int starter, Player* pOne, Player* pTwo) //function setting references of players
{
	//if player one starts its reference is saved into playerOne
	if (starter == 1) {
		playerOne = pOne;
		playerTwo = pTwo;
	}
	//if player two starts its reference is saved into playerOne
	else if (starter == 2) {
		playerOne = pTwo;
		playerTwo = pOne;
	}
	currGame.setPlayers(playerOne, playerTwo); //setting references of players in Game class ass well
}

void Brain::winDeclarer() //resetting necessary variables after a single 501 match is won
{
	//adding wins to correct player
	if (playerOne->getRemaining() == 0) {
		playerOne->addCurrWin();
	}
	else if (playerTwo->getRemaining() == 0) {
		playerTwo->addCurrWin();
	}
	//calling functions that reset values
	playerOne->endOfCurrGame();
	playerTwo->endOfCurrGame();
}

void Brain::BO5won() //resetting necessary values after three 501 matches are win by a player
{
	//increasing the number of Best of 5 wins of winning player
	//Best of 5 won = 3 501 wins
	if (playerOne->getCurrWins() == 3) {
		playerOne->addBO5Win();
	}
	else if (playerTwo->getCurrWins() == 3) {
		playerTwo->addBO5Win();
	}
	//calling functions that reset values
	playerOne->endOfBO5();
	playerTwo->endOfBO5();
}

void Brain::SETSwon() //resetting necessary variables after a full championship of best of 13 best of 5s are won
{
	//adding win to winning player
	//winner of best of 13 = 7 best of 5 wins
	if (playerOne->getBO5Wins() == 7) {
		playerOne->addSETWin();
	}
	else if (playerTwo->getBO5Wins() == 7) {
		playerTwo->addSETWin();
	}
	//calling functions that reset values
	playerOne->endOfSet();
	playerTwo->endOfSet();
}

Game* Brain::returnGame()
{
	Game* ref = &currGame;
	return ref;
}

