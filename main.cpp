#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[10] = { 1,10,5,7,8,2,4,3,6,9 };
	int size = 10;
	sortByBubble(array, size);
	for(int i=0; i<size; i++){
	std::cout << array[i] << ", ";
	}
}

