
#include <iostream>
#include <iomanip>
#include "IA1_Core.h"
#include "IA1_Parser.h"


int main(int ac, char** av)
{


	// init
	IA1::Parser *arg = new IA1::Parser("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv");
	std::string line = "";
	std::map<IA1::argumentOrder,IA1::valueList> *maListe;
/*
	// Si on veut tester plein de compos en ligne
	while ((maListe = arg->getLine()) != NULL)
	{
		IA1::Core *core = new IA1::Core("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv", 1);
		std:: cout << "RES = " << (core->runCore(*maListe) ? "YES"  : "NO") << std::endl;
		delete maListe, core;
	}
	*/
	// si on veut test qu'une seule ligne.
	// Note : Si tu utilises cette métode, tu peux instancier le Parser sans parametre dans le constructeur.
	IA1::Core *core = new IA1::Core("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv", 1);
	line = "fourControllers;middleTrain;firstClass;middleOccupation;yes;prepostRush;no;yes;european;female;senior;someDelay";
	maListe = arg->parseLine(line);
	std:: cout << "RES = " << (core->runCore(*maListe) ? "YES"  : "NO") << std::endl;

	delete arg, maListe, core;


	while (1) {}
}