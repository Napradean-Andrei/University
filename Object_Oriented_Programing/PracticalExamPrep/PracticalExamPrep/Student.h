#pragma once

#include <string>
#include <istream>
#include <ostream>
class Student {

private:
	int id;
	std::string name;
	int group;
	double grade;
	std::string teacherName;

public:
	Student();
	Student(const int id, const std::string name, const int group, const double grade, const std::string teacher);

	~Student();

	int getID();
	std::string getName();
	int getGroup();
	double getGrade();
	std::string getTeacher();

	void setID(const int newID);
	void setName(const std::string newName);
	void setGroup(const int newGroup);
	void setGrade(const double newGrade);
	void setTeacher(const std::string newTeacher);

	friend std::istream& operator>>(std::istream& inputStream, Student& rightMember);
	friend std::ostream& operator<<(std::ostream& outputStream, Student& rightMember);
};

