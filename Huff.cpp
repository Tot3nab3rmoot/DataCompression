#include "Huff.h"



Huff::Huff(std::string fileName)
{
	buildHuff(fileName);
}


Huff::~Huff()
{
}

void Huff::buildHuff(std::string fileName)
{
	Table table;
	table.buildTable(fileName);
	Heap<int, Node*> heap;
	table.constructHeap(heap);

	HTree huffTree(heap, fileName + ".huff");
	huffTree.codedTab();
	

	//call print to the file method
	unsigned int sCount = table.getSCount();
	huffTree.printCodedSym(fileName, sCount);
	

}
