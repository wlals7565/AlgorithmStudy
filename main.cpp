#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[10] = { 10,4,3,7,5,1,2,6,8,9 };
	int start = 0;
	int end = 9;
	int nthNum = 7;
	std::cout << selectionByQuick(array, start, end, nthNum);
}