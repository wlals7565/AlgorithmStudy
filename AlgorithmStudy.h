#pragma once
void sortBySelection(int*, int);

void sortByBubble(int*, int);

void sortByInsertion(int*, int);

void sortByQuick(int*, int, int);

int partioning(int*, int, int);

void sortByMerge(int*, int, int);

void merge(int*, int, int);

void heapify(int*, int, int);

int binarySearch(int*, int, int, int);

int selectionByQuick(int*, int, int, int);

class binaryTree {
	int value;
	binaryTree* leftChild;
	binaryTree* rightChild;
public:
	binaryTree();
	void insertNum(int);
	void deleteNum(int);
	bool searchNum(int);
	void printTree();
};