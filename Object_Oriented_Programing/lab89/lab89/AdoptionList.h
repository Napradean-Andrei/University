#pragma once
#include "Dog.h"
#include "DynamicVector.h"
#include <string>

class AdoptionList
{
protected:
	DynamicVector<Dog> dogs;

public:
	AdoptionList();
	~AdoptionList();

	Dog& operator[](int index);
	int getSize();
	int getDogs();
	string toString();
	void addDogList(const Dog m);



};
