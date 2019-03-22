#pragma once
#include <QtWidgets/qwidget.h>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include "Observer.h"
#include "GradingController.h"

class TeacherWindow : public QWidget, public Observer {
private:

	Q_OBJECT

		void initUI();
	void linkSignalsAndSlots();

	GradingController& ctrl;
	Teacher teacher;

public:

	QListWidget * studentView;
	QPushButton* gradeStudentBtn;

	QLineEdit* gradeField;

	void update();

	TeacherWindow(GradingController& ctrl, Teacher teacher, QWidget *parent = Q_NULLPTR);
	~TeacherWindow();
signals:
	void refreshList();

	public slots:

	void studentGraded();
	void repopulateList();
};

