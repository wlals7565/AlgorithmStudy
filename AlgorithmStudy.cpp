#pragma once
#include <iostream>
#include "AlgorithmStudy.h"

//선택 정렬 함수 sortBySelection을 정의하였습니다.
void sortBySelection(int* array, int size)
{
	//값을 바꿀때 임시적으로 값을 저장하기 위한 변수 temp를 선언합니다.
	int temp;
	//아래에서 부터 선택 정렬의 중요한 알고리즘입니다.
	//size-1개의 데이터들을 for문을 이용해 정렬합니다. 
	//size-1개만 정렬하는 이유는 size-1개만 정렬하면 나머지 1개는 이미 정렬된 상태가 되기 때문입니다.
	for (int i = 0; i < size - 1; i++) {
		//임시적으로 정렬되지 않은 부분배열의 맨 앞의 인덱스를 min에 저장합니다.
		int min = i;
		//for문을 통해 인덱스 min뒤의 배열 값들을 하나하나 비교하면서 가장 작은 값을 찾습니다.
		for (int j = i + 1; j < size; j++) {
			//만약 지금 가지고 있는 값보다 작은 값을 찾으면 min에 그 값이 있는 인덱스를 저장합니다.
			if (array[min] > array[j]) {
				min = j;
			}
		}
		//배열에서 값을 바꾸는 작업입니다.
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}


//버블 정렬 함수 sortByBubble을 정의하였습니다.
void sortByBubble(int* array, int size)
{
	//값을 바꿀때 임시적으로 값을 저장하기 위한 변수 temp를 선언합니다.
	int temp;
	//size-1개의 데이터들을 for문을 이용해 정렬합니다. 
	//size-1개만 정렬하는 이유는 size-1개만 정렬하면 나머지 1개는 이미 정렬된 상태가 되기 때문입니다.
	for (int i = 0; i < size-1; i++) {
		//for문을 이용해 인접한 두 개의 인덱스 값을 비교해서 왼쪽 인덱스의 값이 오른쪽 인덱스 값보다 크다면 바꿔줍니다.
		//이를 정렬되지 않은 부분 배열내의 끝까지 반복합니다.
		for (int j = 0; j < size -1- i; j++) {
			//배열에서 값을 바꾸는 작업입니다.
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

		}
	}
}
