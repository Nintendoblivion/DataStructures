#include "exception.h"

Exception::Exception(char *msg)
{
	m_msg = new char[strlen(msg)];
	if (!msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}

}

const char Exception::setMessage(const char *msg)
{
	m_msg = new char[strlen(msg)];
	if (!msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
		abort();
	}

	for (int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}
}

Exception &Exception::operator=(const Exception &rhs)
{
	setMessage(rhs.m_msg);
	return *this;
}