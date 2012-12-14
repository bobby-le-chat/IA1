/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created: Fri 14. Dec 12:03:36 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceClass
{
public:
    QWidget *centralWidget;
    QLabel *labelNbControleur;
    QLabel *labelTailleTrain;
    QLabel *labelClasse;
    QLabel *labelPopulation;
    QLabel *labelPolice;
    QLabel *labelPeriode;
    QLabel *labelWeekEnd;
    QLabel *labelVacances;
    QLabel *labelOrigine;
    QLabel *labelGenre;
    QLabel *labelAge;
    QLabel *labelRetard;
    QComboBox *comboBoxNbControleur;
    QComboBox *comboBoxTailleTrain;
    QComboBox *comboBoxClasse;
    QComboBox *comboBoxPopulation;
    QComboBox *comboBoxPolice;
    QComboBox *comboBoxPeriode;
    QComboBox *comboBoxWeekEnd;
    QComboBox *comboBoxVacance;
    QComboBox *comboBoxOrigine;
    QComboBox *comboBoxGenre;
    QComboBox *comboBoxAge;
    QComboBox *comboBoxRetard;
    QLabel *labelCheck;
    QPushButton *buttonCheck;
    QPushButton *buttonAccept;
    QPushButton *buttonRefuse;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfaceClass)
    {
        if (InterfaceClass->objectName().isEmpty())
            InterfaceClass->setObjectName(QString::fromUtf8("InterfaceClass"));
        InterfaceClass->resize(361, 310);
        centralWidget = new QWidget(InterfaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelNbControleur = new QLabel(centralWidget);
        labelNbControleur->setObjectName(QString::fromUtf8("labelNbControleur"));
        labelNbControleur->setGeometry(QRect(10, 0, 111, 16));
        labelTailleTrain = new QLabel(centralWidget);
        labelTailleTrain->setObjectName(QString::fromUtf8("labelTailleTrain"));
        labelTailleTrain->setGeometry(QRect(10, 30, 111, 16));
        labelClasse = new QLabel(centralWidget);
        labelClasse->setObjectName(QString::fromUtf8("labelClasse"));
        labelClasse->setGeometry(QRect(10, 60, 111, 16));
        labelPopulation = new QLabel(centralWidget);
        labelPopulation->setObjectName(QString::fromUtf8("labelPopulation"));
        labelPopulation->setGeometry(QRect(10, 90, 111, 16));
        labelPolice = new QLabel(centralWidget);
        labelPolice->setObjectName(QString::fromUtf8("labelPolice"));
        labelPolice->setGeometry(QRect(10, 120, 111, 16));
        labelPeriode = new QLabel(centralWidget);
        labelPeriode->setObjectName(QString::fromUtf8("labelPeriode"));
        labelPeriode->setGeometry(QRect(10, 150, 111, 16));
        labelWeekEnd = new QLabel(centralWidget);
        labelWeekEnd->setObjectName(QString::fromUtf8("labelWeekEnd"));
        labelWeekEnd->setGeometry(QRect(220, 0, 51, 16));
        labelVacances = new QLabel(centralWidget);
        labelVacances->setObjectName(QString::fromUtf8("labelVacances"));
        labelVacances->setGeometry(QRect(220, 30, 46, 13));
        labelOrigine = new QLabel(centralWidget);
        labelOrigine->setObjectName(QString::fromUtf8("labelOrigine"));
        labelOrigine->setGeometry(QRect(220, 60, 46, 13));
        labelGenre = new QLabel(centralWidget);
        labelGenre->setObjectName(QString::fromUtf8("labelGenre"));
        labelGenre->setGeometry(QRect(220, 90, 46, 13));
        labelAge = new QLabel(centralWidget);
        labelAge->setObjectName(QString::fromUtf8("labelAge"));
        labelAge->setGeometry(QRect(220, 120, 46, 13));
        labelRetard = new QLabel(centralWidget);
        labelRetard->setObjectName(QString::fromUtf8("labelRetard"));
        labelRetard->setGeometry(QRect(220, 150, 46, 13));
        comboBoxNbControleur = new QComboBox(centralWidget);
        comboBoxNbControleur->setObjectName(QString::fromUtf8("comboBoxNbControleur"));
        comboBoxNbControleur->setGeometry(QRect(130, 0, 69, 22));
        comboBoxTailleTrain = new QComboBox(centralWidget);
        comboBoxTailleTrain->setObjectName(QString::fromUtf8("comboBoxTailleTrain"));
        comboBoxTailleTrain->setGeometry(QRect(130, 30, 69, 22));
        comboBoxClasse = new QComboBox(centralWidget);
        comboBoxClasse->setObjectName(QString::fromUtf8("comboBoxClasse"));
        comboBoxClasse->setGeometry(QRect(130, 60, 69, 22));
        comboBoxPopulation = new QComboBox(centralWidget);
        comboBoxPopulation->setObjectName(QString::fromUtf8("comboBoxPopulation"));
        comboBoxPopulation->setGeometry(QRect(130, 90, 69, 22));
        comboBoxPolice = new QComboBox(centralWidget);
        comboBoxPolice->setObjectName(QString::fromUtf8("comboBoxPolice"));
        comboBoxPolice->setGeometry(QRect(130, 120, 69, 22));
        comboBoxPeriode = new QComboBox(centralWidget);
        comboBoxPeriode->setObjectName(QString::fromUtf8("comboBoxPeriode"));
        comboBoxPeriode->setGeometry(QRect(130, 150, 69, 22));
        comboBoxWeekEnd = new QComboBox(centralWidget);
        comboBoxWeekEnd->setObjectName(QString::fromUtf8("comboBoxWeekEnd"));
        comboBoxWeekEnd->setGeometry(QRect(280, 0, 69, 22));
        comboBoxVacance = new QComboBox(centralWidget);
        comboBoxVacance->setObjectName(QString::fromUtf8("comboBoxVacance"));
        comboBoxVacance->setGeometry(QRect(280, 30, 69, 22));
        comboBoxOrigine = new QComboBox(centralWidget);
        comboBoxOrigine->setObjectName(QString::fromUtf8("comboBoxOrigine"));
        comboBoxOrigine->setGeometry(QRect(280, 60, 69, 22));
        comboBoxGenre = new QComboBox(centralWidget);
        comboBoxGenre->setObjectName(QString::fromUtf8("comboBoxGenre"));
        comboBoxGenre->setGeometry(QRect(280, 90, 69, 22));
        comboBoxAge = new QComboBox(centralWidget);
        comboBoxAge->setObjectName(QString::fromUtf8("comboBoxAge"));
        comboBoxAge->setGeometry(QRect(280, 120, 69, 22));
        comboBoxRetard = new QComboBox(centralWidget);
        comboBoxRetard->setObjectName(QString::fromUtf8("comboBoxRetard"));
        comboBoxRetard->setGeometry(QRect(280, 150, 69, 22));
        labelCheck = new QLabel(centralWidget);
        labelCheck->setObjectName(QString::fromUtf8("labelCheck"));
        labelCheck->setGeometry(QRect(20, 210, 321, 20));
        buttonCheck = new QPushButton(centralWidget);
        buttonCheck->setObjectName(QString::fromUtf8("buttonCheck"));
        buttonCheck->setGeometry(QRect(20, 180, 321, 23));
        buttonAccept = new QPushButton(centralWidget);
        buttonAccept->setObjectName(QString::fromUtf8("buttonAccept"));
        buttonAccept->setGeometry(QRect(20, 230, 101, 23));
        buttonRefuse = new QPushButton(centralWidget);
        buttonRefuse->setObjectName(QString::fromUtf8("buttonRefuse"));
        buttonRefuse->setGeometry(QRect(234, 230, 101, 23));
        InterfaceClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfaceClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 361, 21));
        InterfaceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterfaceClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InterfaceClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterfaceClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InterfaceClass->setStatusBar(statusBar);

        retranslateUi(InterfaceClass);

        QMetaObject::connectSlotsByName(InterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceClass)
    {
        InterfaceClass->setWindowTitle(QApplication::translate("InterfaceClass", "Interface", 0, QApplication::UnicodeUTF8));
        labelNbControleur->setText(QApplication::translate("InterfaceClass", "Nombre de contr\303\264leurs", 0, QApplication::UnicodeUTF8));
        labelTailleTrain->setText(QApplication::translate("InterfaceClass", "Taille du Train", 0, QApplication::UnicodeUTF8));
        labelClasse->setText(QApplication::translate("InterfaceClass", "Classe", 0, QApplication::UnicodeUTF8));
        labelPopulation->setText(QApplication::translate("InterfaceClass", "Population", 0, QApplication::UnicodeUTF8));
        labelPolice->setText(QApplication::translate("InterfaceClass", "Pr\303\251sence de la Police", 0, QApplication::UnicodeUTF8));
        labelPeriode->setText(QApplication::translate("InterfaceClass", "P\303\251riode de la journ\303\251e", 0, QApplication::UnicodeUTF8));
        labelWeekEnd->setText(QApplication::translate("InterfaceClass", "Week End", 0, QApplication::UnicodeUTF8));
        labelVacances->setText(QApplication::translate("InterfaceClass", "Vacances", 0, QApplication::UnicodeUTF8));
        labelOrigine->setText(QApplication::translate("InterfaceClass", "Origine", 0, QApplication::UnicodeUTF8));
        labelGenre->setText(QApplication::translate("InterfaceClass", "Genre", 0, QApplication::UnicodeUTF8));
        labelAge->setText(QApplication::translate("InterfaceClass", "Age", 0, QApplication::UnicodeUTF8));
        labelRetard->setText(QApplication::translate("InterfaceClass", "Retard", 0, QApplication::UnicodeUTF8));
        comboBoxNbControleur->clear();
        comboBoxNbControleur->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "8+", 0, QApplication::UnicodeUTF8)
        );
        comboBoxTailleTrain->clear();
        comboBoxTailleTrain->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Court", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Moyen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Long", 0, QApplication::UnicodeUTF8)
        );
        comboBoxClasse->clear();
        comboBoxClasse->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "1\303\250re", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "2\303\251me", 0, QApplication::UnicodeUTF8)
        );
        comboBoxPopulation->clear();
        comboBoxPopulation->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "D\303\251sert", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Faible", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Moyen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Rempli", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Bond\303\251", 0, QApplication::UnicodeUTF8)
        );
        comboBoxPolice->clear();
        comboBoxPolice->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Oui", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Non", 0, QApplication::UnicodeUTF8)
        );
        comboBoxPeriode->clear();
        comboBoxPeriode->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Creuse", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Pr\303\251/Post Rush", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Rush", 0, QApplication::UnicodeUTF8)
        );
        comboBoxWeekEnd->clear();
        comboBoxWeekEnd->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Oui", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Non", 0, QApplication::UnicodeUTF8)
        );
        comboBoxVacance->clear();
        comboBoxVacance->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Oui", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Non", 0, QApplication::UnicodeUTF8)
        );
        comboBoxOrigine->clear();
        comboBoxOrigine->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Europ\303\251enne", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Africaine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Arabe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Asiatique", 0, QApplication::UnicodeUTF8)
        );
        comboBoxGenre->clear();
        comboBoxGenre->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Homme", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Femme", 0, QApplication::UnicodeUTF8)
        );
        comboBoxAge->clear();
        comboBoxAge->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "Enfant", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Djeunz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Adulte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "Vieux", 0, QApplication::UnicodeUTF8)
        );
        comboBoxRetard->clear();
        comboBoxRetard->insertItems(0, QStringList()
         << QApplication::translate("InterfaceClass", "0 \303\240 5 min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "5 \303\240 15 min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterfaceClass", "15 min et +", 0, QApplication::UnicodeUTF8)
        );
        labelCheck->setText(QApplication::translate("InterfaceClass", "Peut \303\252tre...", 0, QApplication::UnicodeUTF8));
        buttonCheck->setText(QApplication::translate("InterfaceClass", "Dois je prendre le train ?", 0, QApplication::UnicodeUTF8));
        buttonAccept->setText(QApplication::translate("InterfaceClass", "Evidemment", 0, QApplication::UnicodeUTF8));
        buttonRefuse->setText(QApplication::translate("InterfaceClass", "Absolument pas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InterfaceClass: public Ui_InterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
