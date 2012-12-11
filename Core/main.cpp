
#include <iostream>
#include <iomanip>
#include "IA1_Core.h"
#include "IA1_Parser.h"


int main(int ac, char** av)
{
	IA1::Core *core = new IA1::Core("C:/Users/Admin/Desktop/projets/Visual/IA1/resultExempleGenerateCsv.csv");
	
	core->runCore("");
	/*
	IA1::Core core;
	std::map<IA1::argumentOrder, IA1::valueList> *map;
	while ((map = parser->getLine()) != NULL)
	{
		core.calculateProba(*map);
		delete map;
	}
	delete parser;
	for (std::map<IA1::argumentOrder, IA1::Parameter>::iterator it = core.editParameterList().begin();
			it != core.getParameterList().end();
			it++
			)
	{
		std::cout << std::setprecision(3) << (*it).second.getArgument() << "(" << core.getStatistics().getYes() << ',' << core.getStatistics().getNo() << ':' << core.editStatistics().getGain((*it).second) << ')' << ':' ;
		for (std::map<IA1::valueList, IA1::Value>::iterator it2 = (*it).second.editValueList().begin();
			it2 != (*it).second.editValueList().end();
			it2++)
		{
			std::cout << " [" << (*it2).second.getparent() << ',' << (*it2).second.getValue() << "](" << (*it2).second.getYes() << ',' << (*it2).second.getNo()
				<< ':' 
				<< (*it2).second.getEntropy() << ')' ;
		}
		std::cout << std::endl;
	}*/
	while (1) {}
}