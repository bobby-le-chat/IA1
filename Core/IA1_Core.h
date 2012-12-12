#ifndef __IA1_CORE_H__
# define __IA1_CORE_H__

#include <map>
#include <list>

#include "IA1_enum.h"
#include "IA1_Parameter.h"
#include "IA1_Stat.h"

namespace IA1
{
	
	class Core
	{
	 private:
		 Stat _statistics;
		 std::map<IA1::argumentOrder, Parameter>  _ParameterList;
		 std::string	_refPath;
		 std::list<std::map<IA1::argumentOrder, IA1::valueList>> _dataBase;
		 std::map<IA1::argumentOrder, IA1::valueList> _selectedNodes;
		 double	_probaRequiered;
	 protected:
		 const Stat& getStatistics() const;
		 Stat& editStatistics();
		 const std::map<IA1::argumentOrder, Parameter>& getParameterList() const;
		 std::map<IA1::argumentOrder, Parameter>& editParameterList();
		 double calculateGain(const Parameter& arg);
		 void updateProba(std::map<IA1::argumentOrder, IA1::valueList>& currentLine);
		 void cleanStatistics();
		 void fillStatistics();

		 bool isTerminalNode(Parameter& parameter, IA1::valueList value);
		 Parameter&	getBestNode();
		 
		 void fillDataBase();
		 bool checkLineValidity(std::map<IA1::argumentOrder, IA1::valueList> line);
		 void updateDataBase();
	public:
		 Core(const std::string& refPath, double probaRequiered = 0.8);
		 bool runCore(const std::map<IA1::argumentOrder, IA1::valueList>& questionLine);
	};

}


#endif /* __IA1_CORE */