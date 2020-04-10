#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game()
{

}

Game::~Game()
{

}

void Game::turn(Player* currPlayer)
{
	int currturn = 0;
	for (int k = 0; k < 3; k++)
	{
		//std::cout << "Turn " << k+1 << ":" << std::endl;

		int hit = 0;
		currPlayer->addThrow();

		if (currPlayer->getRemaining() >= 120) {
			hit = throw_treble(20, currPlayer->getTrebleChance());
		}
		else if ((currPlayer->getRemaining() >= 100) || (currPlayer->getRemaining() == 50)) {
			hit = throw_bull(currPlayer->getBullChance());
			if (hit == 50) currPlayer->addBull();
		}
		else if (currPlayer->getRemaining() > 50) {
			int current = currPlayer->getRemaining() - 50;
			if (current <= 20) {
				hit = throw_single(current);
			}
			else if ((current % 2 == 0) && (current / 2 <= 20)) {
				hit = throw_double(current / 2);
			}
			else if (current / 3 < 17) {
				hit = throw_treble(current / 3, currPlayer->getTrebleChance());
			}
		}
		else if (currPlayer->getRemaining() > 0) {
			if (currPlayer->getRemaining() > 40) {
				int current = currPlayer->getRemaining() - 40;
				hit = throw_single(current);
			}
			else if (currPlayer->getRemaining() % 2 != 0) {
				hit = throw_single(1);
			}
			else if (currPlayer->getRemaining() % 2 == 0){
				hit = throw_double(currPlayer->getRemaining() / 2);
			}
		}
		currturn += hit;
		//std::cout << currPlayer->getName() << " hit the number " << hit << " !" << std::endl;
		if (currPlayer->getRemaining() - currturn == 1 || currPlayer->getRemaining() - currturn < 0) break;
		if (currPlayer->getRemaining() - currturn == 0) break;
	}
	if (currPlayer->getRemaining()-currturn != 1 && currPlayer->getRemaining()-currturn > -1) currPlayer->refreshRemaining(currturn);
	//std::cout << "Their remaining points are: " << currPlayer->getRemaining() << std::endl;
	//if (currPlayer->getRemaining() == 0) std::cout << currPlayer->getName() << " won this game!" << std::endl;
}

void Game::round()
{
	if (playerTwo->getRemaining() != 0) {
		//std::cout << std::endl;
		//std::cout << playerOne->getName() << "'s turn." << std::endl;

		turn(playerOne);
	}
	if (playerOne->getRemaining() != 0) {
		//std::cout << std::endl;
		//std::cout << playerTwo->getName() <<"'s turn." << std::endl;

		turn(playerTwo);
	}
}

void Game::setPlayers(Player* one, Player* two)
{
	playerOne = one;
	playerTwo = two;
}

int Game::throw_bull(int p) {

	//  Throw for the bull with accuracy p%  (20<p<85)

	int r = rand() % 100;

	if (r < (p - 20))
		return 50;
	else if (r < 85)
		return 25;
	else
		return 1 + rand() % 20;
}


int Game::throw_treble(int d, int p) {

	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

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


int Game::throw_double(int d) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
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



int Game::throw_single(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
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