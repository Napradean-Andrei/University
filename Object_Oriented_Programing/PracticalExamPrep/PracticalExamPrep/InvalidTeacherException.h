#pragma once
#include <exception>
#include <string>
class InvalidTeacherException : public std::exception {

private:
	std::string message;

public:

	InvalidTeacherException(std::string message);
	virtual const char* what();
};

