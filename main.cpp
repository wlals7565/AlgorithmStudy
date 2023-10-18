#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	binaryTree biTree;
	biTree.insertNum(5);
	biTree.insertNum(4);
	biTree.insertNum(6);
	biTree.printTree();
	std::cout << std::endl <<biTree.searchNum(6)<< ", "<< biTree.searchNum(7);

}