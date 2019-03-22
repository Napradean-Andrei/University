#pragma once
#include "Controller.h"
#include "Serializer.h"

class UI
{
private:
	Controller ctrl;

public:
	UI();
	~UI();
	UI(Serializer* ser);
	void startUI();

private:
	void selectMode();
	void adminMode();
	void addBulk();
	void addDog();
	void deleteDog();
	//void deleteDog1();
	void updateDog();
	void showAllDogs();
	void less();
	void allBreed();
	void allDogs();
	void watchResults(vector<Dog> dogs);
	void addToAdoptionList(Dog m);
	void userMode();
	void printAdoptionList();
	void ReadFromFile();
	void WriteToFile();
	void saveAdoptionList();
	void seeAdoptionList();

};