#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test3prep.h"

class test3prep : public QMainWindow
{
	Q_OBJECT

public:
	test3prep(QWidget *parent = Q_NULLPTR);

private:
	Ui::test3prepClass ui;
};
