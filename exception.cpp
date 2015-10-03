#include "exception.h"

Exception::Exception(char *msg)
{
	m_msg = new char[strlen(msg)];
	if (!msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (unsigned int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}

}

Exception::~Exception()
{
	delete []m_msg;
}

void Exception::setMessage(const char *msg)
{
	m_msg = new char[strlen(msg)];
	if (!msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (unsigned int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}
}

Exception &Exception::operator=(const Exception &rhs)
{
	setMessage(rhs.m_msg);
	return *this;
}