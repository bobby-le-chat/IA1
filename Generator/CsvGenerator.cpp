#include<iostream>
#include<fstream>
#include<algorithm>
#include "CategoryFactory.h"
#include "CsvGenerator.h"
#include "CalcPondarateRow.h"

CsvGenerator::CsvGenerator() :
		_categories(), _rows(), _controleValue(0.09) {

}

void CsvGenerator::exportToFile(const std::string& filepath,
		bool withCategory) {
	std::ofstream outputFile;
	std::ofstream debugFile;


	outputFile.open(filepath.c_str());
	debugFile.open("debug.csv");
	if (!outputFile.is_open())
		return;

	std::vector<Category> normalized_categories = this->normalizeCategories();
	CalcPondarateRow pondarateAlgo(normalized_categories, this->_controleValue);
	if (withCategory) {
		std::vector<Category>::const_iterator begin_category = normalized_categories.begin();
		std::vector<Category>::const_iterator end_category = normalized_categories.end();

		while (begin_category != end_category) {
			outputFile << (*begin_category).getName() << ";";
			debugFile << begin_category->getName() << "("
					<< begin_category->getWeight() << ")" << ";";
			++begin_category;
		}
		outputFile << "control;" << std::endl;
		debugFile << "control;" << std::endl;
	}

	std::sort(this->_rows.begin(), this->_rows.end(), pondarateAlgo);
	std::vector<Row>::iterator begin_row = this->_rows.begin();
	std::vector<Row>::iterator end_row = this->_rows.end();

	while (begin_row != end_row) {
		std::vector<Node> nodes = begin_row->getNodes();
		std::vector<Node>::iterator begin_node = nodes.begin();
		std::vector<Node>::iterator end_node = nodes.end();
		while (begin_node != end_node) {
			outputFile << begin_node->getValue() << ";";
			debugFile << begin_node->getValue() << "("
					<< begin_node->getWeight() << ");";
			++begin_node;
		}
		pondarateAlgo.operator ()(*begin_row);
		float getTotal = pondarateAlgo.getTotal();
		if (getTotal > this->_controleValue)
			outputFile << "yes" << ";";
		else
			outputFile << "no" << ";";
		debugFile <<  getTotal << ";";
		outputFile << std::endl;
		debugFile << std::endl;
		++begin_row;
	}

}

CsvGenerator CsvGenerator::defaultCsv() {

	CsvGenerator csv;

	csv.addCategory(CategoryFactory::nbControler());
	csv.addCategory(CategoryFactory::trainLength());
	csv.addCategory(CategoryFactory::trainClass());
	csv.addCategory(CategoryFactory::trainPop());
	csv.addCategory(CategoryFactory::cops());
	csv.addCategory(CategoryFactory::timeOfDay());
	csv.addCategory(CategoryFactory::weekEnd());
	csv.addCategory(CategoryFactory::hollidays());
	csv.addCategory(CategoryFactory::race());
	csv.addCategory(CategoryFactory::gender());
	csv.addCategory(CategoryFactory::age());
	csv.addCategory(CategoryFactory::delay());
	csv.setControleValue(0.09);
	return csv;

}

void CsvGenerator::generateAndExport(const std::string& filepath,
		int nbRowGenerate, bool withCategory) {
	this->generate(nbRowGenerate);
	this->exportToFile(filepath, withCategory);
}

float CsvGenerator::getMaxWeightCategory() const {
	std::vector<Category>::const_iterator begin = this->_categories.begin();
	std::vector<Category>::const_iterator end = this->_categories.end();
	float max = begin->getWeight();
	while (begin != end) {

		if (max < begin->getWeight())
			max = begin->getWeight();
		++begin;
	}
	return max;
}

const std::vector<Category> CsvGenerator::normalizeCategories() {
	std::vector<Category> normalized_categories = this->_categories;
	std::vector<Category>::iterator begin = normalized_categories.begin();
	std::vector<Category>::iterator end = normalized_categories.end();
	float total = 0;
	while (begin != end) {
		total += begin->getWeight();
		++begin;
	}
	begin = normalized_categories.begin();
	while (begin != end) {
		float weight_normalized = begin->getWeight() / total;
		begin->setWeight(weight_normalized);
		++begin;
	}
	return normalized_categories;
}

const std::vector<Row>& CsvGenerator::generate(int nbRowGenerate) {
	this->_rows.clear();
	std::vector<Category> categories = this->normalizeCategories();
	for (int y = 0; y < nbRowGenerate; ++y) {
		Row newRow;
		int x = 0;
		std::vector<Category>::iterator current_category = categories.begin();
		while (current_category != categories.end()) {
			Node newNode;
			const std::pair<std::string, float> value =
					current_category->getRandomValue();
			if (current_category->isMaximazed())
				newNode.setParams(value.first, value.second,
						std::pair<int, int>(x, y));
			else
				newNode.setParams(value.first,
						current_category->maxNodeWeight() - value.second,
						std::pair<int, int>(x, y));
			current_category->addNode(newNode);
			newRow.addNode(newNode);
			current_category++;
		}
		this->_rows.push_back(newRow.normalize());
	}
	return this->_rows;
}
bool  CsvGenerator::isControlate(const std::vector<std::string>& values) {
	std::vector<Category> categories = this->normalizeCategories();
	std::vector<Category>::const_iterator begin_categories = categories.begin();
	std::vector<Category>::const_iterator end_categories = categories.end();
	Row	newRow;
	unsigned int 	i = 0;
	while (begin_categories != end_categories && i < values.size())
	{
		std::string name = values[i];
		float weight = begin_categories->findWeightByNameValue(name);
		Node	new_node(name, weight, i, 0);
		newRow.addNode(new_node);
		i++;
		begin_categories++;
	}
	newRow = newRow.normalize();
	CalcPondarateRow pondarateAlgo(categories, this->_controleValue);
	pondarateAlgo.operator()(newRow);
	if ( pondarateAlgo.getTotal() > this->_controleValue)
		return false;
 	return true;
}

void CsvGenerator::addCategory(const Category& category) {
	this->_categories.push_back(category);
}

void	CsvGenerator::setControleValue(float value)
{
	this->_controleValue = value;
}
