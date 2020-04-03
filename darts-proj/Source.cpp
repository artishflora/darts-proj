#include <string>
#include <iostream>​
#include <cstdlib>​
#include <ctime>​
#include <iomanip>​
#include "Player.h"
#include "Brain.h"

using namespace std;

/*
bool bullseye(int playerchance)
{
	bool hit;
	int chance = rand() % 100 + 1;
	if (chance > playerchance) hit = false;
	else hit = true;
	return hit;
	return false;
}
bool wincheck(Player& currplayer)
{
	if (currplayer.currbulls == 10)
	{
		if (currplayer.avg10bulls != 0) {
			currplayer.avg10bulls += currplayer.numofthrows;
			currplayer.avg10bulls /= 2;
		}
		else currplayer.avg10bulls = currplayer.numofthrows;
		return true;
	}
	else return false;
	return false;
}
void turn(Player& currplayer)
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
void round(Player& player1, Player& player2)
{
	turn(player1);
	if (player1.currbulls != 10) turn(player2);
}
*/

int main()
{
	srand(time(0));
	Player Joe;
		Joe.setBullChance(71);
		Joe.setNumChance(80);
	Player Sid;
		Sid.setBullChance(73);
		Sid.setNumChance(80);
	Brain currBrain;

	char userinput;
	do {
		int starter = 0;
		cout << "which one should start? joe 1, sid 2" << endl;
		cin  >> starter;
		currBrain.starterSetter(starter, &Joe, &Sid);

		do {
			currBrain.returnGame()->round();
		}while (!currBrain.wincheck(Joe) && !currBrain.wincheck(Sid));
		currBrain.winDeclarer();

		cout << "do u want to play another? y or n" << endl;
		cin >> userinput;
	} while (userinput != 'n');
}