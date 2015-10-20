/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Cell.cpp
*
*
*			Overview: A cell object that contains a bomb
*						can be flagged, and flipped
*
*			Input: If it has a bomb
*
*			Output: none
****************************************************************/


#include "Cell.h"

Cell::Cell(bool bomb) 
	: m_bomb(bomb), m_turned(false), 
	m_flagged(false), m_bombsNear(0)
{

}

/**************************************************************
*	  Purpose:  mutator for m_bomb
*
*		Entry:  none
*
*			Exit:	return if it has a bomb
****************************************************************/
bool Cell::bomb()
{
	return m_bomb;
}
/**************************************************************
*	  Purpose:  accessor for m_bomb
*
*		Entry:  none
*
*			Exit:	return if it has a bomb
****************************************************************/
bool Cell::bomb() const
{
	return m_bomb;
}
/**************************************************************
*	  Purpose:  makes the cell a bomb cell
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Cell::placeBomb()
{
	m_bomb = true;
}

/**************************************************************
*	  Purpose:  mutator for m_turned
*
*		Entry:  none
*
*			Exit:	return if it has been turned
****************************************************************/
bool Cell::turned()
{
	return m_turned;
}

/**************************************************************
*	  Purpose:  accesor for m_bomb
*
*		Entry:  none
*
*			Exit:	return if it has been turned
****************************************************************/
bool Cell::turned() const
{
	return m_turned;
}

/**************************************************************
*	  Purpose:  turns a cell over
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Cell::turn()
{
	m_turned = !m_turned;
}

/**************************************************************
*	  Purpose:  mutator for m_flagged
*
*		Entry:  none
*
*			Exit:	return if it has been flagged
****************************************************************/
bool Cell::flagged()
{
	return m_flagged;
}

/**************************************************************
*	  Purpose:  accessor  for m_flagged
*
*		Entry:  none
*
*			Exit:	return if it has been flagged
****************************************************************/
bool Cell::flagged() const
{
	return m_flagged;
}

/**************************************************************
*	  Purpose:  Flags or unflags the cell
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Cell::flag()
{
	m_flagged = !m_flagged;
}

/**************************************************************
*	  Purpose:  mutator for m_bombsNear
*
*		Entry:  none
*
*			Exit:	return number of bombs near
****************************************************************/
int Cell::bombsNear()
{
	return m_bombsNear;
}

/**************************************************************
*	  Purpose: accessor for m_bombsNear
*
*		Entry:  none
*
*			Exit:	return number of bombs near
****************************************************************/
int Cell::bombsNear() const
{
	return m_bombsNear;
}

/**************************************************************
*	  Purpose:  Add one to m_bombsNear
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void Cell::addNearBomb()
{
	m_bombsNear++;
}

/**************************************************************
*	  Purpose:  Override the insertion operator
*
*		Entry:  An ostream
*				The cell being displayed
*
*			Exit: If flagged returns		!
*				  If unturned returns		?
*				  If turned bomb returns	X
*				  If turns and not bomb returns number of bombs
****************************************************************/
ostream &operator<<(ostream &os, const Cell &Cell)
{
	if (Cell.flagged() && !Cell.turned())
	{
		os << "!";
	}
	else if (!Cell.flagged() && !Cell.turned())
	{
		os << "?";
	}
	else if (!Cell.bomb())
	{
		os << Cell.bombsNear();
	}
	else
	{
		os << "X";
	}


	return os;
}