#pragma once
class Player
{
	private: 
		int chance;

	public:
		int numofthrows;
		int currbulls;
		float avg10bulls;
		int numofwins;

	//constr
		Player();

	//func
		void setChance(int);
		int getChance();
		bool wincheck(Player&);
		bool bullseye(int);
};

