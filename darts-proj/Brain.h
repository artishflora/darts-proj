#pragma once

#include "Player.h"
#include "Game.h"

class Brain
{
	private:
		int numOfRounds;
		int starter;
		Game currGame;
		Player* playerOne;
		Player* playerTwo;

	public:
		Brain();
		~Brain();

	//functs
		bool wincheck(Player& player);
		void starterSetter(int starter, Player* pOne, Player* pTwo);
		void winDeclarer();

	//gettersetter
		void incrRounds();
		int getRounds();
		Game* returnGame();
};

