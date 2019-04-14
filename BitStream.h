#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <vector>

class BitStream
{
public:
        BitStream(std::string inputName, std::string outputName);
	~BitStream();

	int putBit(unsigned int bit);
	int putByte(unsigned char byte);
	void putSize(unsigned int charCount);

	void flush();
	
	unsigned int checkSize();
	int getBit();
	unsigned char getByte();

private:
	unsigned char buffer;
	int counter;
	std::fstream outFile;
	std::fstream inFile;
};
