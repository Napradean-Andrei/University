#include "UI.h"

#include <Windows.h>
#include <iostream>

UI::UI()
{}
UI::~UI()
{}

void printMenuAdmin()
{
	printf("**************************************************************************************\n");
	printf("Administrator Mode : \n");
	printf("Press 1 to Add a Dog\n");
	printf("Press 2 to Update a Dog\n");
	printf("Press 3 to Delete a Dog\n");
	printf("Press 4 to Delete a Dog\n");
	printf("Press 5 to see All dogs with less weigth than value\n");
	printf("Press 0 to Exit m\n");
	printf("**************************************************************************************\n");

}

void UI::addBulk()
{
	this->ctrl.addController("beagle", "Luke", 8, "www.google.com/0",20);
	this->ctrl.addController("labrador", "DOGO", 4, "www.google.com/1",30);
	this->ctrl.addController("beagle", "Beagy", 12, "www.google.com/2",40);
	this->ctrl.addController("beagle","Fluff", 11, "www.google.com/3",20);
	this->ctrl.addController("bulldog", "Spot", 7, "www.google.com/14",16);
	this->ctrl.addController("boxer", "Mufasa", 6, "www.google.com/5",100);
}



void UI::deleteDog()
{
	int position;
	printf("Give position : ");
	scanf("%d", &position);

	this->ctrl.deleteController(position);
}
void UI::deleteDog1()
{
	string breed, name, photograph;
	int age, index,weigth;
	char temp[200];
	printf("Give new breed : "); scanf("%s", temp); breed = temp;
	printf("Give new name : "); scanf("%s", temp); name = temp;
	printf("Give new age : "); scanf("%d", &age);
	printf("Give new photograph : "); scanf("%s", temp); photograph = temp;
	printf("Give weigth : "); scanf("%d", &weigth);
	Dog d = Dog(breed, name, age, temp,weigth);
	this->ctrl.deleteController1(d);
}

void UI::showAllDogs()
{
	printf("%s", this->ctrl.toStringController().c_str());
}
void UI::less()
{
	int value;
	printf("Give value : ");
	scanf("%d", &value);
	DynamicVector<Dog> m = this->ctrl.lessController(value);
	for (int i = 0; i < m.getSize(); i++)
	{
		printf("%s", m[i].toString().c_str());
		printf("\n");
	}
}
void UI::addDog()
{
	string breed, name, photograph;
	int age, weigth;
	char temp[200];
	printf("Give breed : "); scanf("%s", temp); breed = temp;
	printf("Give name : "); scanf("%s", temp); name = temp;
	printf("Give age : "); scanf("%d", &age);
	printf("Give photograph : "); scanf("%s", temp); photograph = temp;
	printf("Give weigth : "); scanf("%d", &weigth);

	this->ctrl.addController(breed, name, age, photograph, weigth);
}

void UI::updateDog()
{
	string breed, name, photograph;
	int age, index, weigth;
	char temp[200];
	printf("Give index : "); scanf("%d", &index);
	printf("Give new breed : "); scanf("%s", temp); breed = temp;
	printf("Give new name : "); scanf("%s", temp); name = temp;
	printf("Give new age : "); scanf("%d", &age);
	printf("Give new photograph : "); scanf("%s", temp); photograph = temp;
	printf("Give weigth : "); scanf("%d", &weigth);

	this->ctrl.updateController(index, breed, name, age, photograph, weigth);
}
void UI::adminMode()
{
	int i = 6;
	printMenuAdmin();
	
	showAllDogs();
	printf("option : "); scanf("%d", &i);
	
	while (i != 0)
	{
		switch (i)
		{

		case 1:
			addDog();
			showAllDogs();
			break;
		case 2:
			updateDog();
			showAllDogs();
			break;
		case 3:
			deleteDog();
			showAllDogs();
			break;
		case 4:
			deleteDog1();
			showAllDogs();
			break;
		case 5:
			less();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
		printf("\n");
		printMenuAdmin();
		printf("\n");
		printf("option: "); scanf("%d", &i);
	}
}




void UI::selectMode()
{
	int i;
	
	scanf("%d", &i);
	while (i != 0)
	{
		switch (i)
		{
		case 1:
			this->adminMode();
			break;
		
		default:
			printf("Give valid command : ");
			break;
		}
		
		scanf("%d", &i);
	}
}





void UI::startUI()
{

	this->addBulk();
	this->selectMode();

}