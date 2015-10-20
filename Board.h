#include <stdio.h>  
#include <stdlib.h>   
#include <time.h>     


#include "Cell.h"
#include "Array2D.h"
#include "Point.h"

class Board{

public:

	Board(Point loc, int mines);

	void flagSpace(Point loc);
	void turnSpace(Point loc);

	void displayBoard();

	bool loseCheck();
	bool winCheck();

	bool inBounds(Point loc);

private:
	Array2D<Cell> m_board;
	int m_numBombs, m_safeSpaces;

	void add_nearBombs();
	void add_Bombs();
	void reveal_around(Point Loc);
	
};