/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Board.cpp
*
*
*			Overview: A 2D Array of cells
*
*			Input: The size and number of mines
*
*			Output: none
****************************************************************/


#include "Board.h"


/**************************************************************
*	  Purpose:  A constructor to make the board
*				It adds mines to the boards
*				Determines the number of mines near a space
*				Figures out the number of safe spaces
*
*		Entry:  Size of board
*				Number of mines
*
*			Exit:	none
****************************************************************/
Board::Board(Point loc, int mines) : m_board(loc.x(), loc.y()), m_numBombs(mines)
{
	add_Bombs();
	add_nearBombs();
	m_safeSpaces = ( ( loc.x() * loc.y() ) - m_numBombs );
}

/**************************************************************
*	  Purpose:  To flag a cell on the board
*
*		Entry:  location of the cell
*
*			Exit:	none
****************************************************************/
void Board::flagSpace(Point loc)
{
	if (!m_board[loc.x() - 1][loc.y() - 1].turned())
	{
		m_board[loc.x() - 1][loc.y() - 1].flag();
	}
}

/**************************************************************
*	  Purpose:  To turn a cells
*				Turns any cells nearby if blank
*				Won't turn already turned or flagged cells
*
*		Entry:  Location of the cell to turn
*
*			Exit:	none
****************************************************************/
void Board::turnSpace(Point loc)
{
	int newX = loc.x() - 1;
	int newY = loc.y() - 1;
	Point newLoc(newX, newY);
	if (!m_board[newX][newY].turned() && !m_board[newX][newY].flagged()){
		m_board[newX][newY].turn();
		if (!m_board[newX][newY].bomb() && !m_board[newX][newY].bombsNear())
		{
			reveal_around(newLoc);
		}
	}
}

/**************************************************************
*	  Purpose:  Dsipaly the status of the board
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Board::displayBoard()
{
	cout << "[" << m_board.getRow() << "x" << m_board.getColumn() << " with " << m_numBombs << " mines]" << endl;
	cout << endl;
	for (int i = 0; i < m_board.getRow(); i++)
	{
		cout << "		";
		for (int id = 0; id < m_board.getColumn(); id++)
		{
			cout << m_board[i][id];
		}
		cout << endl;
	}
	cout << endl;
}

/**************************************************************
*	  Purpose:  Checks to see if a bomb has been turned
*
*		Entry:  none
*
*			Exit:	returns if the player has lost
****************************************************************/
bool Board::loseCheck()
{
	for (int i = 0; i < m_board.getRow(); i++)
	{
		for (int id = 0; id < m_board.getColumn(); id++)
		{
			if (m_board[i][id].bomb() && m_board[i][id].turned())
			{
				return true;
			}
		}
	}
	return false;
}

/**************************************************************
*	  Purpose:  Checks to see if all the spaces have been revealed
*
*		Entry:  none
*
*			Exit:	returns if the game has been won
****************************************************************/
bool Board::winCheck()
{
	int spaces = 0;
	for (int i = 0; i < m_board.getRow(); i++)
	{
		for (int id = 0; id < m_board.getColumn(); id++)
		{
			if (m_board[i][id].turned() && !m_board[i][id].bomb())
			{
				spaces++;
			}
		}
	}
	return m_safeSpaces == spaces;
}

/**************************************************************
*	  Purpose:  Makes sure the game keeps in the bounds
*				of the array
*
*		Entry:  none
*
*			Exit:	returns if the position is valid
****************************************************************/
bool Board::inBounds(Point loc)
{
	if (0 <= loc.x()-1 && loc.x()-1 < m_board.getRow() && 0 <= loc.y()-1 && loc.y()-1 < m_board.getColumn())
	{
		return true;
	}
	return false;
}

/**************************************************************
*	  Purpose:  Adds the bombs to the board
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Board::add_Bombs()
{
	srand(time(NULL));
	int bombsLeft = m_numBombs;
	unsigned int rNum;
	do{
		for (int i = 0; i < m_board.getRow(); i++)
		{
			for (int id = 0; id < m_board.getColumn(); id++)
			{
				rNum = rand() % 10;
				if (!rNum && bombsLeft && !m_board[i][id].bomb())
				{
					m_board[i][id].placeBomb();
					bombsLeft--;
				}
			}
		}
	} while (bombsLeft);
}

/**************************************************************
*	  Purpose:  Adds up the number of nearbombs to a cell
*				stores info in the cell
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Board::add_nearBombs()
{
	for (int i = 0; i < m_board.getRow(); i++)
	{
		for (int id = 0; id < m_board.getColumn(); id++)
		{
			for (int idx = 0; idx < 3; idx++)
			{
				for (int indx = 0; indx < 3; indx++)
				{
					Point place(i+idx, id+indx);
					if (inBounds(place))
					{
						if (m_board[i+idx-1][id+indx-1].bomb())
						{
							m_board[i][id].addNearBomb();
						}
					}

				}
			}
		}
	}
}

/**************************************************************
*	  Purpose:  Turn all cells next to the current cell
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/

void Board::reveal_around(Point loc)
{
	for (int idx = 0; idx < 3; idx++)
	{
		for (int indx = 0; indx < 3; indx++)
		{
			Point place(loc.x() + idx, loc.y() + indx);
			if (inBounds(place))
			{
				turnSpace(place);
			}

		}
	}
}
