#pragma once
#include "Heap.h"
#include "Node.h"
#include "BitStream.h"
#include <iostream>
#include <bitset>
#include <math.h>


class HTree {

public:
	HTree(std::string fileName);
	HTree(Heap<int, Node*> &PQ, std::string outputFileName);

	void buildTree(Heap<int, Node*> &PQ);
	void codedTab();
	void codeDump();
	void printCodedSym(std::string fileName, unsigned int count);

	void buildPTree();
	void writeSymoles();

private:
	Node * root;
	BitStream bitStr;
	std::fstream outFile;
	struct ByteCode {
		unsigned char bitNum;
		unsigned long long bitPattern;
	};
	ByteCode codedSymbles[256];
	void puffTreeInsert(unsigned char symbol, double countBit, unsigned long long bitPath);
	void codedTable(Node* curr, unsigned char bitNum, unsigned long long bitPattern);
};
