#ifndef __IA1_PARSER_H__
# define __IA1_PARSER_H__

#include <string>
#include <map>

#include "IA1_enum.h"
#include "IA1_Parameter.h"

namespace IA1
{
	class Parser
	{
	private:
		std::string _path;
		std::map<const std::string, IA1::valueList> _reference;
		std::istream*	_current;
		std::filebuf*	_fd;

	public:
		Parser(const std::string& path);
		~Parser();
		IA1::valueList convertToEnum(const std::string& parameter);
		std::map<IA1::argumentOrder, IA1::valueList> *parseLine(std::string& line);
		std::map<IA1::argumentOrder, IA1::valueList> *getLine();
	};
}

#endif /* __IA1_PARSER_H__ */