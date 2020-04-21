#include <string>
#include <iostream>​
#include <cstdlib>​
#include <ctime>​
#include <iomanip>​
#include "Player.h"
#include "Brain.h"
using namespace std;

int main()
{
	//initialising components
	srand(time(0));
	Player playerOne;
	Player playerTwo;
	Brain currBrain;

	//array to save statistical results
	int results[3][14] = {
		{0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7},
		{7, 7, 7, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	//setting up players requiring user input
	cout << "name player one: ";
	string name;
	cin >> name;
	playerOne.setName(name);
	cout << "set player one bull chance between 0-100: ";
	int chance;
	cin >> chance;
	playerOne.setBullChance(chance);
	cout << "set player one treble chance between 0-100: ";
	cin >> chance;
	cout << endl;
	playerOne.setTrebleChance(chance);
	cout << "name player two: ";
	cin >> name;
	playerTwo.setName(name);
	cout << "set player two bull chance between 0-100: ";
	cin >> chance;
	playerTwo.setBullChance(chance);
	cout << "set player two treble chance between 0-100: ";
	cin >> chance;
	cout << endl;
	playerTwo.setTrebleChance(chance);
	cout << "Computing 10000 simulations..." << endl;

	//computing 10000 World Championship - like matches
	for (int k = 0; k < 10000; k++)
	{
		//each best of 13 starts with selecting the starter player throwing closest to bull
		bool starterset = false;
		int starter = 1;
		//throwing until one of them throws a bull
		while (!starterset)
		{
			if (starter == 1) {
				int hit = currBrain.returnGame()->returnBoard()->throw_bull(playerOne.getBullChance());
				if (hit == 50) starterset = true;
			}
			else {
				int hit = currBrain.returnGame()->returnBoard()->throw_bull(playerTwo.getBullChance());
				if (hit == 50) starterset = true;
			}
			starter *= -1;
		}
		//setting up starter players
		if (starter == 1) starter = 2; //Player Two
		else if (starter == -1) starter = 1; //Player One
		//starter player pointers passed to Brain class
		currBrain.starterSetter(starter, &playerOne, &playerTwo);

		//starting best of 13
		for (int setgames = 0; setgames < 13; setgames++)
		{
			//starting best of 5
			for (int BO5games = 0; BO5games < 5; BO5games++)
			{
				//playing one match until one of the scores reduces to 0
				do {
					currBrain.returnGame()->round();
				} while (!currBrain.wincheck(playerOne) && !currBrain.wincheck(playerTwo));
				currBrain.winDeclarer(); //resets necessary values for next game

				//changing starters at the beginning of the next game
				if (starter == 1) starter = 2;
				else if (starter == 2) starter = 1;
				//repassing pointers with changed starter
				currBrain.starterSetter(starter, &playerOne, &playerTwo);

				//best of 5 won
				if ((playerOne.getCurrWins() == 3) || (playerTwo.getCurrWins() == 3))
				{
					//resetting necessary values and saving win
					currBrain.BO5won();
					break;
				}
			}

			//best of 13 won
			if ((playerOne.getBO5Wins() == 7) || (playerTwo.getBO5Wins() == 7))
			{
				if (playerOne.getBO5Wins() == 7)
				{
					//saving win in the statistical array of results
					for (int i = 0; i < 14; i++)
					{
						//checking player two's row because player one's is 7
						if (results[1][i] == playerTwo.getBO5Wins()) {
							results[2][i]++; //increasing number of wins with current score by one
							break;
						}
					}
				}
				else if (playerTwo.getBO5Wins() == 7)
				{
					//saving win in the statistical array of results
					for (int i = 0; i < 14; i++)
					{
						//checking player one's row because player two's is 7
						if (results[0][i] == playerOne.getBO5Wins()) {
							results[2][i]++; //increasing number of wins with current score by one
							break;
						}
					}
				}
				//resetting necessary values and saving best of 13 win
				currBrain.SETSwon();
				break;
			}
		}
	}
	
	cout << endl;
	//printing the statistical array of results
	cout << playerOne.getName() << " : " << playerTwo.getName() << " : total" << endl; //print names of players
	for (int k = 0; k < 14; k++)
	{
		//calculate percentages of results
		float percentage = results[2][k] / 10000.f;
		percentage *= 100;
		//print results, number of instances of that result, percentage of that result
		cout << " " << results[0][k] << "  :  " << results[1][k] << "  :  " << results[2][k] << " - " << percentage << "%" << std::endl;
	}
	//printing number of wins each player acquired
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