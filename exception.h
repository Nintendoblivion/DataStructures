#include <iostream>

using namespace std;
/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 2
* Filename:				exception.h
*		 
*
*			Overview: To output messages for exceptions
*			
*			Input: A string
*
*			Output: None
****************************************************************/

class Exception{

	

public:
	Exception();
	Exception(const char *msg);
	~Exception();

	Exception &operator=(const Exception &rhs);

	char getMessage() const;
	void setMessage(const char *msg);

	friend ostream &operator<<(ostream &out, const Exception &thing);

	

private:
	char *m_msg;
};

