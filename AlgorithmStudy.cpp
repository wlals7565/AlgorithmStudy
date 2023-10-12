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

void sortByQuick(int* array, int start, int end)
{
	if (start < end) {
		int pivotidx = partioning(array, start, end); //�Ǻ��� �ε����� �޽��ϴ�.
		sortByQuick(array, start, pivotidx);
		sortByQuick(array, pivotidx + 1, end);
	}
}

int partioning(int* array, int start, int end) //�Ǻ����� �ִ� �ε����� ��ȯ�մϴ�.
{
	int temp;
	int pivot = array[start];
	int startidx = start+1;
	int endidx = end - 1;
	while(startidx<endidx){
		while (array[startidx] < pivot) {
			startidx++;
		}
		while (array[endidx] > pivot) {
			endidx--;
		}
		if (startidx < endidx) {
			temp = array[startidx];
			array[startidx] = array[endidx];
			array[endidx] = temp;
		}
	}
	temp = array[start];
	array[start] = array[endidx];
	array[endidx] = temp;
	return endidx;
}
