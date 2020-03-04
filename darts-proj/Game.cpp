#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::turn(Player& currplayer)
{
	for (int k = 0; k < 3; k++)
	{
		currplayer.numofthrows++;
		bool hit;
		if (currplayer.bullseye(currplayer.getChance()))
		{
			hit = true;
			currplayer.currbulls++;
			if (currplayer.currbulls == 10) break;
		}
		else hit = false;
	}
}

void Game::round(Player& player1, Player& player2)
{
	turn(player1);
	if (player1.currbulls != 10) turn(player2);
}
