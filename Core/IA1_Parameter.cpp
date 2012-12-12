
#include "IA1_Parameter.h"
#include "IA1_Value.h"
#include "IA1_Core.h"

namespace IA1
{
	Parameter::Parameter()
		: _argument(IA1::nullArgumentOrder), _activation(true)
	{
	}
	Parameter::Parameter(IA1::argumentOrder argument)
		: _argument(argument), _activation(true)
	{
		if (argument == IA1::nbControler)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::twoControllers, Value(IA1::nbControler, IA1::twoControllers)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::fourControllers, Value(IA1::nbControler, IA1::fourControllers)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::sixControllers, Value(IA1::nbControler, IA1::sixControllers)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::eightControllers, Value(IA1::nbControler, IA1::eightControllers)));
		}
		else if (argument == IA1::trainLenght)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::shortTrain, Value(IA1::trainLenght, IA1::shortTrain)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::middleTrain, Value(IA1::trainLenght, IA1::middleTrain)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::longTrain, Value(IA1::trainLenght, IA1::longTrain)));
		}
		else if (argument == IA1::trainClass)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::firstClass, Value(IA1::trainClass, IA1::firstClass)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::secondClass, Value(IA1::trainClass, IA1::secondClass)));
		}
		else if (argument == IA1::trainPop)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::desertOccupation, Value(IA1::trainPop, IA1::desertOccupation)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::lowOccupation, Value(IA1::trainPop, IA1::lowOccupation)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::middleOccupation, Value(IA1::trainPop, IA1::middleOccupation)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::fullOccupation, Value(IA1::trainPop, IA1::fullOccupation)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::crowdedOccupation, Value(IA1::trainPop, IA1::crowdedOccupation)));
		}
		else if (argument == IA1::cops)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::yes, Value(IA1::cops, IA1::yes)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::no, Value(IA1::cops, IA1::no)));
		}
		else if (argument == IA1::timeOfDay)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::slump, Value(IA1::nbControler, IA1::slump)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::prepostRush, Value(IA1::nbControler, IA1::prepostRush)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::rush, Value(IA1::nbControler, IA1::rush)));
		}
		else if (argument == IA1::weekEnd)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::yes, Value(IA1::weekEnd, IA1::yes)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::no, Value(IA1::weekEnd, IA1::no)));
		}
		else if (argument == IA1::hollidays)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::yes, Value(IA1::hollidays, IA1::yes)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::no, Value(IA1::hollidays, IA1::no)));
		}
		else if (argument == IA1::race)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::european, Value(IA1::race, IA1::european)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::african, Value(IA1::race, IA1::african)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::arabic, Value(IA1::race, IA1::arabic)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::asian, Value(IA1::race, IA1::asian)));
		}
		else if (argument == IA1::gender)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::female, Value(IA1::weekEnd, IA1::female)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::male, Value(IA1::weekEnd, IA1::male)));
		}
		else if (argument == IA1::age)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::junior, Value(IA1::age, IA1::junior)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::teenager, Value(IA1::age, IA1::teenager)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::adult, Value(IA1::age, IA1::adult)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::senior, Value(IA1::age, IA1::senior)));
		}
		else if (argument == IA1::delay)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::fewDelay, Value(IA1::delay, IA1::fewDelay)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::someDelay, Value(IA1::delay, IA1::someDelay)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::lotOfDelay, Value(IA1::delay, IA1::lotOfDelay)));
		}
		else if (argument == IA1::control)
		{
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::yes, Value(IA1::control, IA1::yes)));
			this->_valueList.insert(std::pair<IA1::valueList, Value>(IA1::no, Value(IA1::control, IA1::no)));
		}
	}
	/*
	template <>
	void	Parameter::createValueList<IA1::nbControler>()
	{
		this->_valueList[IA1::twoControllers] = new Value(IA1::nbControler, IA1::twoControllers);
		this->_valueList[IA1::fourControllers] = new Value(IA1::nbControler, IA1::fourControllers);
		this->_valueList[IA1::sixControllers] = new Value(IA1::nbControler, IA1::sixControllers);
		this->_valueList[IA1::heightControllers] = new Value(IA1::nbControler, IA1::heightControllers);
	}
	*/
	std::map<IA1::valueList, Value>& Parameter::editValueList()
	{
		return this->_valueList;
	}
	const std::map<IA1::valueList, Value>& Parameter::getValueList() const
	{
		return this->_valueList;
	}
	IA1::argumentOrder	Parameter::getArgument() const
	{
		return this->_argument;
	}
	void	Parameter::setActivation(bool activation)
	{
		this->_activation = activation;
	}
	bool	Parameter::getActivation() const
	{
		return this->_activation;
	}
	void	Parameter::setGain(double gain)
	{
		this->_gain = gain;
	}
	double	Parameter::getGain() const
	{
		return this->_gain;
	}
}