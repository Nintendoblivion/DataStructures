/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.h
*
*
*			Overview: A game of minesweeper
*
*			Input: The difficulty of the game
*
*			Output: none
****************************************************************/


#include "Board.h"

enum difficulty{ b, i, e };

class MineSweeper
{
public:
	
	MineSweeper(difficulty in); // constructor
	
	bool turn(); // turn function to see if game is running

	void flipMark(char in, Point loc); // flag or turn a space as necessary

private:
	Board *game; // game board

	difficulty m_dif; // game difficulty

	void play(); // actually playing of the game
};