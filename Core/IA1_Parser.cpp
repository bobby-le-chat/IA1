
#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "IA1_Parser.h"
#include "IA1_Core.h"

namespace IA1
{

	Parser::Parser(const std::string& path)
		: _path(path)
	{
		this->_fd = new std::filebuf();
		this->_fd->open (this->_path, std::ios::in);
		this->_current = new std::istream(this->_fd);
		this->_reference["yes"] = IA1::yes;
		this->_reference["no"] = IA1::no;
		this->_reference["twoControllers"] = IA1::twoControllers;
		this->_reference["fourControllers"] = IA1::fourControllers;
		this->_reference["sixControllers"] = IA1::sixControllers;
		this->_reference["eightControllers"] = IA1::eightControllers;
		this->_reference["shortTrain"] = IA1::shortTrain;
		this->_reference["middleTrain"] = IA1::middleTrain;
		this->_reference["longTrain"] = IA1::longTrain;
		this->_reference["firstClass"] = IA1::firstClass;
		this->_reference["secondClass"] = IA1::secondClass;
		this->_reference["desertOccupation"] = IA1::desertOccupation;
		this->_reference["lowOccupation"] = IA1::lowOccupation;
		this->_reference["middleOccupation"] = IA1::middleOccupation;
		this->_reference["fullOccupation"] = IA1::fullOccupation;
		this->_reference["crowdedOccupation"] = IA1::crowdedOccupation;
		this->_reference["slump"] = IA1::slump;
		this->_reference["prepostRush"] = IA1::prepostRush;
		this->_reference["rush"] = IA1::rush;
		this->_reference["european"] = IA1::european;
		this->_reference["african"] = IA1::african;
		this->_reference["arabic"] = IA1::arabic;
		this->_reference["asian"] = IA1::asian;
		this->_reference["female"] = IA1::female;
		this->_reference["male"] = IA1::male;
		this->_reference["junior"] = IA1::junior;
		this->_reference["teenager"] = IA1::teenager;
		this->_reference["adult"] = IA1::adult;
		this->_reference["senior"] = IA1::senior;
		this->_reference["fewDelay"] = IA1::fewDelay;
		this->_reference["someDelay"] = IA1::someDelay;
		this->_reference["lotOfDelay"] = IA1::lotOfDelay;
	}
	Parser::~Parser()
	{
		this->_fd->close();
		delete this->_fd;
		delete this->_current;
	}
	IA1::valueList Parser::convertToEnum(const std::string& parameter)
	{
		return this->_reference[parameter];
	}
	std::map<IA1::argumentOrder, IA1::valueList> *Parser::parseLine(std::string& line)
	{
		std::map<IA1::argumentOrder, IA1::valueList> *finalLine = new std::map<IA1::argumentOrder, IA1::valueList>();
		int i = IA1::nbControler;
		for (size_t position = line.find(";"); position != std::string::npos || i <= IA1::delay; position = line.find(";"))
		{
			finalLine->insert(std::pair<IA1::argumentOrder, IA1::valueList>((IA1::argumentOrder)i, this->convertToEnum(line.substr(0, position))));
			line.erase(0,position + 1);
			i++;
		}
		return finalLine;
	}
	std::map<IA1::argumentOrder, IA1::valueList> *Parser::getLine()
	{
		std::string line = "";
		if (std::getline(*(this->_current), line))
			return this->parseLine(line);
		return NULL;
	}
}