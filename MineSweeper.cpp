/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.cpp
*
*
*			Overview: A game of minesweeper
*
*			Input: The difficulty of the game
*
*			Output: none
****************************************************************/


#include"MineSweeper.h"

/**************************************************************
*	  Purpose:  Constructor for the Minesweeper Game
*				Creates the board for the game
*
*		Entry:  The difficulty of the board
*
*			Exit:	none
****************************************************************/
MineSweeper::MineSweeper(difficulty in) : m_dif(in)
{
	if (in == b)
	{
		Point place(10, 10);
		game = new Board(place, 10);
	}
	else if (in == i)
	{
		Point place(16, 16);
		game = new Board(place, 40);
	}
	else
	{
		Point place(16, 32);
		game = new Board(place, 100);
	}
}


/**************************************************************
*	  Purpose:  To run the turn and check if the game has been won or not
*
*		Entry:  none
*
*			Exit:	Returns a bool containing if the game 
*					is still going
****************************************************************/
bool MineSweeper::turn()
{
	system("cls");
	game->displayBoard();
	
	if (!(game->winCheck() || game->loseCheck()))
	{
		play();
		return true;
	}

	else if (game->winCheck())
	{
		cout << endl << endl << "You Win!" << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
	else
	{
		cout << endl << endl << "You Lose!" << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
}

/**************************************************************
*	  Purpose:  turns or flags a  cell
*
*		Entry:  a char marking if it should be flagged or turns
*				the location of the of cell
*
*			Exit:	none
****************************************************************/
void MineSweeper::flipMark(char in, Point loc)
{
	if (in == 'f')
	{
		game->flagSpace(loc);
	}
	else
	{
		game->turnSpace(loc);
	}
}

/**************************************************************
*	  Purpose:  To play the game
*
*		Entry:  none
*
*			Exit:	none
****************************************************************/
void MineSweeper::play()
{
	char in = 0;
	Point loc(10, 10);
	int messUps = 0;
	do
	{
		if (messUps)
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
		}
		system("cls");
		game->displayBoard();
		cout << "Flag or turn(f/t):" << endl;
		cin >> in;
		messUps++;
	} while (!(in == 'f' || in == 't'));

	messUps = 0;
	do
	{
		if (messUps)
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
		}
		system("cls");
		game->displayBoard();

		if (in == 'f')
		{
			cout << "Flag";
		}
		else
		{
			cout << "Turn";
		}
		cout << " spot (x,y):" << endl;
		cin >> loc;
		if (cin.fail())
		{
			throw(new Exception("Type input error"));
		}
		messUps++;
	} while (!game->inBounds(loc));

	flipMark(in, loc);
}