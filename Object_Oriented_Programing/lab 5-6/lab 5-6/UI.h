#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI();
	~UI();

	void startUI();

private:
	void selectMode();
	void adminMode();
	void addBulk();
	void addDog();
	void deleteDog();
	void deleteDog1();
	void updateDog();
	void showAllDogs();
	void less();
	void allBreed();
	void allDogs();

	void addToAdoptionList(Dog m);
	void userMode();
	void printAdoptionList();
	
};