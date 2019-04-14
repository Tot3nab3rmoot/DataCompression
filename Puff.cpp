#include "Puff.h"



Puff::Puff(std::string fileName ) {
	//Heap<int, Node*> hi;
	HTree pufT(fileName);
	pufT.buildPTree();
	pufT.writeSymoles();
}


Puff::~Puff() {
}
/*
void Puff::buildPTree(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);
	BitStream bitStr(fileName, ".puff");
	if (inFile.is_open()) {
		int i = 0;
		Node* curr = root;
		int next;
		unsigned char symbol;
		while (i < 256) {
			symbol = bitStr.getByte();
			for (int y = 0; y < symbol; y++) {
				next = bitStr.getBit();
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
				if (next == 1) {
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
			i++;
		}

		inFile.close();
	}
}*/