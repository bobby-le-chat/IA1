#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtGui/QMainWindow>
#include "ui_interface.h"

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
};

#endif // INTERFACE_H
