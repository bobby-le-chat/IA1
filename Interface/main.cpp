#include "interface.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Interface w;
	w.show();
	return a.exec();
}
