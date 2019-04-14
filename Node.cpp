#include "Node.h"
using namespace std;

void Node::print() {
  std::cout << this
            << " "
	    << "priority(" << priority_ << "), "
	    << "data(" << data_ << "), "
	    << "left(" << left_ << "), "
	    << "right(" << right_ << ")";
}

void Node::dump(int indent)
{
	for (int i = 0; i < indent; i++)
	{
		std::cout << "+----";
	}
	print(); cout << endl;
	if (left_)
	{
		left_->dump(indent + 1);
	}
	if (right_)
	{
		right_->dump(indent + 1);
	}
}
