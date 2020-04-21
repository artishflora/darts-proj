#pragma once
class Board
{
	private:
		int bd[2][21];

		/*int finishers[21] = {50, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
		int allNums[43] = {60, 57, 54, 51, 50, 48, 45, 42, 40, 39, 38, 36, 34, 33, 32, 30, 28, 27, 26, 25, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int twoDartFinishes[21][43];
		int threeDartFinishes[21][43][43];
		int maxThreeFinish;
		int maxTwoFinish;
		int maxOneFinish;*/

	public:
		Board();
		~Board();

	//functs
		int throw_bull(int p);
		int throw_double(int d);
		int throw_treble(int d, int p);
		int throw_single(int d);

		/*int fourThrow(int currScore);
		int threeThrow(int currScore);
		int twoThrow(int currScore);

	//getters
		int getMaxOne();
		int getMaxTwo();
		int getMaxThree();*/
};

