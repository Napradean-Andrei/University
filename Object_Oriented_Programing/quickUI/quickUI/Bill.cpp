#include "Bill.h"
#include <vector>
#include <sstream>

std::string Bill::getName() {
	return this->name;
}

std::string Bill::getCode() {
	return this->code;
}

int Bill::getSum() {
	return this->sum;
}
int Bill::getIsPaid() {
	return this->isPaid;
}

void Bill::setName(std::string name) {
	this->name = name;
}

void Bill::setCode(std::string code) {
	this->code = code;
}
void Bill::setSum(int sum) {
	this->sum = sum;
}
void Bill::setIsPaid(int isPaid) {
	this->isPaid = isPaid;
}

Bill::Bill() {
}

Bill::Bill(std::string name, std::string code, int sum,int isPaid) {
	this->name = name;
	this->code = code;
	this->sum = sum;
	this->isPaid= isPaid;
}

Bill::~Bill() {
}

std::vector<std::string> split(std::string data, char delimiter) {
	std::vector<std::string> splitString;
	std::stringstream strStream(data);
	std::string token;
	while (getline(strStream, token, delimiter))
		splitString.push_back(token);
	return splitString;
}



std::istream& operator>>(std::istream & inputStream, Bill & rightMember) {

	std::string data;

	getline(inputStream, data);

	std::vector<std::string> dataFields = split(data, ';');

	if (dataFields.size() == 4) {
		rightMember.name = dataFields[0];
		rightMember.code = dataFields[1];
		rightMember.sum = std::stoi(dataFields[2]);
		rightMember.isPaid = std::stoi(dataFields[3]);
	}

	return inputStream;
}

