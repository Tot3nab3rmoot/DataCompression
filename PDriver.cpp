#include "Heap.h"
#include <string>
#include "Table.h"
#include "HTree.h"
#include "Node.h"
#include "Puff.h"
using namespace std;


int main(int argc, char *argv[])
{
	if (argc > 1) {
	  std::string fileName = argv[1];
	  Puff puff(fileName);
	}
	return 0;
}
