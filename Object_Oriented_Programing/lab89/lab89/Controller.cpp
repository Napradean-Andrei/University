#include "Controller1.h"
#include "CSVAdoptionList.h"


Controller::Controller(Serializer* ser)
{
	this->AdoptionList = ser;
}
Controller::Controller()
{
	CSVAdoptionList temp;
	this->AdoptionList=&temp;
}

Controller::~Controller() {}





void Controller::updateController(const int index, const string breed, const string name, const int age, const string photograph, const int weigth)
{
	Dog d = Dog(breed, name, age, photograph, weigth);
	this->V.validate(d);
	this->repository.updateRepo(index, d);
}
vector<Dog> Controller::lessController(int value)
{
	return this->repository.less(value);
}
void Controller::addController(const string breed, const string name, const int age, const string photograph, const int weigth)
{
	Dog d = Dog(breed, name, age, photograph, weigth);
	this->V.validate(d);
	this->repository.addRepo(d);
}

string Controller::toStringController()
{
	return this->repository.toStringRepo();
}

void Controller::addAdoptionList(const Dog m)
{
	this->AdoptionList->addDogList(m);
}
void Controller::deleteController(const int position)
{
	this->repository.deleteRepo(position);
}

int Controller::getAdoptionListSize() { return this->AdoptionList->getSize(); }

string Controller::toStringAdoptionList() { return this->AdoptionList->toString(); }

vector<Dog> Controller::allBreedController(const string s, const int a)
{
	return this->repository.allBreed(s, a);
}
vector<Dog> Controller::allDogsController()
{
	return this->repository.allDogs();
}
void Controller::ReadFromFile()
{
	this->repository.readFromFile();

}
void Controller::WriteToFile()
{
	this->repository.writeToFile();

}
void Controller::saveAdoptionList()
{
	this->AdoptionList->writeToFile();
}

void Controller::seeAdoptionList()
{
	this->AdoptionList->viewAdoptionList();
}

