
#include <iostream>
#include <cmath>
#include <map>

#include "IA1_enum.h"
#include "IA1_Stat.h"
#include "IA1_Parameter.h"
#include "IA1_Value.h"

namespace IA1
{
	Stat::Stat()
		: _no(0), _yes(0), _changedEntropy(true), _changedProba(true), _probaYes(0), _probaNo(0), _gain(0)
	{}
	
	void Stat::changed()
	{
		this->_changedEntropy = true;
		this->_changedProba = true;
	}
	int Stat::getYes() const
	{ return this->_yes; }
	void Stat::addYes()
	{ this->changed(); this->_yes += 1; }
	void Stat::setYes(int yes)
	{ this->changed(); this->_yes = yes; }

	int Stat::getNo() const
	{ return this->_no; }
	void Stat::addNo()
	{ this->changed(); this->_no += 1; }
	void Stat::setNo(int no)
	{ this->changed(); this->_no = no; }
	
	double Stat::getProba(IA1::valueList order)
	{
		if (this->_changedProba == false)
			return (order == IA1::yes ? this->_probaYes : this->_probaNo );
		if (this->_yes + this->_no <= 0)
			return 0.0;
		this->_probaYes = (double)this->_yes / (double)(this->_yes + this->_no);
		this->_probaNo = (double)this->_no / (double)(this->_yes + this->_no);
		this->_changedProba = false;
		return (order == IA1::yes ? this->_probaYes : this->_probaNo );
	}
	double Stat::myLog(double income, int base)
	{
		if (income == 0)
			return 0.0;
		return std::log(income) / std::log((double)base);
	}
	double Stat::getEntropy()
	{
		if (this->_changedEntropy == false)
			return this->_entropy;
		this->_entropy = 0;
		this->_entropy -= this->getProba() * this->myLog(this->getProba(), 2);
		this->_entropy -= this->getProba(IA1::no) * this->myLog(this->getProba(IA1::no), 2);
		this->_changedEntropy = false;
		return this->_entropy;
	}
	double Stat::getGain(Parameter& parameter)
	{
		double sumValueEntropy = 0.0;
		for (std::map<IA1::valueList, IA1::Value>::iterator it = parameter.editValueList().begin();
			it != parameter.editValueList().end();
			it++)
		{
			double proba = 0.0;
			if ((proba = (double)(this->getNo() + this->getYes())) > 0)
				proba = ((double)((*it).second.getNo() + (*it).second.getYes()) / proba);
			sumValueEntropy += proba * (*it).second.getEntropy();
		}
		this->_gain = this->getEntropy() - sumValueEntropy;
		this->_gain *= 100;
		return this->_gain;
	}
}