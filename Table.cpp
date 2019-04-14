#include "Table.h"


Table::Table()
{
	sCount = 0;
}

bool Table::buildTable(std::string fileName) {

	std::ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open()) {
		char item;
		while (inFile.get(item)) {
			++table[(unsigned char)item];
			std::cout << item << " ";
			sCount++;
		}

		std::cout << std::endl;
		inFile.close();
		return true;
	}
	else {
		std::cout << "File: " << fileName << " not found" << std::endl;
		return false;
	}
}


void Table::dump() {
	for (std::map<unsigned char, int>::iterator it = table.begin(); it != table.end(); ++it) {
		std::cout << it->first;
		for (int i = 1; i < it->second; i++) {
			std::cout << "+";
		}
		std::cout << std::endl;
	}

}

void Table::constructHeap(Heap<int, Node*> &heap) {
	for (std::map<unsigned char, int>::iterator it = table.begin(); it != table.end(); ++it) {
		Node* temp = new Node(it->second, it->first);
		heap.push(it->second, temp);
	}
}

unsigned int Table::getSCount()
{
	/*std::cout << "this is the number of symbols: " << sCount << std::endl;*/
	return sCount;
}


/*template<class Priority, class Data>
std::map<Data, int>::iterator Table<Priority, Data>::begin()
{
return table.begin();
}

template<class Priority, class Data>
std::map<Data, int>::iterator Table<Priority, Data>::end()
{
return table.end();
}*/

