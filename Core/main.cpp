
#include <iostream>
#include <iomanip>
#include <windows.h>

#include "IA1_Core.h"
#include "IA1_Parser.h"
#include "IA1_Answer.h"


int main(int ac, char** av)
{


	// init
	IA1::Parser *arg = new IA1::Parser("C:/Users/Admin/Desktop/projets/Visual/IA1/resultExempleGenerateCsv.csv");
	std::string line = "";
	std::map<IA1::argumentOrder,IA1::valueList> *maListe;
	IA1::Answer res;
	
	/* Timer Ini*/
	LARGE_INTEGER frequency; 
	LARGE_INTEGER start, stop;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	/* Timer Ini - End */

	IA1::Core *core = new IA1::Core("C:/Users/Admin/Desktop/projets/Visual/IA1_svn/trunk/resultExempleGenerateCsv_full_2.csv", 1);

	// Si on veut tester plein de compos en ligne
	while ((maListe = arg->getLine()) != NULL)
	{
		res = core->runCore(*maListe);
		for (int loop = 1; loop < res.getNbLoop(); loop++)
			std::cout << "	Choix: " << res.getChoise(loop) << " Res: " << res.getResult(loop) << " with: " << res.getProba(loop) * 100 << std::endl;
		
		std::cout << "FINALY Choix: " << res.getChoise() << " Res: " << res.getResult() << " with: " << res.getProba() * 100 << " on " << res.getNbLoop() << " loops" << std::endl;
	}
	
	
	/* Timer Res*/
	QueryPerformanceCounter(&stop);
	std::cout << "Time Spend : " << (stop.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart << std::endl;
	/* Timer Res - End */


	delete maListe, core;
	// si on veut test qu'une seule ligne.
	// Note : Si tu utilises cette métode, tu peux instancier le Parser sans parametre dans le constructeur.
	/*IA1::Core *core = new IA1::Core("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv", 1);
	line = "fourControllers;middleTrain;firstClass;middleOccupation;yes;prepostRush;no;yes;european;female;senior;someDelay";
	maListe = arg->parseLine(line);
	std:: cout << "RES = " << (core->runCore(*maListe) ? "YES"  : "NO") << std::endl;

	delete arg, maListe, core;
	*/

	while (1) {}
}