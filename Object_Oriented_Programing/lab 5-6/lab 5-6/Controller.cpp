#include "Controller.h"

Controller::Controller()
{

}

Controller::~Controller() {}



void Controller::updateController(const int index, const string breed, const string name, const int age, const string photograph, const int weigth)
{
	Dog d = Dog(breed, name, age, photograph,weigth);
	this->repository.updateRepo(index, d);
}
DynamicVector<Dog> Controller::lessController(int value)
{
	return this->repository.less(value);
}

string Controller::toStringController()
{
	return this->repository.toStringRepo();
}



void Controller::addController(const string breed, const string name, const int age, const string photograph, const int weigth)
{
	Dog d = Dog(breed, name, age, photograph, weigth);
	this->repository.addRepo(d);
}

void Controller::deleteController(const int position)
{
	this->repository.deleteRepo(position);
}

void Controller::deleteController1(Dog& d)
{
	this->repository.deleteRepo1(d);
}


DynamicVector<Dog> Controller::allBreedController(const string s,const int a)
{
	return this->repository.allBreed(s,a);
}
DynamicVector<Dog> Controller::allDogsController()
{
	return this->repository.allDogs();
}
