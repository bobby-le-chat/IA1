#ifndef __IA1_PARSER_H__
# define __IA1_PARSER_H__

#include <string>
#include <map>
#include <vector>

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
	protected:
		IA1::valueList convertToEnum(const std::string& parameter);

	public:
		Parser(const std::string& path = "");
		~Parser();
		std::map<IA1::argumentOrder, IA1::valueList> *parseLine(std::string refLine);
		std::map<IA1::argumentOrder, IA1::valueList> *getLine();

		std::vector<std::string>* unParseLine(const std::map<IA1::argumentOrder, IA1::valueList>& ref, const std::string& res);
		std::vector<std::string>* parseLineToVector(std::string res);

	};
}

#endif /* __IA1_PARSER_H__ */