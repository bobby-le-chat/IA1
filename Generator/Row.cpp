#include "Row.h"

Row::Row()
{
  
}

Row::Row(const Row& other)
{
  this->_nodes = other._nodes;
  this->_y = other._y;
}

Row::~Row()
{

}

Row& Row::operator=(const Row& other)
{
  if (this != &other)
  {  
    this->_nodes = other._nodes;
    this->_y = other._y;
  }
  return *this;
}

bool Row::operator==(const Row& other) const
{
   return (this->_nodes == other._nodes && this->_y == other._y);
}

void Row::addNode(const Node& node)
{
  this->_nodes.push_back(node);
}
 
void Row::addNode(const Node& node, int x)
{
  this->_nodes.at(x) = node;
}

void Row::deleteNode(const Node& node)
{
  std::vector<Node>::iterator start = this->_nodes.begin();
  std::vector<Node>::iterator end = this->_nodes.end();
  while (start != end)
  {
      if (*start == node)
      {
	 this->_nodes.erase(start);
	 return;
      }
      start++;
  }
}

void Row::deleteNode(int x)
{
  this->_nodes.erase(this->_nodes.begin() + x);
}

int Row::getLineNumber() const
{
  return this->_y;
}

const std::vector< Node >& Row::getNodes() const
{
  return this->_nodes;
}

