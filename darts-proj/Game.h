#pragma once
#include "Player.h"

class Game
{
	private:
		Player& Joe;
		Player& Sid;
	public:
		Game();
		~Game();

		void turn(Player& currplayer);
		void round(Player& player1, Player& player2);
};

