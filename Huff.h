#pragma once
#include <string>
#include "BitStream.h"
#include "HTree.h"
#include "Table.h"
#include "Heap.h"

class Huff
{
public:
	Huff(std::string fileName);
	~Huff();

	void buildHuff(std::string fileName);


};

