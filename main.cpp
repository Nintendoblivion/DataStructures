#include "Array2D.h"
#include <iostream>

using namespace std;

int main()
{
	try{
		Array2D<int> thing;
		Array2D<int> test(2, 5);
		for (int idx = 0; idx < 2; idx++)
		{
			for (int id = 0; id < 5; id++)
			{
				test[idx][id] = ( (idx + 1) * (id + 1) ) - 1;
				cout << test[idx][id] << " ";
			}
			cout << endl;
		}

		const Array2D<int> test2(test);
		cout << test2[0][0];

		Array2D<int> test3 = test;

		test.setColumn(4);
		test.setRow(3);
		test.getColumn();
		test.getRow();
	}
	catch(Exception e){
		cout << e.getMessage();
	}
	system("pause");
	return 0;
}