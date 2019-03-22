#pragma once
#include "DynamicVector.h"
#include <vector>
#include "Dog.h"

class Repo
{
private:
	DynamicVector<Dog> database;

public:
	Repo();

	Dog& operator[](unsigned int index);

	void addRepo(Dog& d);
	void deleteRepo(const int position);
	void deleteRepo1(Dog& d);
	void updateRepo(const int index, Dog& n);
	DynamicVector<Dog> allBreed(const string s,const int a);
	DynamicVector<Dog> allDogs();
	DynamicVector<Dog> less(int value);
	string toStringRepo();
};