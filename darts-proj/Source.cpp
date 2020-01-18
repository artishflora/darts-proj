#include <string>
#include <iostream>​
#include <cstdlib>​
#include <ctime>​
#include <iomanip>​
using namespace std;

class Player
{
public:
	int chance;
	int numofthrows;
	int currbulls;
	float avg10bulls;
	int numofwins;
};

bool bullseye(int playerchance)
{
	bool hit;
	int chance = rand() % 100 + 1;
	if (chance > playerchance) hit = false;
	else hit = true;
	return hit;
}
void turn(Player& currplayer)
{
	for (int k = 0; k < 3; k++)
	{
		currplayer.numofthrows++;
		bool hit;
		if (bullseye(currplayer.chance))
		{
			hit = true;
			currplayer.currbulls++;
			if (currplayer.currbulls == 10) break;
		}
		else hit = false;
	}
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
}

void round(Player& player1, Player& player2)
{
	turn(player1);
	if (player1.currbulls != 10) turn(player2);
}

int main()
{
	srand(time(0));
	Player Joe = {
	Joe.chance = 71,
	Joe.numofthrows = 0,
	Joe.avg10bulls = 0,
	Joe.currbulls = 0
	};
	Player Sid = {
	Sid.chance = 73,
	Sid.numofthrows = 0,
	Sid.avg10bulls = 0,
	Sid.currbulls = 0
	};
	for (int i = 0; i <= 10; i++)
	{
		//system("cls");​
		int numofrounds = 0;
		bool Joewin = false;
		bool Sidwin = false;
		int starter = 0;
		cout << "Which player should start? 1: Joe, 2: Sid" << endl;
		cin >> starter;
		cout << endl;
		while ((!Joewin) && (!Sidwin))
		{
			if (starter == 1) round(Joe, Sid);
			else if (starter == 2) round(Sid, Joe);
			numofrounds++;
			Joewin = wincheck(Joe);
			Sidwin = wincheck(Sid);
		}
		cout << "- - - - - - - - - - - -" << endl;
		if (starter == 1)
		{
			if (Joewin) {
				cout << "Joe has reached 10 bulls! It took him " << Joe.numofthrows << " trials and " << numofrounds << " rounds." << endl;
				cout << "Sid had " << Sid.currbulls << " with " << Sid.numofthrows << "trials." << endl;
				Joe.numofwins++;
			}
			else if (Sidwin) {
				cout << "Sid has reached 10 bulls! It took him " << Sid.numofthrows << " trials and " << numofrounds << " rounds." << endl;
				cout << "Joe had " << Joe.currbulls << " with " << Joe.numofthrows << "trials." << endl;
				Sid.numofwins++;
			}
		}
		else if (starter == 2)
		{
			if (Sidwin) {
				cout << "Sid has reached 10 bulls! It took him " << Sid.numofthrows << " trials and " << numofrounds << " rounds." << endl;
				cout << "Joe had " << Joe.currbulls << " with " << Joe.numofthrows << "trials." << endl;
				Sid.numofwins++;
			}
			else if (Joewin) {
				cout << "Joe has reached 10 bulls! It took him " << Joe.numofthrows << " trials and " << numofrounds << " rounds." << endl;
				cout << "Sid had " << Sid.currbulls << " with " << Sid.numofthrows << "trials." << endl;
				Joe.numofwins++;
			}
		}
		cout << endl;
		cout << "Current number of games: " << i + 1 << "." << endl;
		cout << "Joe has won " << Joe.numofwins << " games, while Sid has " << Sid.numofwins << " victories." << endl;
		cout << "- - - - - - - - - - - - - -" << endl;
		cout << endl;
		Joe.currbulls = 0;
		Sid.currbulls = 0;
		Joe.numofthrows = 0;
		Sid.numofthrows = 0;
	}
}