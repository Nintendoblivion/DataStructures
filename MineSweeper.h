#include "Board.h"

enum difficulty{ b, i, e };

class MineSweeper
{
public:
	
	MineSweeper(difficulty in);
	
	void turn();

	void flipMark(char in, Point loc);

	bool playing();
	bool playing() const;
	void display_Difficulty();

private:
	Board *game;
	bool m_playing;
	difficulty m_dif;
};