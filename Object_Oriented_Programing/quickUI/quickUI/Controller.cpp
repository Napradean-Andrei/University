#include "Controller.h"



void controller::readFromFile() {
	this->repository.readFromFile();
}



int controller::getSum(std::string name) {
	return this->repository.getSum(name);
}

std::vector<Bill> controller::getAll() {

	return this->repository.getAll();
}

controller::controller() {

}


controller::~controller() {

}
