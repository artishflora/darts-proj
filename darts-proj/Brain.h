#pragma once

#include "Player.h"
#include "Game.h"

class Brain
{
	private:
		int numofrounds;
		bool joeWin;
		bool sidWin;
		int starter;
		Player Joe;
		Player Sid;
		Game currGame;

	public:
		Brain();
		~Brain();

};

