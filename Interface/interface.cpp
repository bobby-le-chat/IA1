
#include "interface.h"

Interface::Interface(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect ( ui.buttonCheck, SIGNAL( clicked() ), this, SLOT( buttonCheckClicked() ) );
	connect ( ui.buttonAccept, SIGNAL( clicked() ), this, SLOT( buttonAcceptClicked() ) );
	connect ( ui.buttonRefuse, SIGNAL( clicked() ), this, SLOT( buttonRefuseClicked() ) );
	ui.buttonAccept->setDisabled(true);
	ui.buttonRefuse->setDisabled(true);
}

Interface::~Interface()
{

}



void Interface::buttonCheckClicked() // defined in .h under public/private slots:
{
	ui.labelCheck->setText("CheckButton");
	ui.comboBoxNbControleur->setDisabled(true);
	ui.comboBoxTailleTrain->setDisabled(true);
    ui.comboBoxClasse->setDisabled(true);
    ui.comboBoxPopulation->setDisabled(true);
    ui.comboBoxPolice->setDisabled(true);
    ui.comboBoxPeriode->setDisabled(true);
    ui.comboBoxWeekEnd->setDisabled(true);
    ui.comboBoxVacance->setDisabled(true);
    ui.comboBoxOrigine->setDisabled(true);
    ui.comboBoxGenre->setDisabled(true);
    ui.comboBoxAge->setDisabled(true);
    ui.comboBoxRetard->setDisabled(true);
	ui.buttonCheck->setDisabled(true);
	ui.buttonAccept->setDisabled(false);
	ui.buttonRefuse->setDisabled(false);

	std::string toParse = "";
	std::map<IA1::argumentOrder, IA1::valueList> toParseMap;
	switch (ui.comboBoxNbControleur->currentIndex())
	{
		case 0 : {toParseMap[IA1::nbControler] = IA1::twoControllers; break; }
		case 1 : {toParseMap[IA1::nbControler] = IA1::fourControllers; break; }
		case 2 : {toParseMap[IA1::nbControler] = IA1::sixControllers; break; }
		case 3 : {toParseMap[IA1::nbControler] = IA1::eightControllers; break; }
		default : break;
	};

	switch (ui.comboBoxTailleTrain->currentIndex())
	{
		case 0 : {toParseMap[IA1::trainLenght] = IA1::shortTrain; break; }
		case 1 : {toParseMap[IA1::trainLenght] = IA1::middleTrain; break; }
		case 2 : {toParseMap[IA1::trainLenght] = IA1::longTrain; break; }

		default : break;
	};

	switch (ui.comboBoxClasse->currentIndex())
	{
		case 0 : {toParseMap[IA1::trainClass] = IA1::firstClass; break; }
		case 1 : {toParseMap[IA1::trainClass] = IA1::secondClass; break; }
		default : break;
	};

	switch (ui.comboBoxPopulation->currentIndex())
	{
		case 0 : {toParseMap[IA1::trainPop] = IA1::desertOccupation; break; }
		case 1 : {toParseMap[IA1::trainPop] = IA1::lowOccupation; break; }
		case 2 : {toParseMap[IA1::trainPop] = IA1::middleOccupation; break; }
		case 3 : {toParseMap[IA1::trainPop] = IA1::fullOccupation; break; }
		case 4 : {toParseMap[IA1::trainPop] = IA1::crowdedOccupation; break; }
		default : break;
	};

	switch (ui.comboBoxPolice->currentIndex())
	{
		case 0 : {toParseMap[IA1::cops] = IA1::yes; break; }
		case 1 : {toParseMap[IA1::cops] = IA1::no; break; }
		default : break;
	};

	switch (ui.comboBoxPeriode->currentIndex())
	{
		case 0 : {toParseMap[IA1::timeOfDay] = IA1::slump; break; }
		case 1 : {toParseMap[IA1::timeOfDay] = IA1::prepostRush; break; }
		case 2 : {toParseMap[IA1::timeOfDay] = IA1::rush; break; }
		default : break;
	};

	switch (ui.comboBoxWeekEnd->currentIndex())
	{
		case 0 : {toParseMap[IA1::weekEnd] = IA1::yes; break; }
		case 1 : {toParseMap[IA1::weekEnd] = IA1::no; break; }

		default : break;
	};

	switch (ui.comboBoxVacance->currentIndex())
	{
		case 0 : {toParseMap[IA1::holidays] = IA1::yes; break; }
		case 1 : {toParseMap[IA1::holidays] = IA1::no; break; }
		default : break;
	};

	switch (ui.comboBoxOrigine->currentIndex())
	{
		case 0 : {toParseMap[IA1::race] = IA1::european; break; }
		case 1 : {toParseMap[IA1::race] = IA1::african; break; }
		case 2 : {toParseMap[IA1::race] = IA1::arabic; break; }
		case 3 : {toParseMap[IA1::race] = IA1::asian; break; }
		default : break;
	};

	switch (ui.comboBoxGenre->currentIndex())
	{
		case 0 : {toParseMap[IA1::gender] = IA1::female; break; }
		case 1 : {toParseMap[IA1::gender] = IA1::male; break; }

		default : break;
	};

	switch (ui.comboBoxAge->currentIndex())
	{
		case 0 : {toParseMap[IA1::age] = IA1::junior; break; }
		case 1 : {toParseMap[IA1::age] = IA1::teenager; break; }
		case 2 : {toParseMap[IA1::age] = IA1::adult; break; }
		case 3 : {toParseMap[IA1::age] = IA1::senior; break; }
		default : break;
	};

	switch (ui.comboBoxRetard->currentIndex())
	{
		case 0 : {toParseMap[IA1::delay] = IA1::fewDelay; break; }
		case 1 : {toParseMap[IA1::delay] = IA1::someDelay; break; }
		case 2 : {toParseMap[IA1::delay] = IA1::lotOfDelay; break; }
		default : break;
	};

	
	////// init
	////this->arg = new IA1::Parser("C:/Users/Admin/Desktop/projets/Visual/IA1/resultExempleGenerateCsv.csv");
	////std::string line = "";
	////std::map<IA1::argumentOrder,IA1::valueList> *maListe;
	////IA1::Answer res;
	////std::string resString = "";
	////std::vector<std::string> *vector;

	/////* Timer Ini*/
	////LARGE_INTEGER frequency; 
	////LARGE_INTEGER start, stop;
	////QueryPerformanceFrequency(&frequency);
	////QueryPerformanceCounter(&start);
	/////* Timer Ini - End */

	////core = new IA1::Core("C:/Users/Admin/Desktop/projets/Visual/IA1/resultExempleGenerateCsv.csv", 1);

	////// Si on veut tester plein de compos en ligne
	////while ((maListe = arg->getLine()) != NULL)
	////{
	////	res = core->runCore(*maListe);
	////	for (int loop = 1; loop < res.getNbLoop(); loop++)
	////		std::cout << "	Choix: " << res.getChoise(loop) << " Res: " << res.getResult(loop) << " with: " << res.getProba(loop) * 100 << std::endl;
	////	resString = (res.getResult() == IA1::controlled ? "yes" : (res.getResult() == IA1::notControlled ? "no" : "")); 
	////	std::cout << "FINALY Choix: " << res.getChoise() << " Res: " << resString << " with: " << res.getProba() * 100 << " on " << res.getNbLoop() << " loops" << std::endl;
	////	vector = arg->unParseLine(*maListe, resString);
	////	std::cout << "String : ";
	////	for (std::vector<std::string>::const_iterator it = vector->begin();
	////		it != vector->end();
	////		it++)
	////		std::cout << (*it).data() << ";";
	////	std::cout << std::endl;
	////	delete maListe, vector;
	////}
	////
	////
	/////* Timer Res*/
	////QueryPerformanceCounter(&stop);
	////std::cout << "Time Spend : " << (stop.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart << std::endl;
	/////* Timer Res - End */


	////
	////// si on veut test qu'une seule ligne.
	////// Note : Si tu utilises cette métode, tu peux instancier le Parser sans parametre dans le constructeur.
	/////*IA1::Core *core = new IA1::Core("C:/Users/Admin/Downloads/resultExempleGenerateCsv.csv", 1);
	////line = "fourControllers;middleTrain;firstClass;middleOccupation;yes;prepostRush;no;yes;european;female;senior;someDelay";
	////maListe = arg->parseLine(line);
	////std:: cout << "RES = " << (core->runCore(*maListe) ? "YES"  : "NO") << std::endl;

	////delete arg, maListe, core;
	////*/

	////while (1) {}



}

