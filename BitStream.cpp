#include "BitStream.h"



BitStream::BitStream(std::string inputName, std::string outputName)
{
        if (inputName != "") {
	  inFile.open(inputName, std::fstream::in);
	}

	if (outputName != "") {
	  outFile.open(outputName, std::fstream::out);
	}
	
	buffer = 0;
	counter = 7;
}

BitStream::~BitStream() {
	flush();
	inFile.close();
	outFile.close();
}

int BitStream::putBit(unsigned int bit) {
	int i=-1;
	if (bit == 1) {
		buffer |= 1 << counter;
		counter--;
		i = 1;
	}
	if (bit == 0) {
		counter--;
		i = 0;
	}
	if (counter < 0) {
		outFile << buffer;
		buffer = 0;
		counter = 7;
		i = 2;
	}
	return i;
}

int BitStream::putByte(unsigned char byte) {
	flush();
	outFile << byte;
	return 0;
	
}

void BitStream::putSize(unsigned int charCount) {
	std::cout << "Char Count: " << charCount << std::endl;
	unsigned char b1 = 0;
	unsigned char b2 = 0;
	unsigned char b3 = 0;
	unsigned char b4 = 0;
	std::vector <unsigned char> temp = { b1, b2, b3, b4 };

	for (int i = 3; i >= 0; --i) {
		temp[i] = charCount & 0xFF;
		std::cout << std::bitset<8>(temp[i]) << std::endl;
		outFile << temp[i];
		charCount = charCount >> 8;
		std::cout << "charCount" << charCount << std::endl;
	}
}

void BitStream::flush() {
	if (counter == 7) {
		return;
	}
	outFile << buffer;
	buffer = 0;
	counter = 7;
}

int BitStream::getBit() {
  if (counter == 7) {
    getByte();
  }
  unsigned int temp = buffer >> counter & 1;
  counter--;
  if (counter < 0) {
    counter = 7;
  }
  return temp;
}

unsigned char BitStream::getByte() {
	buffer = 0;
	counter = -1;
	if (inFile.peek() != EOF) {
		buffer |= inFile.get();
		//std::cout << "buffer " << (int)buffer;
		counter = 7;
		return buffer;
	}
	return -1;
}


unsigned int BitStream::checkSize() {
	unsigned int count = 0;
	for (int i = 0; i < 4; i++) {
		unsigned int bit = getByte();
		count |= bit << (i * 8);
	}
	return count;
}
