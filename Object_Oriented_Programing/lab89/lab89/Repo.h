#pragma once
#include "DynamicVector.h"
#include <vector>
#include "Dog1.h"

class Repo
{
private:
	vector<Dog> database;

public:
	Repo();

	Dog& operator[](unsigned int index);

	void addRepo(Dog& d);
	void deleteRepo(const int position);
	//void deleteRepo1(Dog& d);
	void updateRepo(const int index, Dog& n);
	vector<Dog> allBreed(const string s, const int a);
	vector<Dog> allDogs();
	vector<Dog> less(int value);
	string toStringRepo();
	void readFromFile();
	void writeToFile();
};