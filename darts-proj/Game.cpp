#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game()
{

}

Game::~Game()
{

}

//one player's turn of 3 throws in current 501 match
void Game::turn(Player* currPlayer)
{
	int currturn = 0; //all points the player has thrown
	for (int k = 0; k < 3; k++) //for three throws
	{
		int hit = 0; //result of throw
		currPlayer->addThrow(); //save throw
		//logical requirements based on which the appropriate target is chosen
		//once target is chosen dart is thrown using the given functions

		/*if (k == 2 && currPlayer->getRemaining() <= currBoard.getMaxThree() + 50)
		{
			int target = currBoard.fourThrow(currPlayer->getRemaining());
			if (target > 20 && target != 50) {
				if (target % 2 == 0) hit = throw_double(target / 2);
				else if (target % 3 == 0) hit = throw_treble(target / 3, currPlayer->getTrebleChance());
				else if (target == 25) hit = throw_single(25);
			}
			else if (target == 50) {
				hit = throw_bull(currPlayer->getBullChance());
				if (hit == 50) currPlayer->addBull();
			}
			else {
				hit = throw_single(target);
			}
		}
		else if (k == 0 && currPlayer->getRemaining() <= currBoard.getMaxThree())
		{
			int target = currBoard.threeThrow(currPlayer->getRemaining());
			if (target > 20 && target != 50) {
				if (target % 2 == 0) hit = throw_double(target / 2);
				else if (target % 3 == 0) hit = throw_treble(target / 3, currPlayer->getTrebleChance());
				else if (target == 25) hit = throw_single(25);
			}
			else if (target == 50) {
				hit = throw_bull(currPlayer->getBullChance());
				if (hit == 50) currPlayer->addBull();
			}
			else {
				hit = throw_single(target);
			}
		}*/
		//else 
		if (currPlayer->getRemaining() >= 120) {
			hit = currBoard.throw_treble(20, currPlayer->getTrebleChance());
		}
		/*else if (k == 1 && currPlayer->getRemaining() <= currBoard.getMaxTwo())
		{
			int target = currBoard.twoThrow(currPlayer->getRemaining());
			if (target > 20 && target != 50) {
				if (target % 2 == 0) hit = throw_double(target / 2);
				else if (target % 3 == 0) hit = throw_treble(target / 3, currPlayer->getTrebleChance());
				else if (target == 25) hit = throw_single(25);
			}
			else if (target == 50) {
				hit = throw_bull(currPlayer->getBullChance());
				if (hit == 50) currPlayer->addBull();
			}
			else {
				hit = throw_single(target);
			}
		}*/
		else if ((currPlayer->getRemaining() >= 100) || (currPlayer->getRemaining() == 50)) {
			hit = currBoard.throw_bull(currPlayer->getBullChance());
			if (hit == 50) currPlayer->addBull();
		}
		else if (currPlayer->getRemaining() == 74) {
			hit = currBoard.throw_treble(14, currPlayer->getTrebleChance());
		}
		else if (currPlayer->getRemaining() > 50)
		{
			int current = currPlayer->getRemaining() - 50;
			if (current <= 20) {
				hit = currBoard.throw_single(current);
			}
			else if ((current % 2 == 0) && (current / 2 <= 20)) {
				hit = currBoard.throw_double(current / 2);
			}
			else if (current / 3 < 17) {
				hit = currBoard.throw_treble(current / 3, currPlayer->getTrebleChance());
			}
		}
		else if (currPlayer->getRemaining() > 0)
		{
			if (currPlayer->getRemaining() > 40) {
				int current = currPlayer->getRemaining() - 40;
				hit = currBoard.throw_single(current);
			}
			else if (currPlayer->getRemaining() == 40){
				hit = currBoard.throw_double(20);
			}
			else if (currPlayer->getRemaining() == 32) {
				hit = currBoard.throw_double(16);
			}
			else if (currPlayer->getRemaining() % 2 != 0) {
				hit = currBoard.throw_single(1);
			}
			else if (currPlayer->getRemaining() % 2 == 0){
				hit = currBoard.throw_double(currPlayer->getRemaining() / 2);
			}
		}
		currturn += hit; //saving current hit score into total score of turn
		//if total score of turn (until now) subtracted from remaining score of player results in 1 or under 0, turn is ended
		//and score is not subtracted
		if (currPlayer->getRemaining() - currturn == 1 || currPlayer->getRemaining() - currturn < 0) break;
		//if total score of turn (until now) subtracted from remaining score of player results in 0
		//turn is ended, player has won the match
		if (currPlayer->getRemaining() - currturn == 0) break;
	}
	//if player's remaining points minus total score of current turn is not 1 or below zero
	//it's subtracted from remaining
	if (currPlayer->getRemaining() - currturn != 1 && currPlayer->getRemaining() - currturn > -1) currPlayer->refreshRemaining(currturn);
}

//round in which both players throw 3 darts
void Game::round()
{
	//player one's turn if player two hasn't won
	if (playerTwo->getRemaining() != 0) {
		turn(playerOne);
	}
	//player two's turn if player one hasn't won
	if (playerOne->getRemaining() != 0) {
		turn(playerTwo);
	}
	//these playerOne and playerTwo are not the same as they are declared in main
	//these references refer to the order in which they are playing
	//but using * the computer is working with the original player instances declared in main
}

void Game::setPlayers(Player* one, Player* two) 
{
	//sets playerOne as the one referenced in Brain
	playerOne = one;
	//sets playerTwo as the one referenced in Brain
	playerTwo = two;
}

Board* Game::returnBoard()
{
	//returns a reference of currBoard (class Board instance declared in class Game) in order to use it's functions in main
	//used this way Board.h does not need to be included in Source.cpp
	Board* ref = &currBoard;
	return ref;
}