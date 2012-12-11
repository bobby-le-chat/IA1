
#include <list>
#include <string>
#include <iterator>

#include <iostream>
#include <iomanip>

#include "IA1_Core.h"
#include "IA1_Parser.h"

namespace IA1
{
	Core::Core(const std::string& refPath)
		: _refPath(refPath)
	{
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
			this->_dataBase.push_back(*map);
			delete map;
		}
		delete parser;
	}
	bool	Core::checkLineValidity(std::map<IA1::argumentOrder, IA1::valueList> line)
	{
		for (std::map<IA1::argumentOrder, IA1::valueList>::iterator it = this->_selectedNodes.begin();
			it != this->_selectedNodes.end();
			it++)
		{
			if (line[(*it).first] != (*it).second)
				return false;
		}
		return true;
	}
	void	Core::updateDataBase()
	{
		for (std::list<std::map<IA1::argumentOrder, IA1::valueList>>::iterator it = this->_dataBase.begin();
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
		for (std::list<std::map<IA1::argumentOrder, IA1::valueList>>::iterator it = this->_dataBase.begin();
			it != this->_dataBase.end();
			it++)
		{
			if (this->checkLineValidity(*it) == true)
				this->updateProba(*it);
		}
	}
	bool	Core::runCore(const std::string& questionLine)
	{
		this->_selectedNodes.insert(std::pair<IA1::argumentOrder, IA1::valueList>(IA1::cops, IA1::yes));
		this->fillDataBase();
		this->updateDataBase();
		this->fillStatistics();
		/*while (this->isTerminalNode() != true)
		{

		}*/

		/*
		while res != false
			set leaf
			apply filter
			clean the table
			clean the objetcs
			look at stats
		*/

			for (std::map<IA1::argumentOrder, IA1::Parameter>::iterator it = this->editParameterList().begin();
			it != --this->getParameterList().end();
			it++
			)
		{
		std::cout << std::setprecision(3) << (*it).second.getArgument() << "(" << this->getStatistics().getYes() << ',' << this->getStatistics().getNo() << ':' << this->editStatistics().getGain((*it).second) << ')' << ':' ;
		for (std::map<IA1::valueList, IA1::Value>::iterator it2 = (*it).second.editValueList().begin();
			it2 != (*it).second.editValueList().end();
			it2++)
		{
			std::cout << " [" << (*it2).second.getparent() << ',' << (*it2).second.getValue() << "](" << (*it2).second.getYes() << ',' << (*it2).second.getNo()
				<< ':' 
				<< (*it2).second.getEntropy() << ')' ;
		}
		std::cout << std::endl;

		}
			return true;
	}
};	