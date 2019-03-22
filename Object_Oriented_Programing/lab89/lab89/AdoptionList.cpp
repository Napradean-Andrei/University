#include "AdoptionList1.h"

AdoptionList::AdoptionList() {}
AdoptionList::~AdoptionList() {}

Dog& AdoptionList::operator[](int index) {

	return this->dogs[index];
}

int AdoptionList::getSize() { return this->dogs.getSize(); }

string AdoptionList::toString()
{
	string a = "\n";
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		a += this->dogs[i].toString();
		a += "\n";
	}
	return a;
}


void AdoptionList::addDogList(const Dog m)
{
	for (int i = 0; i < dogs.getSize(); i++)
		if (this->dogs[i] == m)
		{
			printf("Dog already exists\n");
			return;
		}
	this->dogs.add(m);
}




