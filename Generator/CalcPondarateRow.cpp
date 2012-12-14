/*
 * CalcPondarateRow.cpp
 *
 *  Created on: 12 déc. 2012
 *      Author: thibremy
 */
#include <iostream>
#include "CalcPondarateRow.h"

CalcPondarateRow::CalcPondarateRow(const std::vector<Category>& categories, float refValue)
	: _categories(categories), _refValue(refValue), _total(0)
{

}

CalcPondarateRow::~CalcPondarateRow() {

}

float CalcPondarateRow::calculate(const Row& row) const
{
	float total = 0;
	for (unsigned int i = 0; i < this->_categories.size(); ++i)
	{
		total += this->_categories.at(i).getWeight() * row.getNode(i).getWeight();
	}
	return total;
}

bool	CalcPondarateRow::operator()(const Row& row, const Row& row2) const
{
	return this->calculate(row) > this->calculate(row2);
}

bool CalcPondarateRow::operator()(const Row& row)
{
	this->_total = this->calculate(row);
	return this->_total > this->_refValue;
}

float	CalcPondarateRow::getTotal() const
{
	return this->_total;
}


