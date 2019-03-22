#include "PracticalExamPrep.h"
#include <QtWidgets/QApplication>
#include "MainTeacherWindow.h"
#include "TeacherWindow.h"
#include "GradingController.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GradingController ctrl;
	std::vector<Teacher> temp = ctrl.getTeachers();

	for (int i = 0; i < temp.size(); ++i) {
		TeacherWindow* normalTest = new TeacherWindow(ctrl, temp[i], 0);
		normalTest->show();
	}


	ctrl.getMainTeacher();
	MainTeacherWindow mainTest(ctrl, ctrl.getMainTeacher(), 0);

	//PracticalExamPrep w;
	//w.show();
	return a.exec();
}
