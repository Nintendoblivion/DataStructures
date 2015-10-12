/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 2
* Filename:				exception.cpp
*
*
*			Overview: To output messages for exceptions
*
*			Input: A string
*
*			Output: None
****************************************************************/


#include "exception.h"




/**************************************************************
*	  Purpose:  Construcotr for the Exception class
*
*		 Entry: Message to set for the class
*
*			Exit: none
****************************************************************/
Exception::Exception(const char *msg)
{
	m_msg = new char[strlen(msg)];
	if (!m_msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (unsigned int i = 0; i < strlen(msg); i++)
	{
		m_msg[i] = msg[i];
	}

}

/**************************************************************
*	  Purpose:  Delete any allocated memory
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
Exception::~Exception()
{
	delete []m_msg;
}

/**************************************************************
*	  Purpose:  To get the message
*
*		 Entry: none
*
*			Exit: The message
****************************************************************/
char Exception:: getMessage() const 
{ 
	return *m_msg; 
}

/**************************************************************
*	  Purpose:  Set the message of the exception class
*
*		 Entry: The message to set it to
*
*			Exit: none
****************************************************************/
void Exception::setMessage(const char *msg)
{
	delete[]m_msg;
	m_msg = new char[strlen(msg)];
	if (!m_msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (unsigned int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}
}

/**************************************************************
*	  Purpose:  Overriding the assignment 
*
*		 Entry: Another Exception object
*
*			Exit: An exception object the same as the other
****************************************************************/
Exception &Exception::operator=(const Exception &rhs)
{

	delete[] m_msg;
	m_msg = new char[strlen(rhs.m_msg)];
	if (!m_msg)
	{
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	setMessage(rhs.m_msg);
	return *this;
}

/**************************************************************
*	  Purpose:  To output the message
*
*		 Entry: An ostream object
*				The Exception
*
*			Exit: An ostream containing the message
****************************************************************/
ostream &operator<<(ostream &out, const Exception &thing)
{
	return out << thing.getMessage();

}