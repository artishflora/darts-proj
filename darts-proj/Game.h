#pragma once
#include "Player.h"
#include "Board.h"

class Game
{
	private:
		Player pOne;
		Player pTwo;
		Player* playerOne;
		Player* playerTwo;
		Board currBoard;

	public:
		Game();
		~Game();

		void turn(Player* currPlayer);
		void round();
		void setPlayers(Player* one, Player* two);

		Board* returnBoard();
};

