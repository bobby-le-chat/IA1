
#include "interface.h"
#include "IA1_Answer.h"
#include "CsvGenerator.h"

Interface::Interface(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect ( ui.buttonCheck, SIGNAL( clicked() ), this, SLOT( buttonCheckClicked() ) );
	connect ( ui.buttonAccept, SIGNAL( clicked() ), this, SLOT( buttonAcceptClicked() ) );
	connect ( ui.buttonRefuse, SIGNAL( clicked() ), this, SLOT( buttonRefuseClicked() ) );
	ui.buttonAccept->setDisabled(true);
	ui.buttonRefuse->setDisabled(true);
	this->parser = new IA1::Parser();
	this->core = new IA1::Core("testEchantillon.csv");
	this->generator = CsvGenerator::defaultCsv();
}

Interface::~Interface()
{
	delete core, parser;
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
	IA1::Answer answer;
	
	answer = this->core->runCore(toParseMap);

	if (answer.getNbLoop() <= 0)
		ui.labelCheck->setText("Fichier source introuvable");
	else if (answer.getResult() == true)
		ui.labelCheck->setText("35 euros petit !!!");
	else
		ui.labelCheck->setText("Tranquille mon gars !!!");

}

void Interface::buttonAcceptClicked() // defined in .h under public/private slots:
{
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

	bool confirmer = this->generator.isControlate(*this->parser->unParseLine(this->toParseMap, (this->res == IA1::controlled ? "yes" : (this->res == IA1::notControlled ? "no" : ""))));
	
	if (confirmer)
		ui.labelCheck->setText("Confirmé");
	else
		ui.labelCheck->setText("Trompé");
}

void Interface::buttonRefuseClicked() // defined in .h under public/private slots:
{
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
}