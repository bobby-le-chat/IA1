#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtGui/QMainWindow>
#include <list>
#include <string>
#include <iterator>
#include <map>
#include <list>
#include <iostream>
#include <iomanip>

#include "IA1_Core.h"
#include "IA1_Parser.h"
#include "IA1_Answer.h"
#include "IA1_enum.h"
#include "IA1_Stat.h"
#include "IA1_Parameter.h"
#include "IA1_Parameter.h"
#include "ui_interface.h"
#include "CsvGenerator.h"



class Interface : public QMainWindow
{
	Q_OBJECT

public:
	Interface(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Interface();


public slots:
	void buttonCheckClicked();
	void buttonAcceptClicked();
	void buttonRefuseClicked();

private:
	Ui::InterfaceClass ui;
	IA1::Parser *parser;
	IA1::Core *core;
	CsvGenerator generator;
	std::map<IA1::argumentOrder, IA1::valueList> toParseMap;
	bool	res;
};

#endif // INTERFACE_H
