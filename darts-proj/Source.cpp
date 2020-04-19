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
	Player playerOne;
		playerOne.setBullChance(71);
	Player playerTwo;
		playerTwo.setBullChance(73);
	Brain currBrain;

	int results[3][14] = {
		{0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7},
		{7, 7, 7, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	cout << "name player one: " << endl;
	string name;
	cin >> name;
	playerOne.setName(name);
	cout << "name player two: " << endl;
	cin >> name;
	playerTwo.setName(name);
	int gameno = 0;
	for (int k = 0; k < 1; k++)
	{
		//cout << "Game no. " << k + 1 << ": ";
		bool starterset = false;
		int starter = 1;
		while (!starterset)
		{
			if (starter == 1) {
				int hit = currBrain.returnGame()->throw_bull(playerOne.getBullChance());
				if (hit == 50) starterset = true;
			}
			else {
				int hit = currBrain.returnGame()->throw_bull(playerTwo.getBullChance());
				if (hit == 50) starterset = true;
			}
			starter *= -1;
		}
		if (starter == 1) starter = 2;
		else if (starter == -1) starter = 1;
		currBrain.starterSetter(starter, &playerOne, &playerTwo);

		//char userinput;
		//do {
			for (int setgames = 0; setgames < 13; setgames++)
			{
				for (int BO5games = 0; BO5games < 5; BO5games++)
				{
					//cout << endl;
					//cout << "--------------------------------------------------------" << endl << endl;
					//currBrain.starterDeclarer();
					gameno++;
					cout << "game no: " << gameno << endl;
					do {
						currBrain.returnGame()->round();
					} while (!currBrain.wincheck(playerOne) && !currBrain.wincheck(playerTwo));
					currBrain.winDeclarer();

					if (starter == 1) starter = 2;
					else if (starter == 2) starter = 1;
					currBrain.starterSetter(starter, &playerOne, &playerTwo);

					if ((playerOne.getCurrWins() == 3) || (playerTwo.getCurrWins() == 3))
					{
						currBrain.BO5won();
						break;
					}
				}
				//cout << endl;
				//cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
				if ((playerOne.getBO5Wins() == 7) || (playerTwo.getBO5Wins() == 7))
				{
					if (playerOne.getBO5Wins() == 7)
					{
						for (int i = 0; i < 14; i++)
						{
							if (results[1][i] == playerTwo.getBO5Wins()) {
								results[2][i]++;
								break;
							}
						}
					}
					else if (playerTwo.getBO5Wins() == 7)
					{
						for (int i = 0; i < 14; i++)
						{
							if (results[0][i] == playerOne.getBO5Wins()) {
								results[2][i]++;
								break;
							}
						}
					}
					currBrain.SETSwon();
					break;
				}
			}
			//cout << " ################################################################### " << endl << endl;

			//cout << "do u want to play another set of 13 matches? y or n" << endl;
			//cin >> userinput;
			//cout << endl;
		//while (userinput != 'n');
	}
	
	cout << endl;
	cout << playerOne.getName() << " : " << playerTwo.getName() << " : total" << endl;
	for (int k = 0; k < 14; k++)
	{
		float percentage = results[2][k] / 10000.f;
		percentage *= 100;
		cout << " " << results[0][k] << "  :  " << results[1][k] << "  :  " << results[2][k] << " - " << percentage << "%" << std::endl;
	}
	cout << endl << "Overall victories" << endl;
	int playerOneVictory = 0;
	int playerTwoVictory = 0;
	for (int k = 0; k < 14; k++)
	{
		if (k < 7) playerOneVictory += results[2][k];
		else if (k > 6) playerTwoVictory += results[2][k];
	}
	cout << playerOne.getName() << ": " << playerOneVictory << endl;
	cout << playerTwo.getName() << ": " << playerTwoVictory << endl;
}