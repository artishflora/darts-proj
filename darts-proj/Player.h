#pragma once
class Player
{
	private: 
		int bullChance;
		int numChance;
		int numofthrows;
		int currbulls;
		int numofwins;
		int remaining;

	public:
	//constr
		Player();
		~Player();

	//functions
		int targetCalculator();
		void endOfCurrGame();

	//gettersetter
		void setBullChance(int chance);
		int getBullChance();
		void setNumChance(int chance);
		int getNumChance();
		void addThrow();
		int getThrows();
		void addBull();
		int getBulls();
		void addWin();
		int getWins();
		void refreshRemaining(int hit);
		int getRemaining();

/*
	//func
		void setChance(int);
		int getChance();
		bool wincheck(Player&);
		bool bullseye(int);
		*/
};

