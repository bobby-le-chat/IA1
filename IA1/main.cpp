
#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <fstream> 
#include <sstream>
#include <istream>

#include "IA1_Core.h"
#include "IA1_Parser.h"
#include "IA1_Answer.h"

#include "CsvGenerator.h"
#include "CategoryFactory.h"


void	generator(CsvGenerator& csv, int lenght, const std::string& prefix = "")
{    
    csv.addCategory(CategoryFactory::nbControler());
    csv.addCategory(CategoryFactory::trainLength());
    csv.addCategory(CategoryFactory::trainClass());
    csv.addCategory(CategoryFactory::trainPop());
    csv.addCategory(CategoryFactory::cops());
    csv.addCategory(CategoryFactory::timeOfDay());
    csv.addCategory(CategoryFactory::weekEnd());
    csv.addCategory(CategoryFactory::hollidays());
    csv.addCategory(CategoryFactory::race());
    csv.addCategory(CategoryFactory::gender());
    csv.addCategory(CategoryFactory::age());
    csv.addCategory(CategoryFactory::delay());
	
	std::ostringstream logFile;
	logFile << prefix << lenght << ".csv";
    csv.generateAndExport(logFile.str(), lenght, false);
}

void	calculate(IA1::Parser* vv, int lenght)
{
	// init
	
	std::ostringstream logFile;
	
	CsvGenerator csv;
	generator(csv, lenght, "Ex/resultCsv");
	CsvGenerator csv2;
	generator(csv2, lenght, "Ref/resultCsv");
	
	
	logFile << "Ex/resultCsv" << lenght << ".csv";
	IA1::Parser *verif = new IA1::Parser(logFile.str());
	logFile.clear();
	logFile << "Ref/resultCsv" << lenght << ".csv";
	IA1::Core *core = new IA1::Core(logFile.str(), 1);
	IA1::Parser *arg = new IA1::Parser(logFile.str());

	std::string line = "";
	std::map<IA1::argumentOrder,IA1::valueList> *maListe;
	std::map<IA1::argumentOrder,IA1::valueList> *maVerif;
	IA1::Answer res;
	std::string resString = "";
	std::vector<std::string> *vector;
	// log
	std::ofstream log;

	logFile.clear();
	logFile << "log/log" << lenght << ".csv";

	log.open(logFile.str(), std::ios::out);
	
	/* Timer Ini*/
	LARGE_INTEGER frequency; 
	LARGE_INTEGER start, stop;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	/* Timer Ini - End */
	
	int total = 0;
	int verified = 0;
	// Si on veut tester plein de compos en ligne
	while ((maListe = arg->getLine()) != NULL)
	{
		maVerif = verif->getLine();
		QueryPerformanceCounter(&start);
		res = core->runCore(*maListe);
		resString = (res.getResult() == IA1::controlled ? "yes" : (res.getResult() == IA1::notControlled ? "no" : "")); 
/*		for (int loop = 1; loop < res.getNbLoop(); loop++)
			std::cout << "	Choix: " << res.getChoise(loop) << " Res: " << res.getResult(loop) << " with: " << res.getProba(loop) * 100 << std::endl;
		std::cout << "FINALY Choix: " << res.getChoise() << " Res: " << resString << " with: " << res.getProba() * 100 << " on " << res.getNbLoop() << " loops" << std::endl;
		vector = arg->unParseLine(*maListe, resString);
		std::cout << "String : ";
		for (std::vector<std::string>::const_iterator it = vector->begin();
			it != vector->end();
			it++)
			std::cout << (*it).data() << ";";
		std::cout << std::endl;*/
		
		QueryPerformanceCounter(&stop);
		//std::cout <<  std::boolalpha << res.getResult() << ' ' << csv.isControlate(*arg->unParseLine(*maListe, resString)) << std::endl;
		bool realAnwser = false;
		if (maVerif->find(IA1::control)->second == IA1::yes)
			realAnwser = true;
		if ((bool)realAnwser == (bool)res.getResult())
			verified++;
		total++;
		//std::cout <<  std::boolalpha <<  res2 << std::endl;
//		log << res2 << ';' <<  (stop.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart << ';' << std::endl;
		delete maListe, vector, res;
	}
	log.close();
	if (total != 0)
		std::cout << "Done : " << lenght << " : "  << (verified / total) * 100 << std::endl;
	else
		std::cout << "Done : " << lenght << " : "  << "bug" << std::endl;
	delete core;

}

int main(int ac, char** av)
{
	IA1::Parser *arg = NULL;
	
	calculate(arg, 5);
	calculate(arg, 10);
	calculate(arg, 20);
	calculate(arg, 50);
	calculate(arg, 100);
	calculate(arg, 250);
	calculate(arg, 500);
	calculate(arg, 1000);
	calculate(arg, 2500);
	calculate(arg, 5000);
	calculate(arg, 10000);
	calculate(arg, 20000);
	calculate(arg, 30000);
	calculate(arg, 40000);
	calculate(arg, 50000);
	calculate(arg, 100000);
	calculate(arg, 150000);
	calculate(arg, 200000);

	delete arg;
	
	/* Timer Res*/
//	QueryPerformanceCounter(&stop);
//	std::cout << "Time Spend : " << (stop.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart << std::endl;
	/* Timer Res - End */


//	delete core;
	// si on veut test qu'une seule ligne.
	// Note : Si tu utilises cette métode, tu peux instancier le Parser sans parametre dans le constructeur.
	/*IA1::Core *core = new IA1::Core("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv", 1);
	line = "fourControllers;middleTrain;firstClass;middleOccupation;yes;prepostRush;no;yes;european;female;senior;someDelay";
	maListe = arg->parseLine(line);
	std:: cout << "RES = " << (core->runCore(*maListe) ? "YES"  : "NO") << std::endl;

	delete arg, maListe, core;
	*/

}