void Interface::buttonAcceptClicked() // defined in .h under public/private slots:
{
	ui.labelCheck->setText("AcceptButton");
	ui.comboBoxNbControleur->setDisabled(false);
	ui.comboBoxTailleTrain->setDisabled(false);
    ui.comboBoxClasse->setDisabled(false);
    ui.comboBoxPopulation->setDisabled(false);
    ui.comboBoxPolice->setDisabled(false);
    ui.comboBoxPeriode->setDisabled(false);
    ui.comboBoxWeekEnd->setDisabled(false);
    ui.comboBoxVacance->setDisabled(false);
    ui.comboBoxOrigine->setDisabled(false);
    ui.comboBoxGenre->setDisabled(false);
    ui.comboBoxAge->setDisabled(false);
    ui.comboBoxRetard->setDisabled(false);
	ui.buttonCheck->setDisabled(false);
	ui.buttonAccept->setDisabled(true);
	ui.buttonRefuse->setDisabled(true);

	delete core;
}

void Interface::buttonRefuseClicked() // defined in .h under public/private slots:
{
	ui.labelCheck->setText("RefuseButton");
	ui.comboBoxNbControleur->setDisabled(false);
	ui.comboBoxTailleTrain->setDisabled(false);
    ui.comboBoxClasse->setDisabled(false);
    ui.comboBoxPopulation->setDisabled(false);
    ui.comboBoxPolice->setDisabled(false);
    ui.comboBoxPeriode->setDisabled(false);
    ui.comboBoxWeekEnd->setDisabled(false);
    ui.comboBoxVacance->setDisabled(false);
    ui.comboBoxOrigine->setDisabled(false);
    ui.comboBoxGenre->setDisabled(false);
    ui.comboBoxAge->setDisabled(false);
    ui.comboBoxRetard->setDisabled(false);
	ui.buttonCheck->setDisabled(false);
	ui.buttonAccept->setDisabled(true);
	ui.buttonRefuse->setDisabled(true);

	delete core;
}