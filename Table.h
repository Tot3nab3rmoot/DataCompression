#pragma once
#include <map>
#include <fstream>
#include <string>
#include "Heap.h"
#include "Node.h"


class Table {

public:
	Table();

	bool buildTable(std::string fileName);
	void dump();
	void constructHeap(Heap<int, Node*> &heap);
	unsigned int getSCount();

private:
	std::map <unsigned char, int> table;
	unsigned int sCount;
};