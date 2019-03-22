#pragma once
#include "Repo1.h"
#include "AdoptionList1.h"
#include "DogValidator1.h"
#include "RepositoryExceptions1.h"
#include "Serializer1.h"
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
	void clearC();
	
	vector<Dog> allBreedController(const string s, const int a);
	vector<Dog> allDogsController();
};