#include <iomanip>

#include "HTree.h"

using namespace std;


HTree::HTree(string fileName) : bitStr(fileName, "") {
	root = new Node();
	int nLength = (int)fileName.find('.');
	int remove = fileName.length() - nLength;
	std::string newFile = fileName.replace(nLength, remove, ".puff");
	outFile.open(newFile, std::fstream::out);
}

HTree::HTree(Heap<int, Node*> &PQ, std::string outputFileName) : bitStr("", outputFileName) {
	root = nullptr;
	for (int i=0; i<256; i++) {
	  codedSymbles[i].bitNum = 0;
	  codedSymbles[i].bitPattern = 0;
	}
	buildTree(PQ);
}


void HTree::buildTree(Heap<int, Node*> &PQ) {
	while (PQ.size()>2) {
		PQ.dumpArr();

		Node *left = PQ.pop();
		PQ.dumpArr();
		Node *right = PQ.pop();
		PQ.dumpArr();

		cout << "popped ";
		left->print();
		cout << " and ";
		right->print();
		cout << endl;

		Node *root = new Node(left, right);

		cout << "pushing " << root << endl;
		root->print();
		cout << endl;

		PQ.push(root->priority(), root);
		PQ.dumpArr();
	}
	root = PQ.peek();
	root->dump(0);
}

void HTree::codedTab()
{
	codedTable(root, 0, 0);
	codeDump();
}

void HTree::codedTable(Node* curr, unsigned char bitNum, unsigned long long bitPattern) {
		
	if(!curr->left() && !curr->right()) {
		codedSymbles[curr->data()].bitNum = bitNum;
		codedSymbles[curr->data()].bitPattern = bitPattern;
	}
	else {
	        ++bitNum;
		bitPattern = bitPattern << 1;
		codedTable(curr->left(), bitNum, bitPattern);
		codedTable(curr->right(), bitNum, bitPattern | 1);
	}
	
}


void HTree::codeDump()
{
	cout << "char\tindex\tbitNum\tbitPattern" << endl;
	int i = 0;
	while (i < 256) {
		if (codedSymbles[i].bitNum != 0) {
			cout << (char)i << "\t";
			cout << i << "\t";
			cout << (int) codedSymbles[i].bitNum << "\t";
			cout << bitset<64>(codedSymbles[i].bitPattern) << endl;
		}
		i++;
	}
}

void HTree::printCodedSym(string fileName, unsigned int sCount) {
	cout << "symbol count: -----------------------------------" << sCount << endl;
	//printCodedSymbols
	for (int i = 0; i < 256; ++i) {
	  bitStr.putByte(codedSymbles[i].bitNum);
	  if (codedSymbles[i].bitNum != 0) {
	    unsigned long long pattern = codedSymbles[i].bitPattern;
	    for (int y = codedSymbles[i].bitNum - 1; y >= 0; --y) {
	      bitStr.putBit((pattern >> y) & 1);
	    }
	    bitStr.flush();
	  }
	}
	
	//print the size
	bitStr.putSize(sCount);

	//print the actual file now finally hahahah
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open()) {
		char raw_item;
		while (inFile.get(raw_item)) {
			unsigned char item = raw_item;
			unsigned char length = codedSymbles[item].bitNum;
			unsigned long long pattern = codedSymbles[item].bitPattern;
			for (int y = length - 1; y >= 0; --y) {
			  bitStr.putBit((pattern >> y) & 1);
			}
		}
		bitStr.flush();
		inFile.close();  
	}
}

/*Node * HTree::getRoot()
{
	return root;
}*/

void HTree::buildPTree() {
	cout << "building PTree_________________________" << endl;
	for (int i = 0; i < 256; ++i) {
	  unsigned int countBit = bitStr.getByte();
	  if (countBit != 0) {
	    Node* node = root;
	    unsigned long long pattern = 0;
	    for (unsigned int y = 0; y < countBit; y++) {
	      pattern = pattern << 1;
	      if (bitStr.getBit()) {
		if (!node->right()) {
		  node->setRight(new Node());
		}
		pattern = pattern | 1;
		node = node->right();
	      } else {
		if (!node->left()) {
		  node->setLeft(new Node());
		}
		node = node->left();
	      }
	    }
	    node->setData(i);
	    cout << "%%%%%%%%%%%%%%%%%%%%%%%% insert character " << i
		 << " length " << countBit
		 << "  pattern " << hex << pattern << dec
		 << endl;
	    root->dump(0);
	  }
	  bitStr.flush();
	}
	cout << "tree is Built______________________" << endl;
	root->dump(0);
}

void HTree::writeSymoles() {
	/*cout << "after Pufftree is built" << endl;*/
	//root->dump(0);

	unsigned int symbolCount = bitStr.checkSize();
//	cout << "symbolCount..................." << symbolCount;
	unsigned int symbolEnd = 0;
	Node* curr = root;
	//unsigned char symbol = 0;
	while (symbolCount != symbolEnd) {
	  if (bitStr.getBit()) {
	    curr = curr->right();
	  } else {
	    curr = curr->left();
	  }
	  if (curr->isLeaf()) {
	    outFile << curr->data();
	    ++symbolEnd;
	    curr = root;
	  }
	}
}

void HTree::puffTreeInsert(unsigned char symbol, double countBit, unsigned long long bitPath) {
	Node* curr = root;
	for (int i = 0; i < countBit; i++) {
		int next = bitPath >> (63 - i) & 1;
		if (next == 0) {
			if (!curr->left()) {
				Node* temp = new Node();
				curr->setLeft(temp);
				curr = curr->left();
			}
			else {
				curr = curr->left();
			}
		}
		else {
			if (!curr->right()) {
				Node* temp = new Node();
				curr->setRight(temp);
				curr = curr->right();
			}
			else {
				curr = curr->right();
			}
		}
	}
	curr->setData(symbol);
}

		//inFile.close();// do not close so we don't start from the beginning
		//cout << "this is the number of symboles: " << bitStr.checkSize()<< std::endl;
		//cout << "this is the number of symboles: " << bitStr.checkSize() << std::endl;
		
	
		
//}
