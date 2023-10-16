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

//삽입 정렬 함수 sortByInsertion을 정의하였습니다.
void sortByInsertion(int* array, int size)
{
	// for문을 이용해 index 1 부터 시작해서 index n까지 정렬합니다. index 1부터 시작하는 이유는 삽입정렬은 선택된 값 왼쪽 값들과 비교해서 위치를 정하는데
	// index 0값은 비교할 왼쪽 값이 없기 때문입니다.
	for (int i = 1; i < size; i++) {
		//임시적으로 현재 선택한 값을 temp에 저장합니다.
		int temp = array[i];
		//for문을 이용해 왼쪽 인덱스에 있는 값들을 차례대로 비교해가며 만약 temp값보다 크다면 index에 1을 더한 위치에 값을 옮깁니다.
		//만약 크지 않은 값을 만났다면 for문을 탈출하고 임시적으로 저장한 값을 크지 않은 값 index에 1을 더한 위치에 넣습니다.
		for (int j = i; j > 0; j--) {
			if (temp < array[j - 1]) {
				array[j] = array[j - 1];
			}
			else {
				array[j] = temp;
				break;
			}
		}
	}
}


//퀵 정렬 함수 sortByQuick을 정의하였습니다.
void sortByQuick(int* array, int start, int end)
{
	//경계 조건으로 인덱스 start가 인덱스 end보다 작아야 합니다.
	if (start < end) {
		//partioning함수를 통해 피봇 값을 기준으로 작은 값은 피봇 왼쪽 부분배열에 큰 값은 피봇 오른쪽 부분배열에 들어가게 만들고 피봇의 인덱스를 반환합니다.
		int pivotidx = partioning(array, start, end); //피봇의 인덱스를 저장하고 있습니다.
		//재귀적으로 피봇을 기준으로 왼쪽 부분 배열과 오른쪽 부분배열에 대해 sortByQuick함수를 통해 퀵정렬하고 있습니다.
		sortByQuick(array, start, pivotidx-1);
		sortByQuick(array, pivotidx + 1, end);
	}
}

// 피봇값을 설정하고 그 값을 기준으로 퀵 정렬을 수행하며 피봇이 있는 인덱스를 반환합니다..
int partioning(int* array, int start, int end) 
{
	//temp는 값을 바꿀때 임시적으로 값을 저장하는 변수입니다.
	int temp;
	//피봇 값은 정렬하고자 하는 부분 배열의 맨 앞의 값으로 설정했습니다.
	int pivot = array[start];
	//startidx는 부분 배열에서 정렬을 시작하는 앞 부분입니다.
	int startidx = start+1;
	//endidx는 부분 배열에서 정렬을 시작하는 뒷 부분입니다.
	int endidx = end;
	//while문을 통해 왼쪽에는 피봇보다 작은 값을 오른쪽에는 피봇 보다 큰 값이 위치하게 만듭니다.
	while(startidx<endidx){
		//맨 앞 피봇값을 제외한 부분배열에서부터 오른쪽으로 한 칸 씩 이동하면서 피봇보다 큰 값을 찾습니다.
		while (array[startidx] < pivot) {
			startidx++;
		}
		//맨 뒤에서부터 왼쪽으로 한 칸 씩 이동하면서 피봇보다 작은 값을 찾습니다.
		while (array[endidx] > pivot) {
			endidx--;
		}
		//왼쪽에서 피봇보다 큰 값과 오른쪽에서 피봇보다 작은 값을 찾은 이후
		//startidx와 endidx를 비교해 서로가 교차한 적이 없다면 두 값의 위치를 바꿉니다.
		if (startidx < endidx) {
			temp = array[startidx];
			array[startidx] = array[endidx];
			array[endidx] = temp;
		}
	}
	//피봇값을 제외한 모든 값들이 피봇값을 기준으로 작은 값은 왼쪽 큰 값은 오른쪽에 위치한다면
	//마지막으로 작은 값들 중 가장 왼쪽에 있는 값과 피봇 값의 위치를 바꿉니다.
	temp = array[start];
	array[start] = array[endidx];
	array[endidx] = temp;
	return endidx;
}

//병합 정렬 함수 sortByMerge을 정의하였습니다
void sortByMerge(int* array, int start, int end)
{	
	//경계 조건으로 start가 end보다 작아야 함수를 실행합니다.
	if(start<end){ 
		//배열을 분활하기 위해 중간값인 middle를 선언했습니다.
		int middle = (end + start) / 2;
		//배열을 miidle를 통해 2개의 부분배열로 나누고 각 부분배열에 대해 재귀적으로 병합 정렬 함수 sortByMerge를 호출하고 있습니다.
		sortByMerge(array, start, middle);
		sortByMerge(array, middle+1, end);
		//merge함수는 start부터 end까지의 값들을 순서대로 정렬하는 역할을 합니다.
		merge(array, start, end);
	}
	else {
		return;
	}
}

