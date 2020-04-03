#include "Player.h"
#include <ctime>​
#include <iomanip>​

Player::Player()
{
	bullChance = 70;
	numChance = 80;
	numofthrows = 0;
	currbulls = 0;
	numofwins = 0;
	remaining = 301;
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
	remaining = 301;
}

void Player::setBullChance(int chance)
{
	bullChance = chance;
}

int Player::getBullChance()
{
	return bullChance;
}

void Player::setNumChance(int chance)
{
	numChance = chance;
}

int Player::getNumChance()
{
	return numChance;
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

void Player::addWin()
{
	numofwins++;
}

int Player::getWins()
{
	return numofwins;
}

void Player::refreshRemaining(int hit)
{
	remaining -= hit;
}

int Player::getRemaining()
{
	return remaining;
}


/*
void Player::setChance(int newChance)
{
	chance = newChance;
}

int Player::getChance()
{
	return chance;
}

bool Player::wincheck(Player& currplayer)
{
	if (currplayer.currbulls == 10)
	{
		if (currplayer.avg10bulls != 0) {
			currplayer.avg10bulls += currplayer.numofthrows;
			currplayer.avg10bulls /= 2;
		}
		else currplayer.avg10bulls = currplayer.numofthrows;
		return true;
	}
	else return false;
}

bool Player::bullseye(int playerchance)
{
	bool hit;
	int chance = rand() % 100 + 1;
	if (chance > playerchance) hit = false;
	else hit = true;
	return hit;
}*/