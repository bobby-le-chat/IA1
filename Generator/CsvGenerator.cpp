#include<iostream>
#include<fstream>
#include "CsvGenerator.h"

CsvGenerator::CsvGenerator()
 :  _categories(), _rows()
{

}

void CsvGenerator::exportToFile(const std::string& filepath, bool withCategory)
{
    std::ofstream outputFile;
    
    outputFile.open(filepath.c_str());
    if (!outputFile.is_open())
      return;

    
    if (withCategory)
    {
	std::vector<Category>::iterator begin_category = this->_categories.begin();
	std::vector<Category>::iterator end_category = this->_categories.end();
	
	while(begin_category != end_category)
	{
	    outputFile << begin_category->getName() << ";";
	    ++begin_category;
	}
	outputFile << std::endl;
    }
    
    std::vector<Row>::iterator begin_row = this->_rows.begin();
    std::vector<Row>::iterator end_row = this->_rows.end();
    
    while (begin_row != end_row)
    {
	std::vector<Node> nodes = begin_row->getNodes();
	std::vector<Node>::iterator begin_node = nodes.begin();
	std::vector<Node>::iterator end_node = nodes.end();
	while (begin_node != end_node)
	{
	  outputFile << begin_node->getValue() << ";";
	  ++begin_node;
	}
	outputFile << std::endl;
	++begin_row;
    }
}

void CsvGenerator::generateAndExport(const std::string& filepath, int nbRowGenerate, bool withCategory)
{
  this->generate(nbRowGenerate);
  this->exportToFile(filepath);
}


const std::vector<Row>& CsvGenerator::generate(int nbRowGenerate)
{
  this->_rows.clear();
  for (int y = 0; y < nbRowGenerate; ++y)
  { 
    Row	newRow;
    int x = 0;
    std::vector<Category>::iterator  current_category = this->_categories.begin();
    while (current_category != this->_categories.end())
    {
      Node 	newNode;
      const std::pair<std::string, float> value = current_category->getRandomValue();
      newNode.setParams(value.first, value.second, std::pair<int, int>(x, y));
      current_category->addNode(newNode);
      newRow.addNode(newNode);
      current_category++;
    }
    this->_rows.push_back(newRow);
  }
  return this->_rows;
}

void CsvGenerator::addCategory(const Category& category)
{
  this->_categories.push_back(category);
}
