#include "quickUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	quickUI w;
	w.show();
	return a.exec();
}
