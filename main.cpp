#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int start = 0;
	int end = 9;
	int searchNum = 1;
	std::cout << binarySearch(array, start, end, searchNum);
}