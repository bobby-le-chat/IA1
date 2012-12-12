#include "interface.h"
#include "interface.h"
#include <QLabel>

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
}