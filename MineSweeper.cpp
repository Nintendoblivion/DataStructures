#include"MineSweeper.h"

MineSweeper::MineSweeper(difficulty in) : m_playing(true), m_dif(in)
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

void MineSweeper::turn()
{
	char in = 0;
	int messUps = 0;
	Point loc(10,10);
	system("cls");
	display_Difficulty();
	game->displayBoard();
	
	if (!(game->winCheck() || game->loseCheck()))
	{
		do
		{
			if (messUps)
			{
				cout << "Invalid choice" << endl << endl;
				system("pause");
			}
			system("cls");
			display_Difficulty();
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
			display_Difficulty();
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

	else if (game->winCheck())
	{
		cout << endl << endl << "You Win!" << endl << endl;
		system("pause");
		m_playing = false;
		system("cls");
	}
	else
	{
		cout << endl << endl << "You Lose!" << endl << endl;
		system("pause");
		m_playing = false;
		system("cls");
	}
}

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

bool MineSweeper::playing(){
	return m_playing;
}
bool MineSweeper::playing() const{
	return m_playing;
}

void MineSweeper::display_Difficulty()
{
	cout << endl;
	if (m_dif == b)
	{
		cout << "[10x10 with 10 mines]" << endl;
	}
	else if (m_dif == i)
	{
		cout << "[16x16 with 40 mines]" << endl;
	}
	else
	{
		cout << "[16x32 with 100 mines]" << endl;
	}
}