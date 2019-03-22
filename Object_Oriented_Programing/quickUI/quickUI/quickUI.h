#pragma once

#include <QtWidgets/QMainWindow>
#include "qlistwidget.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "Controller.h"

class quickUI : public QWidget
{
	Q_OBJECT
		controller ctrl;
	QListWidget* listView;
	QPushButton* sortButton;
	QPushButton* calculateButton;
	QLineEdit* filterText;

public:
	quickUI(QWidget *parent = Q_NULLPTR);

private:
	void initUI();
	void linkSignalsAndSlots();
signals:
	void refreshList();

	private slots:

	void getBill();
	void getSum();
	void repopulateList();

};
