#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	int array[11] = { 0,10,9,8,7,6,5,4,3,2,1 };
	int start = 1;
	int end = 10;
	int size = 11;
	//재귀적으로 배열 맨 끝의 원소부터 heapify함수를 이용하여 힙 구조를 가지게 합니다.
	for(int i = end; i>=start; i--){
		heapify(array, i, end);
	}
	for(int i=1; i<size; i++){
	std::cout << array[i] << ", ";
	}
	int clone[10] = { 0, };
	for (int i = 0; i < 10; i++) {
		clone[i] = array[1];
		array[1] = array[end--];
		heapify(array, start, end);
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << clone[i] << ", ";
	}

	
}