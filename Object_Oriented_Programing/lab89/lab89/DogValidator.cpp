#include "DogValidator1.h"

using namespace std;

DogException::DogException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const Dog & s)
{
	vector<string> errors;
	if (s.getAge() <0)
		errors.push_back("The age must be greater than 0!\n");
	if (s.getWeigth() <0)
		errors.push_back("The weigth must be greater than 0!\n");

	if (errors.size() > 0)
		throw DogException(errors);
}
