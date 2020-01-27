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
	
		void setChance(int);
		int getChance();

	//func
		bool wincheck(Player&);
		bool bullseye(int);
};

