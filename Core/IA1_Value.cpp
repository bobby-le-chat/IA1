
#include <cmath>

#include "IA1_enum.h"
#include "IA1_Value.h"

namespace IA1
{
	Value::Value()
		: _parent(IA1::nullArgumentOrder), _value(IA1::nullValueList), _activation(true)
	{}
	Value::Value(IA1::argumentOrder parent, IA1::valueList value)
		: _parent(parent), _value(value), _activation(true)
	{}

	IA1::valueList Value::getValue() const
	{
		return this->_value;
	}
	IA1::argumentOrder	Value::getparent() const
	{
		return this->_parent;
	}
	void	Value::setActivation(bool activation)
	{
		this->_activation = activation;
	}
	bool	Value::getActivation() const
	{
		return this->_activation;
	}
}
