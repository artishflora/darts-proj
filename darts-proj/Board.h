#pragma once
class Board
{
	private:
		int numberNeighbours[3][21] = {
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
			{0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5},
			{0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1}
		};

		int finishers[21] = {50, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
		int allNums[43] = {60, 57, 54, 51, 50, 48, 45, 42, 40, 39, 38, 36, 34, 33, 32, 30, 28, 27, 26, 25, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int twoDartFinishes[21][43];
		int threeDartFinishes[21][43][43];
		int maxThreeFinish;
		int maxTwoFinish;
		int maxOneFinish;

	public:
		Board();
		~Board();

	//functs
		int bullMiss();
		int numberTarget(int target, int numChance);
		int fourThrow(int currScore);
		int threeThrow(int currScore);
		int twoThrow(int currScore);

	//getters
		int getMaxOne();
		int getMaxTwo();
		int getMaxThree();
};

