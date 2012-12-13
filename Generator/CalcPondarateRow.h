/*
 * CalcPondarateRow.h
 *
 *  Created on: 12 déc. 2012
 *      Author: thibremy
 */

#ifndef CALCPONDARATEROW_H_
#define CALCPONDARATEROW_H_

#include <vector>
#include "Category.h"
#include "Row.h"

class CalcPondarateRow {
	const std::vector<Category>& _categories;
	float _refValue;
	float _total;

	float calculate(const Row& row) const;
public:
	CalcPondarateRow(const std::vector<Category>& categories, float refValue = 0.9);
	bool	operator()(const Row& row);
	bool	operator()(const Row& row1, const Row& row2) const;
	bool	isValidate();
	virtual ~CalcPondarateRow();
	float 	getTotal() const;
};

#endif /* CALCPONDARATEROW_H_ */
