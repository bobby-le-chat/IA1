
#include <list>
#include <string>
#include <iterator>

#include <iostream>
#include <iomanip>

#include "IA1_Core.h"
#include "IA1_Parser.h"
#include "IA1_Answer.h"

namespace IA1
{
	Core::Core(const std::string& refPath, double probaRequiered)
		: _refPath(refPath), _probaRequiered(probaRequiered)
	{
		this->fillDataBase();
		for (int i = IA1::nbControler; i <= IA1::control; i++)
		{
			this->_ParameterList.insert(std::pair<IA1::argumentOrder, Parameter>((IA1::argumentOrder)i, Parameter((IA1::argumentOrder)i)));
		}
	}
	const Stat& Core::getStatistics() const
	{
		return this->_statistics;
	}	
	Stat& Core::editStatistics()
	{
		return this->_statistics;
	}
	const std::map<IA1::argumentOrder, Parameter>& Core::getParameterList() const
	{
		return this->_ParameterList;
	}
	std::map<IA1::argumentOrder, Parameter>& Core::editParameterList()
	{
		return this->_ParameterList;
	}
	void	Core::updateProba(std::map<IA1::argumentOrder, IA1::valueList>& currentLine)
	{
		for (std::map<IA1::argumentOrder, IA1::valueList>::const_iterator iterator = currentLine.begin();
			iterator != --(currentLine.end());
			iterator++)
		{
			if (currentLine[IA1::control] == IA1::yes)
			{
				this->_ParameterList[(*iterator).first].editValueList()[(*iterator).second].addYes();
			}
			else if (currentLine[IA1::control] == IA1::no)
			{
				this->_ParameterList[(*iterator).first].editValueList()[(*iterator).second].addNo();
			}
		}
		if (currentLine[IA1::control] == IA1::yes)
			this->_statistics.addYes();
		else if (currentLine[IA1::control] == IA1::no)
			this->_statistics.addNo();
	}

	void	Core::fillDataBase()
	{
		IA1::Parser *parser = new IA1::Parser(this->_refPath);
		std::map<IA1::argumentOrder, IA1::valueList> *map;
		while ((map = parser->getLine()) != NULL)
		{
			this->_fullDataBase.push_back(*map);
			delete map;
		}
		delete parser;
	}
	void	Core::resetDataBase()
	{
		this->_dataBase.clear();
		for (std::list<std::map<IA1::argumentOrder, IA1::valueList>>::iterator it = this->_fullDataBase.begin();
			it != this->_fullDataBase.end();
			it++)
		{
			this->_dataBase.push_back(&(*it));
		}
	}
	bool	Core::checkLineValidity(std::map<IA1::argumentOrder, IA1::valueList> *line)
	{
		for (std::map<IA1::argumentOrder, IA1::valueList>::iterator it = this->_selectedNodes.begin();
			it != this->_selectedNodes.end();
			it++)
		{
			if (line->operator[]((*it).first) != (*it).second)
				return false;
		}
		return true;
	}
	void	Core::updateDataBase()
	{
		for (std::list<std::map<IA1::argumentOrder, IA1::valueList>*>::iterator it = this->_dataBase.begin();
			it != this->_dataBase.end();
			)
		{
			if (this->checkLineValidity(*it) == false)
				this->_dataBase.erase(it++);
			else
				it++;
		}
	}
	void	Core::fillStatistics()
	{
		for (std::list<std::map<IA1::argumentOrder, IA1::valueList>*>::iterator it = this->_dataBase.begin();
			it != this->_dataBase.end();
			it++)
		{
			if (this->checkLineValidity(*it) == true)
				this->updateProba(*(*it));
		}
	}
	bool	Core::isTerminalNode(IA1::Parameter& parameter, IA1::valueList value, IA1::Answer& res)
	{
		double	probaYes = parameter.editValueList()[value].getProba(IA1::yes),
				probaNo = parameter.editValueList()[value].getProba(IA1::no);
		if (probaNo == 0 && probaYes == 0)
		{
			res.increaseLoop(-1);
			return true;
		}
		if (probaNo > probaYes)
			res.addResult(IA1::notControlled, probaNo);
		else if (probaNo < probaYes)
			res.addResult(IA1::controlled, probaYes);
		else if (probaNo == probaYes)
			res.addResult(IA1::fiftyfifty, probaYes);

		if (probaNo >= this->_probaRequiered || probaYes >= this->_probaRequiered)
			return true;
		return false;
	}
	Parameter&	Core::getBestNode()
	{
		IA1::argumentOrder parameterIdentifer = IA1::nullArgumentOrder;
		double best = 0;
		double	temp = 0;
		for (std::map<IA1::argumentOrder, IA1::Parameter>::iterator it = this->editParameterList().begin();
			it != --this->getParameterList().end();
			it++)
		{
			if ((*it).second.getActivation() == true && (temp = this->_statistics.getGain((*it).second)) > best)
			{	

				best = temp;
				this->_ParameterList[(*it).first].setGain(temp);
				parameterIdentifer = (*it).first;
			}
		}
		return this->_ParameterList[parameterIdentifer];
	}
	void	Core::cleanStatistics()
	{
		this->_statistics.clean();
		for (std::map<IA1::argumentOrder, IA1::Parameter>::iterator it = this->editParameterList().begin();
			it != --this->getParameterList().end();
			it++
			)
		{
			for (std::map<IA1::valueList, IA1::Value>::iterator it2 = (*it).second.editValueList().begin();
			it2 != (*it).second.editValueList().end();
			it2++)
			{
				(*it2).second.clean();
			}
		}
	}
	void	Core::resetParameters()
	{
		for (std::map<IA1::argumentOrder, Parameter>::iterator it = this->_ParameterList.begin();
			it != this->_ParameterList.end();
			it++)
		{
			(*it).second.setActivation(true);
		}
	}
	const IA1::Answer&	Core::runCore(const std::map<IA1::argumentOrder, IA1::valueList>& questionLine)
	{
		IA1::Parameter *best = NULL;
		IA1::Answer *res = new IA1::Answer();
		this->resetDataBase();
		this->resetParameters();
		this->_selectedNodes.clear();

		while (best == NULL || (this->_dataBase.size() > 0 && this->isTerminalNode(*best, (*(questionLine.find(best->getArgument()))).second, *res) != true))
		{
			this->cleanStatistics();
			this->updateDataBase();
			this->fillStatistics();
			best = &this->getBestNode();
			best->setActivation(false);
			this->_selectedNodes.insert(std::pair<IA1::argumentOrder, IA1::valueList>(best->getArgument(), (*(questionLine.find(best->getArgument()))).second));
			res->increaseLoop();
			res->addChoise(best->getArgument());
		}
		return *res;
	}
};	