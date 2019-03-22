#include "Lab1214.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include "DogGUI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GenesGUI w(0);
	w.show();
	return a.exec();
}
