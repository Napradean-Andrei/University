#pragma once
#include "GradingRepository.h"
class GradingController {
private:
	GradingRepository repo;

public:
	GradingController();
	~GradingController();

	void addStudent(const std::string& name, const int& group);

	void removeStudent(const std::string& name);

	std::string gradeStudent(std::string& name, double& grade, std::string teacherName);

	std::vector<Student> getAllStudents();

	std::vector<Student> getStudentsFor(Teacher teacher);

	std::vector<Teacher> getTeachers();

	void addObserver(Observer* newObserver);

	Teacher getMainTeacher();
};


