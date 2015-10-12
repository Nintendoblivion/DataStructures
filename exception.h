#include <iostream>

using namespace std;

class Exception{

	

public:
	Exception();
	Exception(const char *msg);
	~Exception();

	Exception &operator=(const Exception &rhs);

	char getMessage() const;
	void setMessage(const char *msg);

	friend ostream &operator<<(ostream out, const Exception &thing);

	

private:
	char *m_msg;
};

