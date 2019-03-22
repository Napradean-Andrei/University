#pragma once
#include "Repo.h"
#include "AdoptionList.h"
#include "DogValidator.h"
#include "RepositoryExceptions.h"
#include "Serializer.h"
class Controller
{
private:
	Repo repository;
	Serializer* AdoptionList;
	DogValidator V;
public:
	Controller();
	Controller(Serializer* ser);
	~Controller();

	void addController(const string breed, const string name, const int	age, const string photograph, const int weigth);
	void deleteController(const int position);
	//void deleteController1(Dog& d);
	void updateController(const int index, const string breed, const string name, const int	age, const string photograph, const int weigth);
	vector<Dog> lessController(int value);
	string toStringController();
	void addAdoptionList(const Dog m);
	string toStringAdoptionList();
	int getAdoptionListSize();
	void ReadFromFile();
	void WriteToFile();
	void saveAdoptionList();
	void seeAdoptionList();

	vector<Dog> allBreedController(const string s, const int a);
	vector<Dog> allDogsController();
};