//merge는 start부터 end까지의 인덱스 값들을 순서대로 정렬합니다.
void merge(int* array, int start, int end)
{
	//start부터 end까지 있는 값의 수 만큼 동적으로 배열을 할당합니다.
	int* temparray = new int[end-start+1]; 
	//여기서 middle는 왼쪽 부분배열의 끝을 가리킵니다.
	int middle = (start + end) / 2;
	//idx는 temparray에 값을 저장할 때 인덱스 값으로 쓰입니다.
	int idx = 0;
	//startidx1과 startIdx2는 각각 왼쪽 부분배열의 맨 앞 인덱스 오른쪽 부분배열의 맨 뒤 인덱스를 가리킵니다.
	int startIdx1 = start;
	int startIdx2 = middle+1;
	//while문을 통해 startIdx1과 startIdx2가 각각이 해당하는 부분배열의 끝을 넘지 않았다면 아래 과정을 반복합니다.
	while (startIdx1 <= middle && startIdx2 <= end) {//
		//만약 startIdx1 인덱스에 있는 값이 startIdx2 인덱스에 있는 값보다 작다면 temparray에 startIdx2에 있는 값을 넣고 idx와 startIdx1의 값을 1올립니다.
		if (array[startIdx1] < array[startIdx2]) {
			temparray[idx++] = array[startIdx1++];
		}
		//만약 startIdx2 인덱스에 있는 값이 startIdx1 인덱스에 있는 값보다 작다면 temparray에 startIdx2에 있는 값을 넣고 idx와 startIdx1의 값을 1올립니다.
		else {
			temparray[idx++] = array[startIdx2++];
		}
	}
	//위의 while문이 완료될 경우 부분배열 중 한개는 아직 값을 다 temparray에 저장하지 않았기 때문에
	//if문을 통해 아직 모든 값을 저장하지 않은 부분배열의 값들을 저장해줍니다.
	if (startIdx1 <= middle) {
		while (startIdx1 <= middle) {
			temparray[idx++] = array[startIdx1++];
		}
	}
	else {
		while (startIdx2 <= end) {
			temparray[idx++] = array[startIdx2++];
		}
	}
	//위 작업이 끝나며 temparray에 정렬된 부분 배열을 가지게 될 텐데 이 정렬된 부분 배열을 전체 배열인 array에 적용합니다.
	for (int i = start, idx =0 ; i <= end; i++, idx++) {
		array[i] = temparray[idx];
	}
	//temparray의 할당을 해제합니다.
	delete[] temparray;
}

//배열을 힙으로 만드는 함수 heapify를 정의합니다.
//최소힙으로 구성합니다.
void heapify(int* array, int start, int end)
{
	bool haveLeftChild = false;
	bool haveRightChild = false;
	int temp;
	//해당 원소가 왼쪽 자식을 가지고 있다면 이를 알리기 위한 값입니다.
	if (start * 2 <= end) {
		haveLeftChild = true;
	}
	//해당 원소가 오른쪽 자식을 가지고 있다면 이를 알리기 위한 값입니다.
	if (start * 2 + 1 <= end) {
		haveRightChild = true;
	}
	//왼쪽 자식과 오른쪽 자식이 있을 경우
	if (haveLeftChild == true && haveRightChild == true) {
		//자식 중에 더 작은 값을 가진고 있을 경우 
		if (array[start] > array[start * 2] || array[start]>array[start*2+1]) {
			//자식 중에 왼쪽 자식이 최소값인 경우
			if (array[start * 2] < array[start * 2 + 1]) {
				temp = array[start];
				array[start] = array[start * 2];
				array[start * 2] = temp;
				heapify(array, start * 2, end);
			}
			//자식 중에 오른쪽 자식이 최소값인 경우
			else {
				temp = array[start];
				array[start] = array[start * 2 + 1];
				array[start * 2 + 1] = temp;
				heapify(array, start * 2 + 1, end);
			}
		}
		//자식 중에 최솟값을 가진애가 없을 경우 아무것도 안함.
		else {
			return;
		}
	}
	//왼쪽 자식만 있을 경우
	else if (haveLeftChild == true && haveRightChild == false) {
		//왼쪽 자식이 더 작은 값을 가지고 있을 경우
		if (array[start] > array[start * 2]) {
			temp = array[start];
			array[start] = array[start * 2];
			array[start * 2] = temp;
			heapify(array, start * 2, end);
		}
		else {
			return;
		}
	}
	else {
		return;
	}
}
