#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PracticalExamPrep.h"

class PracticalExamPrep : public QMainWindow
{
	Q_OBJECT

public:
	PracticalExamPrep(QWidget *parent = Q_NULLPTR);

private:
	Ui::PracticalExamPrepClass ui;
};
