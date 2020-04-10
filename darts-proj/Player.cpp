#include "Player.h"
#include <ctime>​
#include <iomanip>​

Player::Player()
{
	bullChance = 70;
	trebleChance = 68;

	numofthrows = 0;
	currbulls = 0;
	numofBO5wins = 0;
	numofSETwins = 0;
	currwins = 0;
	remaining = 501;
}

Player::~Player()
{

}

int Player::targetCalculator()
{
	return (getRemaining() - 50);
}

void Player::endOfCurrGame()
{
	numofthrows = 0;
	currbulls = 0;
	remaining = 501;
}

void Player::endOfBO5()
{
	numofthrows = 0;
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