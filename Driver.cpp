#include "Heap.h"
#include <string>
#include "Table.h"
#include "HTree.h"
#include "Node.h"
#include "Huff.h"
#include "Puff.h"
using namespace std;

#if 1
int main(int argc, char *argv[])
{
	std::string fileName = argv[1];
	if (argc > 1)
	{
		Huff huff(fileName);
	}
	return 0;
}
#else
int main() {
	Puff puff("sampleText.huff");
	return 0;
}
#endif
