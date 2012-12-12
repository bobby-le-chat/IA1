#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Category.h"

Category::Category(const std::string& name, float weight, bool maximize)
  : _name(name), _values(), _weight(weight), _maximize(maximize)
{
  srand(time(NULL));
}


Category::Category(const Category& other)
{
	this->_name = other._name;
	this->_values = other._values;
	this-> _maximize = other._maximize;
	this->_weight = other._weight;
}

Category::~Category()
{

}

Category& Category::operator=(const Category& other)
{
	this->_name = other._name;
	this->_values = other._values;
	this-> _maximize = other._maximize;
	this->_weight = other._weight;
  return *this;
}

bool Category::operator==(const Category& other) const
{
  return (this->_name == other._name && 
  this->_values == other._values && this->_nodes == this->_nodes);
}

void Category::addValues(const std::string& name, float poid = 0)
{
  this->_values.insert(std::pair<std::string, float>(name, poid));
}

void Category::deleteValues(const std::string& name)
{
    this->_values.erase(name);
}

const std::string& Category::getName() const
{
  return this->_name;
}

const std::pair<std::string, float> Category::getRandomValue() const
{
   std::map<std::string, float>::const_iterator begin = this->_values.begin();
   std::map<std::string, float>::const_iterator end = this->_values.end();
   int random  = rand() % this->_values.size();
   for (int i = 0; begin != end; ++i)
   {
     if (i == random)
      return std::pair<std::string, float>(begin->first, begin->second);
     begin++;
   }
   return std::pair<std::string, float>();
}

void Category::addNode(const Node& node)
{
  this->_nodes.push_back(node);
}

void Category::deleteNode(const Node& node)
{
 this->_nodes.erase( this->_nodes.begin() + node.getAbs().first);
}

