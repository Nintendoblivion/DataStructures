#include "exception.h"

Exception::Exception(const char *msg)
{
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

Exception::~Exception()
{
	delete []m_msg;
}

char Exception:: getMessage() const 
{ 
	return *m_msg; 
}

void Exception::setMessage(const char *msg)
{
	delete[]m_msg;
	m_msg = new char[strlen(msg)];
	if (!m_msg){
		cout << "Failed Memory Allocation" << endl;
		system("pause");
	}

	for (unsigned int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}
}

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

ostream &operator<<(ostream out, const Exception &thing)
{
	return out << thing.getMessage();

}