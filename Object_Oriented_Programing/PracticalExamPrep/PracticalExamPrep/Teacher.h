#pragma once
#include <string>
#include <vector>
class Teacher {

private:
	std::string name;
	std::vector<int> groups;

public:
	Teacher();
	Teacher(const std::string name, const std::vector<int> groups);

	~Teacher();

	std::string getName();
	std::vector<int> getGroups();

	void setName(std::string newName);
	void setGroups(std::vector<int> newGroups);

	bool hasGroup(int group);

	friend std::istream& operator>>(std::istream& inputStream, Teacher& rightMember);
	friend std::ostream& operator<<(std::ostream& outputStream, Teacher& rightMember);

};



