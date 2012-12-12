
#include <list>
#include <string>
#include <iterator>

#include <iostream>
#include <iomanip>

#include "IA1_Core.h"
#include "IA1_Parser.h"

namespace IA1
{
	Core::Core(const std::string& refPath, double probaRequiered)
		: _refPath(refPath), _probaRequiered(probaRequiered)
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
	bool	Core::isTerminalNode(Parameter& parameter, IA1::valueList value)
	{
		std::cout << "Reccord : Yes:" << (parameter.editValueList()[value].getProba(IA1::yes))*100 << " No:" << (parameter.editValueList()[value].getProba(IA1::no))*100 << std::endl;
		if (parameter.editValueList()[value].getProba(IA1::no) >= this->_probaRequiered || parameter.editValueList()[value].getProba(IA1::yes) >= this->_probaRequiered)
			return true;
		else if (parameter.editValueList()[value].getProba(IA1::no) == 0.5)
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
	bool	Core::runCore(const std::map<IA1::argumentOrder, IA1::valueList>& questionLine)
	{
		int nbTurn = 1;
		this->fillDataBase();
		this->updateDataBase();
		this->fillStatistics();
		Parameter *best = &this->getBestNode();
		best->setActivation(false);
		this->_selectedNodes.insert(std::pair<IA1::argumentOrder, IA1::valueList>(best->getArgument(), (*(questionLine.find(best->getArgument()))).second));
		std::cout << "BEST : " << this->_ParameterList[best->getArgument()].getGain() << ", " << best->getArgument() << std::endl;
		while (this->isTerminalNode(*best, (*(questionLine.find(best->getArgument()))).second) != true && this->_dataBase.size() > 0)
		{
			this->cleanStatistics();
			this->updateDataBase();
			this->fillStatistics();
			best = &this->getBestNode();
			best->setActivation(false);
			this->_selectedNodes.insert(std::pair<IA1::argumentOrder, IA1::valueList>(best->getArgument(), (*(questionLine.find(best->getArgument()))).second));
			std::cout << "BEST : " << this->_ParameterList[best->getArgument()].getGain() << ", " << best->getArgument() << std::endl;
			++nbTurn;
		}
		std::cout << "nb Turn : " << nbTurn << std::endl;
		if (best->editValueList()[(*(questionLine.find(best->getArgument()))).second].getProba(IA1::no) >= this->_probaRequiered)
			return false;
		return true;
	}
};	