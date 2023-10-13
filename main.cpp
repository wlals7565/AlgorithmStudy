#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[12] = {11,12,1,10,5,7,8,2,4,3,6,9};
	int start = 0;
	int end = 11;
	int size = 12;
	sortByQuick(array, start, end);
	for(int i=0; i<size; i++){
	std::cout << array[i] << ", ";
	}
}

