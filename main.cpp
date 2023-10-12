#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[10] = {1,10,5,7,8,2,4,3,6,9};
	int start = 0;
	int end = 10;
	sortByQuick(array, start, end);
	for(int i=0; i<end; i++){
	std::cout << array[i] << ", ";
	}
}

