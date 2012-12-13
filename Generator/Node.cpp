#include "Node.h"

Node::Node(const std::string& value, float poid, int x, int y)
: _value(), _poid(-1), _abs(2, -1)
{
 this->setParams(value, poid, std::pair<int, int>(x,y));
}

Node::Node()
: _value(), _poid(-1), _abs(2, -1)
{

}

Node::Node(const Node& other)
{ 
  this->_abs = other._abs;
  this->_poid = other._poid;
  this->_value = other._value;
}

Node::~Node()
{

}

Node& Node::operator=(const Node& other)
{
   if (this != &other)
   {  
    this->_abs = other._abs;
    this->_poid = other._poid;
    this->_value = other._value;
   }
  return *this;
}

bool Node::operator==(const Node& other) const
{
  return (this->_abs == other._abs && this->_poid == other._poid && this->_value == other._value);
}

const std::pair< int, int >& Node::getAbs() const
{
  return this->_abs;
}

float Node::getWeight() const
{
  return this->_poid;
}

void Node::setWeight(float weight)
{
	this->_poid = weight;
}

const std::string& Node::getValue() const
{
  return this->_value;
}

void Node::setAbs(int x, int y)
{
  this->_abs.first = x;
  this->_abs.second = y;
}

void Node::setParams(const std::string& value, float poid, const std::pair< int, int >& abs)
{
  this->_abs = abs;
  this->_poid = poid;
  this->_value = value;
}


