#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	binaryTree biTree;
	biTree.insertNum(5);
	biTree.insertNum(4);
	biTree.insertNum(6);
	biTree.printTree();
	biTree.deleteNum(4);
	biTree.printTree();
	biTree.deleteNum(6);
	biTree.deleteNum(7);
	biTree.printTree();

}