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
	while(startidx<=endidx){
		//맨 앞 피봇값을 제외한 부분배열에서부터 오른쪽으로 한 칸 씩 이동하면서 피봇보다 큰 값을 찾습니다.
		while (array[startidx] < pivot ) {
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
	//여기가 잘못되었다.
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

//이진 탐색 함수 binarySearch를 정의합니다.
int binarySearch(int* array, int start, int end, int searchNum)
{
	//만약 start값이 end보다 크다면 실행하지 않습니다.
	if(start<=end){
		//배열의 중간을 가리키는 middle 변수를 선언합니다.
		int middle = (start + end) / 2;
		//인덱스 middle인 값이 searchNum과 값이 같다면 middle를 반환합니다.
		if (array[middle] == searchNum) {
			return middle;
		}
		//인덱스 middle인 값이 searchNum보다 작다면 middle+1부터 end까지의 범위에 다시 재귀적으로 이진탐색을 합니다.
		else if (array[middle] < searchNum) {
			return binarySearch(array, middle + 1, end, searchNum);
		}
		//인덱스 middle인 값이 searchNum보다 크다면 middle-1부터 start까지의 범위에 다시 재귀적으로 이진탐색을 합니다.
		else if (array[middle] > searchNum) {
			return binarySearch(array, start, middle - 1,searchNum);
		}
	}
	//만약 값을 찾지 못하면 -999를 반환합니다.
	else {
		return -999;
	}
}
//nthNum번째로 작은 값을 구하는 함수 selectionByQuick을 정의합니다.
int selectionByQuick(int* array, int start, int end, int nthNum)
{
	if (start <= end) {
		//partioning을 통해 피봇의 인덱스를 얻습니다.
		int pivotIdx = partioning(array, start, end);
		//피봇의 인덱스와 nthNum-1이 같다면 피봇이 nthNum번째 수이기 때문에 array[pivot]을 반환합니다.
		if (pivotIdx == nthNum - 1) {
			// nthNum번째 값을 반환합니다.
			return array[pivotIdx];
		}
		//피봇의 인덱스가 nthNum-1보다 크다면 피봇 기준 오른쪽에 찾고자 하는 nthNum번째 값이 있기 때문에 해당 부분 배열만 재귀적으로 selectionByQuick함수를 사용합니다.
		else if (pivotIdx > nthNum - 1) {
			return selectionByQuick(array, start, pivotIdx - 1, nthNum);
		}
		//피봇의 인덱스가 nthNum-1보다 작다면 피봇 기준 왼쪽에 찾고자 하는 nthNum번째 값이 있기 때문에 해당 부분 배열만 재귀적으로 selectionByQuick함수를 사용합니다.
		else {
			return selectionByQuick(array, pivotIdx + 1, end, nthNum);
		}
	}
	//nthNum번째 값을 찾지 못하면 -1을 반환합니다.
	else {
		return -1;
	}
}
binaryTree:: binaryTree() {
		this->value = NULL;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
	//이진트리에 값을 삽입하는 함수 insertNum입니다.
	void binaryTree::insertNum(int num)
	{
		//해당 노드에 값이 존재하지 않으면 값을 삽입합니다.
		//값을 삽입하기 이전에 아래 코드에서 노드를 새로 만들어 놓습니다.
		if (this->value == NULL) {
			this->value = num;
			return;
		}
		//만약 삽입하고자 하는 값 num보다 현재 노드의 값이 크다면 왼쪽서브트리에 있어야 합니다. 
		else if (this->value > num) {
			//이때 왼쪽 자식이 nullptr이라면 노드를 생성하고 재귀적으로 insertNum을 호출해 값을 삽입해줍니다.
			if (this->leftChild == nullptr) {
				binaryTree* temp = new binaryTree();
				this->leftChild = temp;
				this->leftChild->insertNum(num);
				return;
			}
			//왼쪽 자식이 있다면 왼쪽 자식에 대해 재귀적으로 insertNum을 호출해 찾고자 하는 값을 찾습니다.
			else {
				this->leftChild->insertNum(num);
				return;
			}
		}
		//만약 삽입하고자 하는 값 num보다 현재 노드의 값이 작다면 오른쪽서브트리에 있어야 합니다. 
		else if (this->value < num) {
			//이때 오른쪽 자식이 nullptr이라면 노드를 생성하고 재귀적으로 insertNum을 호출해 값을 삽입해줍니다
			if (this->rightChild == nullptr) {
				binaryTree* temp = new binaryTree();
				this->rightChild = temp;
				this->rightChild->insertNum(num);
				return;
			}
			//오른쪽 자식이 있다면 오른쪽 자식에 대해 재귀적으로 insertNum을 호출해 찾고자 하는 값을 찾습니다.
			else {
				this->rightChild->insertNum(num);
				return;
			}
		}
		//아무 의미도 없는 구문입니다.
		else {
			return;
		}
	}

	void binaryTree::deleteNum(int num)
	{
		binaryTree* parentNode = nullptr;
		binaryTree* childNode = this;
		// isRight는 parentNode기준 child노드가 오른쪽 자식인지 아닌지를 알려주는 값임.
		bool isRight;
		//가장 최상위 노드를 삭제해야 한다면 parentNode 는 nullptr이 된다 이걸 이용하자
		//가장 최상위 노드가 아니라는 가정으로 먼저 코드를 만들다
		//현재 노드에 값이 삭제하고자 하는 값과 같지 않다면 값을 찾거나 값이 없다는 것을 확인할 때까지 반복한다.
		while (childNode->value != num) { 
			//현재 값이 찾고자 하는 값보다 크다면 왼쪽 서브 트리에서 값을 찾아야 한다.
			if (childNode->value > num && childNode->leftChild !=nullptr) {
				isRight = false;
				parentNode = childNode;
				childNode = childNode->leftChild;
			}
			//현재 값이 찾고자 하는 값보다 작다면 오른쪽 서브 트리에서 값을 찾아야 한다.
			else if(childNode->value < num && childNode->rightChild !=nullptr){
				isRight = true;
				parentNode = childNode;
				childNode = childNode->rightChild;
			}
			else {
				//값이 없어서 못 찾음.
				return;
			}
		}
		//삭제하고자 하는 값을 찾음
		//삭제 작업 시작
		//삭제하고 하는 값이 리프노드여서 자식이 없다면
		if(parentNode != nullptr){
			if (childNode->leftChild == nullptr && childNode->rightChild == nullptr) {
				if (isRight) {
					parentNode->rightChild = nullptr;
					delete childNode;
					return;
				}
				else {
					parentNode->leftChild = nullptr;
					delete childNode;
					return;
				}
			}
			//삭제하고자 하는 값이 왼쪽 자식만 가지고 있다면
			else if(childNode->leftChild != nullptr && childNode->rightChild == nullptr) {
				if (isRight) {
					parentNode->rightChild = childNode->leftChild;
					delete childNode;
					return;
				}
				else {
					parentNode->leftChild = childNode->leftChild;
					delete childNode;
					return;
				}
			}
			//삭제하고자 하는 값이 오른쪽 자식만 가지고 있다면
			else if (childNode->leftChild == nullptr && childNode->rightChild != nullptr) {
				if (isRight) {
					parentNode->rightChild = childNode->rightChild;
					delete childNode;
					return;
				}
				else {
					parentNode->leftChild = childNode->rightChild;
					delete childNode;
					return;
				}
			}
			//삭제하고자 하는 값이 왼쪽 오른쪽 자식 다 가지고 있다면
			else {
				binaryTree* changeNode = childNode->leftChild;
				binaryTree* parentChangeNode = nullptr;
				while (changeNode->rightChild != nullptr) {
					parentChangeNode = changeNode;
					changeNode = changeNode->rightChild;
				}
				//왼쪽 서브트리의 가장 큰 값이 childNode왼쪽 자식일 경우
				if (childNode->leftChild == changeNode) {
					if (isRight) {
						parentNode->rightChild = changeNode;
						changeNode->rightChild = childNode->rightChild;
						delete childNode;
						return;
					}
					else {
						parentNode->leftChild = changeNode;
						changeNode->rightChild = childNode->rightChild;
						delete childNode;
						return;
					}
				}
				//왼쪽 서브트리의 가장 큰 값이 childNode의 왼쪽 자식이 아닐경우
				else {
					//바꾸고자 하는 changeNode의 왼쪽 자식이 없는 경우
					if (changeNode->leftChild == nullptr) {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = nullptr;
						delete changeNode;
						return;
					}
					//바꾸고자 하는 changeNode의 왼쪽 자식이 있는 경우
					else {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = changeNode->leftChild;
						delete changeNode;
						return;
					}
				}
			}
		}
		//제거하고자 하는 값이 최상위 루트 노드에 있었다면
		else {
			if (childNode->leftChild == nullptr && childNode->rightChild == nullptr) {
				childNode->value = NULL;
				childNode->leftChild = nullptr;
				childNode->rightChild = nullptr;
				return;
			}
			//왼쪽 자식만 있다면
			else if (childNode->leftChild != nullptr && childNode->rightChild == nullptr)
			{
				binaryTree* temp = childNode->leftChild;
				childNode->value = childNode->leftChild->value;
				childNode->leftChild = childNode->leftChild->leftChild;
				childNode->rightChild = childNode->leftChild->rightChild;
				delete temp;
				return;
			}
			//오른쪽 자식만 있다면
			else if (childNode->leftChild == nullptr && childNode->rightChild != nullptr) {
				binaryTree* temp = childNode->rightChild;
				childNode->value = childNode->rightChild->value;
				childNode->leftChild = childNode->rightChild->leftChild;
				childNode->rightChild = childNode->rightChild->rightChild;
				delete temp;
				return;
			}
			//여기 다시 볼 필요가 있다.
			//자식 둘다 있다면
			else {
				binaryTree* changeNode = childNode->leftChild;
				binaryTree* parentChangeNode = nullptr;
				while (changeNode->rightChild != nullptr) {
					parentChangeNode = changeNode;
					changeNode = changeNode->rightChild;
				}
				//왼쪽 서브트리의 가장 큰 값이 childNode왼쪽 자식일 경우
				if (childNode->leftChild == changeNode) {
					binaryTree* temp = childNode->leftChild;
					childNode->value = childNode->leftChild->value;
					childNode->leftChild = childNode->leftChild->leftChild;
					delete temp;
				}
				//왼쪽 서브트리의 가장 큰 값이 childNode의 왼쪽 자식이 아닐경우
				else {
					//바꾸고자 하는 changeNode의 왼쪽 자식이 없는 경우
					if (changeNode->leftChild == nullptr) {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = nullptr;
						delete changeNode;
						return;
					}
					//바꾸고자 하는 changeNode의 왼쪽 자식이 있는 경우
					else {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = changeNode->leftChild;
						delete changeNode;
						return;
					}
				}
			}
		}
		return;
	}

	bool binaryTree::searchNum(int num)
	{
		if (this->value == num) {
			return true;
		}
		else if (this->value > num) {
			if (this->leftChild == nullptr) {
				return false;
			}
			else {
				return this->leftChild->searchNum(num);
			}

		}
		else if (this->value < num) {
			if (this->rightChild == nullptr) {
				return false;
			}
			else {
				return this->rightChild->searchNum(num);
			}
		}
		else {
			return false;
		}
	}

	void binaryTree::printTree() {
		//레벨 순회 구현해야함
		// 큐 만들어야 하고
		//이거어렵네
		if(this->value != NULL){
			std::cout << this->value;
		}
		if (this->leftChild != nullptr) {
			this->leftChild->printTree();
		}
		if (this->rightChild != nullptr) {
			this->rightChild->printTree();
		}
	}