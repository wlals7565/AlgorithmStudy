#include <iostream>
#include "AlgorithmStudy.h"

int main() {
	binaryTree biTree;
	biTree.insertNum(10);
	biTree.insertNum(5);
	biTree.insertNum(13);
	biTree.insertNum(15);
	biTree.insertNum(6);
	biTree.insertNum(3);
	biTree.insertNum(2);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(5);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(10);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(13);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(10);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(2);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(3);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(6);
	biTree.printTree();
	std::cout << std::endl;
	biTree.deleteNum(15);
	biTree.printTree();

}