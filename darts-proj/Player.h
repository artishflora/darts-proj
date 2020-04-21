#pragma once
#include <iostream>

class Player
{
	private: 
		int bullChance;
		int trebleChance;

		int numofthrows;
		int currbulls;
		int numofBO5wins;
		int numofSETwins;
		int currwins;
		int remaining;

		std::string name;

	public:
	//constr
		Player();
		~Player();

	//functions
		void endOfCurrGame();
		void endOfBO5();
		void endOfSet();

	//gettersetter
		void setBullChance(int chance);
		int getBullChance();
		void setTrebleChance(int chance);
		int getTrebleChance();

		void addThrow();
		int getThrows();
		void addBull();
		int getBulls();
		void addBO5Win();
		int getBO5Wins();
		void addSETWin();
		int getSETWins();
		void addCurrWin();
		int getCurrWins();
		void refreshRemaining(int hit);
		int getRemaining();
		void setName(std::string _name);
		std::string getName();
};

