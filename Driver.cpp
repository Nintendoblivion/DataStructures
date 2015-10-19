#include"LinkedList.h"

typedef int TYPE;

void display(LinkedList<TYPE> &list ){
	for (Iterator<TYPE> i = list.begin(); i != list.end(); ++i)
	{
		cout << i << endl;
	}
}

int main()
{
	LinkedList<TYPE> test;
	int one = 1;
	int two = 2;
	int three = 3;

	test.Prepend(&one);
	test.Append(&two);

	system("pause");
	return 0;
}