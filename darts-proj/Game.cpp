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
	for (int k = 0; k < 3; k++)
	{
		std::cout << "Turn " << k << ":" << std::endl;

		int hit = 0;
		currPlayer->addThrow();
		if (currPlayer->getRemaining() >= 100)
		{
			int chance = rand() % 100 + 1;
			if (chance <= currPlayer->getBullChance())
			{
				currPlayer->addBull();
				currPlayer->refreshRemaining(50);

				std::cout << "Player hit a bull!" << std::endl;
				std::cout << "Their remaining points are: " << currPlayer->getRemaining() << std::endl;
			}
			else
			{
				hit = currBoard.bullMiss();
				currPlayer->refreshRemaining(hit);

				std::cout << "Player hit the number " << hit << " !" << std::endl;
				std::cout << "Their remaining points are: " << currPlayer->getRemaining() << std::endl;
			}
		}
		else if (currPlayer->getRemaining() >= 70)
		{
			hit = currBoard.numberTarget(20, currPlayer->getNumChance());
			currPlayer->refreshRemaining(hit);

			std::cout << "Player hit the number " << hit << " !" << std::endl;
			std::cout << "Their remaining points are: " << currPlayer->getRemaining() << std::endl;
		}
		else if (currPlayer->getRemaining() > 50)
		{
			int target = currPlayer->targetCalculator();
			hit = currBoard.numberTarget(target, currPlayer->getNumChance());
			std::cout << "Player hit the number " << hit << " !" << std::endl;
			if ((currPlayer->getRemaining() - hit) >= 50) {
				currPlayer->refreshRemaining(hit);
				std::cout << "Their remaining points are: " << currPlayer->getRemaining() << std::endl;
			}
			else std::cout << "Their score went under 50. The remaining is still " << currPlayer->getRemaining() << std::endl;
		}
		else if (currPlayer->getRemaining() == 50)
		{
			int chance = rand() % 100 + 1;
			if (chance <= currPlayer->getBullChance())
			{
				currPlayer->addBull();
				currPlayer->refreshRemaining(50);
				std::cout << "The player hit the bull! Game won!" << std::endl << std::endl;
				break;
			}
		}
	}
}

void Game::round()
{
	if (playerTwo->getRemaining() != 0) {
		std::cout << std::endl;
		std::cout << "Player One's turn." << std::endl;

		turn(playerOne);
	}
	if (playerOne->getRemaining() != 0) {
		std::cout << std::endl;
		std::cout << "Player Two's turn." << std::endl;

		turn(playerTwo);
	}
}

void Game::setPlayers(Player* one, Player* two)
{
	playerOne = one;
	playerTwo = two;
}

/*
void Game::turn(Player& currplayer)
{
	for (int k = 0; k < 3; k++)
	{
		currPlayer->numofthrows++;
		bool hit;
		if (currPlayer->bullseye(currPlayer->getChance()))
		{
			hit = true;
			currPlayer->currbulls++;
			if (currPlayer->currbulls == 10) break;
		}
		else hit = false;
	}
}

void Game::round(Player& player1, Player& player2)
{
	turn(player1);
	if (player1.currbulls != 10) turn(player2);
}
*/