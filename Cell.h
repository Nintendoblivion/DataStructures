
#include <iostream>
using namespace std;

class Cell{

public:
		Cell(bool bomb = false);

		bool bomb();
		bool bomb() const;
		void placeBomb();

		bool turned();
		bool turned() const;
		void turn();

		bool flagged();
		bool flagged() const;
		void flag();

		int bombsNear();
		int bombsNear() const;
		void addNearBomb();

		friend ostream &operator<<(ostream &os, const Cell &Cell);


private:
	bool m_bomb;
	bool m_turned;
	bool m_flagged;

	int m_bombsNear;


};