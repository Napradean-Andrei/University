#pragma once
#include "Repo.h"
#include "AdoptionList.h"
class Controller
{
private:
	Repo repository;

public:
	Controller();
	~Controller();

	void addController(const string breed, const string name, const int	age, const string photograph, const int weigth);
	void deleteController(const int position);
	void deleteController1(Dog& d);
	void updateController(const int index, const string breed, const string name, const int	age, const string photograph, const int weigth);
	DynamicVector<Dog> lessController(int value);
	string toStringController();
	void addAdoptionList(const Dog m);
	string toStringAdoptionList();
	int getAdoptionListSize();


	DynamicVector<Dog> allBreedController(const string s, const int a);
	DynamicVector<Dog> allDogsController();
};