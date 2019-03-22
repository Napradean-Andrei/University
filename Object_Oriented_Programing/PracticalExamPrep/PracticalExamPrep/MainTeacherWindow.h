#pragma once
#include <QtWidgets/qwidget.h>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include "Observer.h"
#include "GradingController.h"


class MainTeacherWindow : public QWidget, public Observer {
private:

	Q_OBJECT

		GradingController& ctrl;
	Teacher mainTeacher;


	void initUI();
	void linkSignalsAndSlots();

public:

	QListWidget * studentView;
	QPushButton* addStudentBtn;
	QPushButton* removeStudentBtn;

	QLineEdit* nameField;
	QLineEdit* groupField;

	void update();

	MainTeacherWindow(GradingController& ctrl, Teacher mainTeacher, QWidget *parent = Q_NULLPTR);
	~MainTeacherWindow();

signals:
	void refresh();

	public slots:

	void repopulateList();
	void studentAdded();
	void studentRemoved();


};

