#include "Player.h"
#include <ctime>​
#include <iomanip>​

Player::Player()
{
	//setting up initial values
	bullChance = 70;
	trebleChance = 68;

	currbulls = 0; //saving number of bulls in a 501 match by palyer
	numofBO5wins = 0; //how many best of 5s the player has won in the current best of 13
	numofSETwins = 0; // how many best of 13s the player has won
	currwins = 0; // how many wins the player has in the current best of 5
	remaining = 501; //score
}

Player::~Player()
{

}

void Player::endOfCurrGame()
{
	currbulls = 0;
	remaining = 501;
}

void Player::endOfBO5()
{
	currbulls = 0;
	remaining = 501;
	currwins = 0;
}

void Player::endOfSet()
{
	numofthrows = 0;
	currbulls = 0;
	remaining = 501;
	currwins = 0;
	numofBO5wins = 0;
}

void Player::setBullChance(int chance)
{
	bullChance = chance;
}

int Player::getBullChance()
{
	return bullChance;
}

void Player::setTrebleChance(int chance)
{
	trebleChance = chance;
}

int Player::getTrebleChance()
{
	return trebleChance;
}

void Player::addThrow()
{
	numofthrows++;
}

int Player::getThrows()
{
	return numofthrows;
}

void Player::addBull()
{
	currbulls++;
}

int Player::getBulls()
{
	return currbulls;
}

void Player::addBO5Win()
{
	numofBO5wins++;
}

int Player::getBO5Wins()
{
	return numofBO5wins;
}

void Player::addSETWin()
{
	numofSETwins++;
}

int Player::getSETWins()
{
	return numofSETwins;
}

void Player::addCurrWin()
{
	currwins++;
}

int Player::getCurrWins()
{
	return currwins;
}

void Player::refreshRemaining(int hit)
{
	remaining -= hit;
}

int Player::getRemaining()
{
	return remaining;
}

void Player::setName(std::string _name)
{
	name = _name;
}

std::string Player::getName()
{
	return name;
}