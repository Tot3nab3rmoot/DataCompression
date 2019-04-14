#pragma once
#include <iostream>

class Node {
public:
  Node() : priority_(), data_(), left_(nullptr), right_(nullptr) {}
  //Node(int pri) : priority_(pri), data_(), left_(nullptr), right_(nullptr) {}

  Node(Node* left, Node* right):
    priority_(left->priority_ + right->priority_),
    data_(0),
    left_(left),
    right_(right) {
  }
  

	Node(int pri, unsigned char data) : priority_(pri), data_(data), left_(nullptr), right_(nullptr)  {}

	int priority() { return priority_; }
	const unsigned char& data() { return data_; }
	Node* left() { return left_; }
	Node* right() { return right_; }

	void setPriority(int pri) { priority_ = pri; }
	void setData(unsigned char data) { data_ = data; }
	void setLeft(Node* left) { left_ = left; }
	void setRight(Node* right) { right_ = right; }

  bool isLeaf() {return left_ == nullptr;}

        void print();
	void dump(int indent);


private:
	int priority_;
	unsigned char data_;
	Node* left_;
	Node* right_;

};

