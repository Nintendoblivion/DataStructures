#include <iostream>

using namespace std;

class Exception{

	friend ostream &operator<<(ostream in, const Exception &thing) { return in << thing.m_msg; }

public:
	Exception();
	Exception(char *msg);
	~Exception();

	Exception &operator=(const Exception &rhs);

	const char getMessage() { return *m_msg; }
	void setMessage(const char *msg);

	

private:
	char *m_msg;
};

