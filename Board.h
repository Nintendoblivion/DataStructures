/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Board.h
*
*
*			Overview: A 2D Array of cells
*
*			Input: The size and number of mines
*
*			Output: none
****************************************************************/


#include <stdio.h>  
#include <stdlib.h>   
#include <time.h>     


#include "Cell.h"
#include "Array2D.h"
#include "Point.h"

class Board{

public:

	Board(Point loc, int mines); // constructor

	void flagSpace(Point loc); // flag the cell at loc
	void turnSpace(Point loc); // turn the space at loc

	void displayBoard(); // display the board

	bool loseCheck(); //check if game has been lost
	bool winCheck(); // check if game has been won

	bool inBounds(Point loc); // check if in bounds

private:
	Array2D<Cell> m_board; // actually array for the board
	int m_numBombs, m_safeSpaces; // number of bombs and safe spots

	void add_nearBombs(); //add the nearby bombs to cells
	void add_Bombs(); // places the bombs
	void reveal_around(Point Loc); // turns all spaces around loc
	
};