/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.h
*
*
*			Overview: A cell object that contains a bomb
*						can be flagged, and flipped
*
*			Input: If it has a bomb
*
*			Output: none
****************************************************************/


#include <iostream>
using namespace std;

class Cell{

public:
		Cell(bool bomb = false); // constructor

		bool bomb(); // returns if a bomb
		bool bomb() const; // returns if a bomb
		void placeBomb(); // makes a bomb

		bool turned(); // returns if turned
		bool turned() const; // returns if turned
		void turn(); // turn the space

		bool flagged(); // returns if flagged
		bool flagged() const; // returns if flagged
		void flag(); // flag or unflag

		int bombsNear(); // returns number of bombs near
		int bombsNear() const; // returns number of bombs near
		void addNearBomb(); // adds a nearby bomb

		friend ostream &operator<<(ostream &os, const Cell &Cell); // cell output


private:
	bool m_bomb; // if a bomb
	bool m_turned; // if turned
	bool m_flagged; // if flagged

	int m_bombsNear; // number of nearby bombs


};