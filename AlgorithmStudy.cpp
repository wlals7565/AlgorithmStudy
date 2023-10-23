#pragma once
#include <iostream>
#include "AlgorithmStudy.h"

//���� ���� �Լ� sortBySelection�� �����Ͽ����ϴ�.
void sortBySelection(int* array, int size)
{
	//���� �ٲܶ� �ӽ������� ���� �����ϱ� ���� ���� temp�� �����մϴ�.
	int temp;
	//�Ʒ����� ���� ���� ������ �߿��� �˰����Դϴ�.
	//size-1���� �����͵��� for���� �̿��� �����մϴ�. 
	//size-1���� �����ϴ� ������ size-1���� �����ϸ� ������ 1���� �̹� ���ĵ� ���°� �Ǳ� �����Դϴ�.
	for (int i = 0; i < size - 1; i++) {
		//�ӽ������� ���ĵ��� ���� �κй迭�� �� ���� �ε����� min�� �����մϴ�.
		int min = i;
		//for���� ���� �ε��� min���� �迭 ������ �ϳ��ϳ� ���ϸ鼭 ���� ���� ���� ã���ϴ�.
		for (int j = i + 1; j < size; j++) {
			//���� ���� ������ �ִ� ������ ���� ���� ã���� min�� �� ���� �ִ� �ε����� �����մϴ�.
			if (array[min] > array[j]) {
				min = j;
			}
		}
		//�迭���� ���� �ٲٴ� �۾��Դϴ�.
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}


//���� ���� �Լ� sortByBubble�� �����Ͽ����ϴ�.
void sortByBubble(int* array, int size)
{
	//���� �ٲܶ� �ӽ������� ���� �����ϱ� ���� ���� temp�� �����մϴ�.
	int temp;
	//size-1���� �����͵��� for���� �̿��� �����մϴ�. 
	//size-1���� �����ϴ� ������ size-1���� �����ϸ� ������ 1���� �̹� ���ĵ� ���°� �Ǳ� �����Դϴ�.
	for (int i = 0; i < size-1; i++) {
		//for���� �̿��� ������ �� ���� �ε��� ���� ���ؼ� ���� �ε����� ���� ������ �ε��� ������ ũ�ٸ� �ٲ��ݴϴ�.
		//�̸� ���ĵ��� ���� �κ� �迭���� ������ �ݺ��մϴ�.
		for (int j = 0; j < size -1- i; j++) {
			//�迭���� ���� �ٲٴ� �۾��Դϴ�.
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

		}
	}
}

//���� ���� �Լ� sortByInsertion�� �����Ͽ����ϴ�.
void sortByInsertion(int* array, int size)
{
	// for���� �̿��� index 1 ���� �����ؼ� index n���� �����մϴ�. index 1���� �����ϴ� ������ ���������� ���õ� �� ���� ����� ���ؼ� ��ġ�� ���ϴµ�
	// index 0���� ���� ���� ���� ���� �����Դϴ�.
	for (int i = 1; i < size; i++) {
		//�ӽ������� ���� ������ ���� temp�� �����մϴ�.
		int temp = array[i];
		//for���� �̿��� ���� �ε����� �ִ� ������ ���ʴ�� ���ذ��� ���� temp������ ũ�ٸ� index�� 1�� ���� ��ġ�� ���� �ű�ϴ�.
		//���� ũ�� ���� ���� �����ٸ� for���� Ż���ϰ� �ӽ������� ������ ���� ũ�� ���� �� index�� 1�� ���� ��ġ�� �ֽ��ϴ�.
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


//�� ���� �Լ� sortByQuick�� �����Ͽ����ϴ�.
void sortByQuick(int* array, int start, int end)
{
	//��� �������� �ε��� start�� �ε��� end���� �۾ƾ� �մϴ�.
	if (start < end) {
		//partioning�Լ��� ���� �Ǻ� ���� �������� ���� ���� �Ǻ� ���� �κй迭�� ū ���� �Ǻ� ������ �κй迭�� ���� ����� �Ǻ��� �ε����� ��ȯ�մϴ�.
		int pivotidx = partioning(array, start, end); //�Ǻ��� �ε����� �����ϰ� �ֽ��ϴ�.
		//��������� �Ǻ��� �������� ���� �κ� �迭�� ������ �κй迭�� ���� sortByQuick�Լ��� ���� �������ϰ� �ֽ��ϴ�.
		sortByQuick(array, start, pivotidx-1);
		sortByQuick(array, pivotidx + 1, end);
	}
}

// �Ǻ����� �����ϰ� �� ���� �������� �� ������ �����ϸ� �Ǻ��� �ִ� �ε����� ��ȯ�մϴ�..
int partioning(int* array, int start, int end) 
{
	//temp�� ���� �ٲܶ� �ӽ������� ���� �����ϴ� �����Դϴ�.
	int temp;
	//�Ǻ� ���� �����ϰ��� �ϴ� �κ� �迭�� �� ���� ������ �����߽��ϴ�.
	int pivot = array[start];
	//startidx�� �κ� �迭���� ������ �����ϴ� �� �κ��Դϴ�.
	int startidx = start+1;
	//endidx�� �κ� �迭���� ������ �����ϴ� �� �κ��Դϴ�.
	int endidx = end;
	//while���� ���� ���ʿ��� �Ǻ����� ���� ���� �����ʿ��� �Ǻ� ���� ū ���� ��ġ�ϰ� ����ϴ�.
	while(startidx<=endidx){
		//�� �� �Ǻ����� ������ �κй迭�������� ���������� �� ĭ �� �̵��ϸ鼭 �Ǻ����� ū ���� ã���ϴ�.
		while (array[startidx] < pivot ) {
			startidx++;
		}
		//�� �ڿ������� �������� �� ĭ �� �̵��ϸ鼭 �Ǻ����� ���� ���� ã���ϴ�.
		while (array[endidx] > pivot) {
			endidx--;
		}
		//���ʿ��� �Ǻ����� ū ���� �����ʿ��� �Ǻ����� ���� ���� ã�� ����
		//startidx�� endidx�� ���� ���ΰ� ������ ���� ���ٸ� �� ���� ��ġ�� �ٲߴϴ�.
		if (startidx < endidx) {
			temp = array[startidx];
			array[startidx] = array[endidx];
			array[endidx] = temp;
		}
	
	}
	//�Ǻ����� ������ ��� ������ �Ǻ����� �������� ���� ���� ���� ū ���� �����ʿ� ��ġ�Ѵٸ�
	//���������� ���� ���� �� ���� ���ʿ� �ִ� ���� �Ǻ� ���� ��ġ�� �ٲߴϴ�.
	//���Ⱑ �߸��Ǿ���.
	temp = array[start];
	array[start] = array[endidx];
	array[endidx] = temp;
	return endidx;
}

//���� ���� �Լ� sortByMerge�� �����Ͽ����ϴ�
void sortByMerge(int* array, int start, int end)
{	
	//��� �������� start�� end���� �۾ƾ� �Լ��� �����մϴ�.
	if(start<end){ 
		//�迭�� ��Ȱ�ϱ� ���� �߰����� middle�� �����߽��ϴ�.
		int middle = (end + start) / 2;
		//�迭�� miidle�� ���� 2���� �κй迭�� ������ �� �κй迭�� ���� ��������� ���� ���� �Լ� sortByMerge�� ȣ���ϰ� �ֽ��ϴ�.
		sortByMerge(array, start, middle);
		sortByMerge(array, middle+1, end);
		//merge�Լ��� start���� end������ ������ ������� �����ϴ� ������ �մϴ�.
		merge(array, start, end);
	}
	else {
		return;
	}
}

//merge�� start���� end������ �ε��� ������ ������� �����մϴ�.
void merge(int* array, int start, int end)
{
	//start���� end���� �ִ� ���� �� ��ŭ �������� �迭�� �Ҵ��մϴ�.
	int* temparray = new int[end-start+1]; 
	//���⼭ middle�� ���� �κй迭�� ���� ����ŵ�ϴ�.
	int middle = (start + end) / 2;
	//idx�� temparray�� ���� ������ �� �ε��� ������ ���Դϴ�.
	int idx = 0;
	//startidx1�� startIdx2�� ���� ���� �κй迭�� �� �� �ε��� ������ �κй迭�� �� �� �ε����� ����ŵ�ϴ�.
	int startIdx1 = start;
	int startIdx2 = middle+1;
	//while���� ���� startIdx1�� startIdx2�� ������ �ش��ϴ� �κй迭�� ���� ���� �ʾҴٸ� �Ʒ� ������ �ݺ��մϴ�.
	while (startIdx1 <= middle && startIdx2 <= end) {//
		//���� startIdx1 �ε����� �ִ� ���� startIdx2 �ε����� �ִ� ������ �۴ٸ� temparray�� startIdx2�� �ִ� ���� �ְ� idx�� startIdx1�� ���� 1�ø��ϴ�.
		if (array[startIdx1] < array[startIdx2]) {
			temparray[idx++] = array[startIdx1++];
		}
		//���� startIdx2 �ε����� �ִ� ���� startIdx1 �ε����� �ִ� ������ �۴ٸ� temparray�� startIdx2�� �ִ� ���� �ְ� idx�� startIdx1�� ���� 1�ø��ϴ�.
		else {
			temparray[idx++] = array[startIdx2++];
		}
	}
	//���� while���� �Ϸ�� ��� �κй迭 �� �Ѱ��� ���� ���� �� temparray�� �������� �ʾұ� ������
	//if���� ���� ���� ��� ���� �������� ���� �κй迭�� ������ �������ݴϴ�.
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
	//�� �۾��� ������ temparray�� ���ĵ� �κ� �迭�� ������ �� �ٵ� �� ���ĵ� �κ� �迭�� ��ü �迭�� array�� �����մϴ�.
	for (int i = start, idx =0 ; i <= end; i++, idx++) {
		array[i] = temparray[idx];
	}
	//temparray�� �Ҵ��� �����մϴ�.
	delete[] temparray;
}

//�迭�� ������ ����� �Լ� heapify�� �����մϴ�.
//�ּ������� �����մϴ�.
void heapify(int* array, int start, int end)
{
	bool haveLeftChild = false;
	bool haveRightChild = false;
	int temp;
	//�ش� ���Ұ� ���� �ڽ��� ������ �ִٸ� �̸� �˸��� ���� ���Դϴ�.
	if (start * 2 <= end) {
		haveLeftChild = true;
	}
	//�ش� ���Ұ� ������ �ڽ��� ������ �ִٸ� �̸� �˸��� ���� ���Դϴ�.
	if (start * 2 + 1 <= end) {
		haveRightChild = true;
	}
	//���� �ڽİ� ������ �ڽ��� ���� ���
	if (haveLeftChild == true && haveRightChild == true) {
		//�ڽ� �߿� �� ���� ���� ������ ���� ��� 
		if (array[start] > array[start * 2] || array[start]>array[start*2+1]) {
			//�ڽ� �߿� ���� �ڽ��� �ּҰ��� ���
			if (array[start * 2] < array[start * 2 + 1]) {
				temp = array[start];
				array[start] = array[start * 2];
				array[start * 2] = temp;
				heapify(array, start * 2, end);
			}
			//�ڽ� �߿� ������ �ڽ��� �ּҰ��� ���
			else {
				temp = array[start];
				array[start] = array[start * 2 + 1];
				array[start * 2 + 1] = temp;
				heapify(array, start * 2 + 1, end);
			}
		}
		//�ڽ� �߿� �ּڰ��� �����ְ� ���� ��� �ƹ��͵� ����.
		else {
			return;
		}
	}
	//���� �ڽĸ� ���� ���
	else if (haveLeftChild == true && haveRightChild == false) {
		//���� �ڽ��� �� ���� ���� ������ ���� ���
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

//���� Ž�� �Լ� binarySearch�� �����մϴ�.
int binarySearch(int* array, int start, int end, int searchNum)
{
	//���� start���� end���� ũ�ٸ� �������� �ʽ��ϴ�.
	if(start<=end){
		//�迭�� �߰��� ����Ű�� middle ������ �����մϴ�.
		int middle = (start + end) / 2;
		//�ε��� middle�� ���� searchNum�� ���� ���ٸ� middle�� ��ȯ�մϴ�.
		if (array[middle] == searchNum) {
			return middle;
		}
		//�ε��� middle�� ���� searchNum���� �۴ٸ� middle+1���� end������ ������ �ٽ� ��������� ����Ž���� �մϴ�.
		else if (array[middle] < searchNum) {
			return binarySearch(array, middle + 1, end, searchNum);
		}
		//�ε��� middle�� ���� searchNum���� ũ�ٸ� middle-1���� start������ ������ �ٽ� ��������� ����Ž���� �մϴ�.
		else if (array[middle] > searchNum) {
			return binarySearch(array, start, middle - 1,searchNum);
		}
	}
	//���� ���� ã�� ���ϸ� -999�� ��ȯ�մϴ�.
	else {
		return -999;
	}
}
//nthNum��°�� ���� ���� ���ϴ� �Լ� selectionByQuick�� �����մϴ�.
int selectionByQuick(int* array, int start, int end, int nthNum)
{
	if (start <= end) {
		//partioning�� ���� �Ǻ��� �ε����� ����ϴ�.
		int pivotIdx = partioning(array, start, end);
		//�Ǻ��� �ε����� nthNum-1�� ���ٸ� �Ǻ��� nthNum��° ���̱� ������ array[pivot]�� ��ȯ�մϴ�.
		if (pivotIdx == nthNum - 1) {
			// nthNum��° ���� ��ȯ�մϴ�.
			return array[pivotIdx];
		}
		//�Ǻ��� �ε����� nthNum-1���� ũ�ٸ� �Ǻ� ���� �����ʿ� ã���� �ϴ� nthNum��° ���� �ֱ� ������ �ش� �κ� �迭�� ��������� selectionByQuick�Լ��� ����մϴ�.
		else if (pivotIdx > nthNum - 1) {
			return selectionByQuick(array, start, pivotIdx - 1, nthNum);
		}
		//�Ǻ��� �ε����� nthNum-1���� �۴ٸ� �Ǻ� ���� ���ʿ� ã���� �ϴ� nthNum��° ���� �ֱ� ������ �ش� �κ� �迭�� ��������� selectionByQuick�Լ��� ����մϴ�.
		else {
			return selectionByQuick(array, pivotIdx + 1, end, nthNum);
		}
	}
	//nthNum��° ���� ã�� ���ϸ� -1�� ��ȯ�մϴ�.
	else {
		return -1;
	}
}
binaryTree:: binaryTree() {
		this->value = NULL;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
	//����Ʈ���� ���� �����ϴ� �Լ� insertNum�Դϴ�.
	void binaryTree::insertNum(int num)
	{
		//�ش� ��忡 ���� �������� ������ ���� �����մϴ�.
		//���� �����ϱ� ������ �Ʒ� �ڵ忡�� ��带 ���� ����� �����ϴ�.
		if (this->value == NULL) {
			this->value = num;
			return;
		}
		//���� �����ϰ��� �ϴ� �� num���� ���� ����� ���� ũ�ٸ� ���ʼ���Ʈ���� �־�� �մϴ�. 
		else if (this->value > num) {
			//�̶� ���� �ڽ��� nullptr�̶�� ��带 �����ϰ� ��������� insertNum�� ȣ���� ���� �������ݴϴ�.
			if (this->leftChild == nullptr) {
				binaryTree* temp = new binaryTree();
				this->leftChild = temp;
				this->leftChild->insertNum(num);
				return;
			}
			//���� �ڽ��� �ִٸ� ���� �ڽĿ� ���� ��������� insertNum�� ȣ���� ã���� �ϴ� ���� ã���ϴ�.
			else {
				this->leftChild->insertNum(num);
				return;
			}
		}
		//���� �����ϰ��� �ϴ� �� num���� ���� ����� ���� �۴ٸ� �����ʼ���Ʈ���� �־�� �մϴ�. 
		else if (this->value < num) {
			//�̶� ������ �ڽ��� nullptr�̶�� ��带 �����ϰ� ��������� insertNum�� ȣ���� ���� �������ݴϴ�
			if (this->rightChild == nullptr) {
				binaryTree* temp = new binaryTree();
				this->rightChild = temp;
				this->rightChild->insertNum(num);
				return;
			}
			//������ �ڽ��� �ִٸ� ������ �ڽĿ� ���� ��������� insertNum�� ȣ���� ã���� �ϴ� ���� ã���ϴ�.
			else {
				this->rightChild->insertNum(num);
				return;
			}
		}
		//�ƹ� �ǹ̵� ���� �����Դϴ�.
		else {
			return;
		}
	}

	void binaryTree::deleteNum(int num)
	{
		binaryTree* parentNode = nullptr;
		binaryTree* childNode = this;
		// isRight�� parentNode���� child��尡 ������ �ڽ����� �ƴ����� �˷��ִ� ����.
		bool isRight;
		//���� �ֻ��� ��带 �����ؾ� �Ѵٸ� parentNode �� nullptr�� �ȴ� �̰� �̿�����
		//���� �ֻ��� ��尡 �ƴ϶�� �������� ���� �ڵ带 �����
		//���� ��忡 ���� �����ϰ��� �ϴ� ���� ���� �ʴٸ� ���� ã�ų� ���� ���ٴ� ���� Ȯ���� ������ �ݺ��Ѵ�.
		while (childNode->value != num) { 
			//���� ���� ã���� �ϴ� ������ ũ�ٸ� ���� ���� Ʈ������ ���� ã�ƾ� �Ѵ�.
			if (childNode->value > num && childNode->leftChild !=nullptr) {
				isRight = false;
				parentNode = childNode;
				childNode = childNode->leftChild;
			}
			//���� ���� ã���� �ϴ� ������ �۴ٸ� ������ ���� Ʈ������ ���� ã�ƾ� �Ѵ�.
			else if(childNode->value < num && childNode->rightChild !=nullptr){
				isRight = true;
				parentNode = childNode;
				childNode = childNode->rightChild;
			}
			else {
				//���� ��� �� ã��.
				return;
			}
		}
		//�����ϰ��� �ϴ� ���� ã��
		//���� �۾� ����
		//�����ϰ� �ϴ� ���� ������忩�� �ڽ��� ���ٸ�
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
			//�����ϰ��� �ϴ� ���� ���� �ڽĸ� ������ �ִٸ�
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
			//�����ϰ��� �ϴ� ���� ������ �ڽĸ� ������ �ִٸ�
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
			//�����ϰ��� �ϴ� ���� ���� ������ �ڽ� �� ������ �ִٸ�
			else {
				binaryTree* changeNode = childNode->leftChild;
				binaryTree* parentChangeNode = nullptr;
				while (changeNode->rightChild != nullptr) {
					parentChangeNode = changeNode;
					changeNode = changeNode->rightChild;
				}
				//���� ����Ʈ���� ���� ū ���� childNode���� �ڽ��� ���
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
				//���� ����Ʈ���� ���� ū ���� childNode�� ���� �ڽ��� �ƴҰ��
				else {
					//�ٲٰ��� �ϴ� changeNode�� ���� �ڽ��� ���� ���
					if (changeNode->leftChild == nullptr) {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = nullptr;
						delete changeNode;
						return;
					}
					//�ٲٰ��� �ϴ� changeNode�� ���� �ڽ��� �ִ� ���
					else {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = changeNode->leftChild;
						delete changeNode;
						return;
					}
				}
			}
		}
		//�����ϰ��� �ϴ� ���� �ֻ��� ��Ʈ ��忡 �־��ٸ�
		else {
			if (childNode->leftChild == nullptr && childNode->rightChild == nullptr) {
				childNode->value = NULL;
				childNode->leftChild = nullptr;
				childNode->rightChild = nullptr;
				return;
			}
			//���� �ڽĸ� �ִٸ�
			else if (childNode->leftChild != nullptr && childNode->rightChild == nullptr)
			{
				binaryTree* temp = childNode->leftChild;
				childNode->value = childNode->leftChild->value;
				childNode->leftChild = childNode->leftChild->leftChild;
				childNode->rightChild = childNode->leftChild->rightChild;
				delete temp;
				return;
			}
			//������ �ڽĸ� �ִٸ�
			else if (childNode->leftChild == nullptr && childNode->rightChild != nullptr) {
				binaryTree* temp = childNode->rightChild;
				childNode->value = childNode->rightChild->value;
				childNode->leftChild = childNode->rightChild->leftChild;
				childNode->rightChild = childNode->rightChild->rightChild;
				delete temp;
				return;
			}
			//���� �ٽ� �� �ʿ䰡 �ִ�.
			//�ڽ� �Ѵ� �ִٸ�
			else {
				binaryTree* changeNode = childNode->leftChild;
				binaryTree* parentChangeNode = nullptr;
				while (changeNode->rightChild != nullptr) {
					parentChangeNode = changeNode;
					changeNode = changeNode->rightChild;
				}
				//���� ����Ʈ���� ���� ū ���� childNode���� �ڽ��� ���
				if (childNode->leftChild == changeNode) {
					binaryTree* temp = childNode->leftChild;
					childNode->value = childNode->leftChild->value;
					childNode->leftChild = childNode->leftChild->leftChild;
					delete temp;
				}
				//���� ����Ʈ���� ���� ū ���� childNode�� ���� �ڽ��� �ƴҰ��
				else {
					//�ٲٰ��� �ϴ� changeNode�� ���� �ڽ��� ���� ���
					if (changeNode->leftChild == nullptr) {
						childNode->value = changeNode->value;
						parentChangeNode->rightChild = nullptr;
						delete changeNode;
						return;
					}
					//�ٲٰ��� �ϴ� changeNode�� ���� �ڽ��� �ִ� ���
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
		//���� ��ȸ �����ؾ���
		// ť ������ �ϰ�
		//�̰ž�Ƴ�
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