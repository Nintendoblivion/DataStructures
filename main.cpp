#include <iostream>
#include "array.h"

using namespace std;

int main(){
	Array<int> thing(0, 10);
	Array<int> thing2(thing);
	Array<int> thing3 = thing;
	thing[0];
	thing.getLength();
	thing.getStartIndex();
	thing.lowerBound();
	thing.numElements();
	thing.setLength(5);
	thing.setStartIndex(5);
	thing.size();
	thing.upperBound();
	Exception test("thing");
	Exception test2(test);
	Exception test3 = test;
	test.getMessage();
	test.setMessage("woot");

	
	return 0;
}