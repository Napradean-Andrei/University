#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Observer.h"
class GradingRepository : public Subject {

private:
	std::vector<Teacher> teachers;
	std::vector<Student> students;
	int mainTeacherPos;
	int freeID;

	void saveStudentsToFile();

	void loadStudents();
	void loadTeachers();

public:
	GradingRepository();

	void addStudent(Student newStudent);

	void addTeacher(Teacher newTeacher);

	void removeStudent(std::string name);

	void gradeStudent(std::string& studentName, double& grade, std::string& teacher);

	std::vector<Teacher> getTeachers();

	std::vector<Student> getStudents();

	Student& getStudent(std::string name);

	int getFreeID();

	Teacher getMainTeacher();

	// Because the student file should be update on app close
	// the destructor of the repository should be the one that
	// calls a function that saved the data to file
	~GradingRepository();
};

