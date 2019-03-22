#include "Dog.h"

Dog::Dog() :breed(""), name(""), age(), photograph(""), weigth() {}

Dog::Dog(const string& breed, const string& name, const int age, const string& photograph, const int weigth)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
	this->weigth = weigth;
	
}

string Dog::getBreed() const { return this->breed; }
string Dog::getName() const { return this->name; }
int Dog::getAge() const { return this->age; }
string Dog::getPhotograph() const { return this->photograph; }
int Dog::getWeigth() const { return this->weigth; }

void Dog::setBreed(string breed) { this->breed = breed; }
void Dog::setName(string name) { this->name = name; }
void Dog::setAge(int age) { this->age = age; }
void Dog::setPhotograph(string photograph) { this->photograph = photograph; }
void Dog::setWeigth(int weigth) { this->weigth = weigth; }

bool Dog::operator==(const Dog& d)
{
	return !strcmp(this->getPhotograph().c_str(), d.getPhotograph().c_str());
}
bool Dog::operator<(int value)
{
	return this->getWeigth() < value;
}


string Dog::toString()
{
	char c[200];
	sprintf(c, "%10s   %10s    %10d     %10s   %10d",
		this->getBreed().c_str(), this->getName().c_str(), this->getAge(),  this->getPhotograph().c_str(), this->getWeigth());
	return c;
}
