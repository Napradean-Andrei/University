#include "UI.h"

#include <Windows.h>
#include <iostream>

UI::UI()
{}
UI::~UI()
{}

UI::UI(Serializer * ser)
{
	this->ctrl = Controller(ser);
}

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
	printf("Press 6 to read ff m\n");
	printf("Press 7 to write ff\n");
	printf("**************************************************************************************\n");

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

	
	try
	{
		this->ctrl.addController(breed, name, age, photograph, weigth);
	}
	catch (DogException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}
void UI::addBulk()
{
	this->ctrl.addController("beagle", "Luke", 8, "www.google.com/0", 20);
	this->ctrl.addController("labrador", "DOGO", 4, "www.google.com/1", 30);
	this->ctrl.addController("beagle", "Beagy", 12, "www.google.com/2", 40);
	this->ctrl.addController("beagle", "Fluff", 11, "www.google.com/3", 20);
	this->ctrl.addController("bulldog", "Spot", 7, "www.google.com/14", 16);
	this->ctrl.addController("boxer", "Mufasa", 6, "www.google.com/5", 100);
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

void UI::deleteDog()
{
	int position;
	printf("Give position : ");
	scanf("%d", &position);

	this->ctrl.deleteController(position);
}
/*void UI::deleteDog1()
{
	string breed, name, photograph;
	int age, index, weigth;
	char temp[200];
	printf("Give new breed : "); scanf("%s", temp); breed = temp;
	printf("Give new name : "); scanf("%s", temp); name = temp;
	printf("Give new age : "); scanf("%d", &age);
	printf("Give new photograph : "); scanf("%s", temp); photograph = temp;
	printf("Give weigth : "); scanf("%d", &weigth);
	Dog d = Dog(breed, name, age, temp, weigth);
	this->ctrl.deleteController1(d);
}*/
void UI::ReadFromFile()
{
	this->ctrl.ReadFromFile();
}
void UI::WriteToFile()
{
	this->ctrl.WriteToFile();
}
void UI::saveAdoptionList()
{
	this->ctrl.saveAdoptionList();
}


void UI::adminMode()
{
	int i = 6;
	printMenuAdmin();

	showAllDogs();
	printf("Press a key: "); scanf("%d", &i);

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
			//deleteDog1();
			showAllDogs();
			break;
		case 5:
			less();
			break;
		case 6:
			this->ReadFromFile();
			break;
		case 7:
			this->WriteToFile();
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
		printf("press a key : "); scanf("%d", &i);
	}
}
void UI::seeAdoptionList()
{
	this->ctrl.seeAdoptionList();
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
	vector<Dog> m = this->ctrl.lessController(value);
	for (int i = 0; i < m.size(); i++)
	{
		printf("%s", m[i].toString().c_str());
		printf("\n");
	}
}
void printMenuUser()
{
	printf("User Menu \n");
	printf("1. See Dogs one by one\n");
	printf("2. See all the dogs of a given breed, having an age less than a given number\n");
	printf("3. See Adoptionlist\n");
	printf("5. Save Adoptionlist \n");
	printf("0. Back \n");
}

void UI::allBreed()
{
	char temp[200];
	int age;
	printf("Give breed :");
	scanf(" %[^\n]s", temp);
	string s = temp;
	printf("Give age :");
	scanf("%d", &age);
	int a = age;


	this->watchResults(this->ctrl.allBreedController(s, a));

}
void UI::allDogs()
{


	this->watchResults(this->ctrl.allDogsController());

}

void UI::addToAdoptionList(Dog m) { this->ctrl.addAdoptionList(m); }

void UI::printAdoptionList() { printf("%s", this->ctrl.toStringAdoptionList().c_str()); }

void UI::watchResults(vector<Dog> dogs)
{
	int j = 2, n;

	for (int i = 0; i < dogs.size(); ++i)
	{

		printf(" press 0 to go back   press 1 to Add To Adoption List    press 2 to not adopt and see the next Dog\n", dogs[i].toString().c_str());

		cout << dogs[i].getName().c_str() << ' ' << dogs[i].getBreed().c_str() << ' ' << dogs[i].getAge() << ' ' << dogs[i].getWeigth() << ' ';
		
		scanf("%d", &j);

		switch (j)
		{
		case 0:
			system("cls");
			return;
			break;
		case 1:
			this->addToAdoptionList(dogs[i]);
			break;
		case 2:
			break;
		default:
			break;
		}

		if (i == dogs.size() - 1)
			i = -1;
	}

}



void menuMode()
{

	printf("\t Press 1 for Administrator Mode\n");
	printf("\t Press 2 for User Mode\n");
	printf("\t Press 0 to Exit \n");
}

void UI::userMode()
{
	int i = 1;
	while (i != 0)
	{
		printMenuUser();
		scanf("%d", &i);
		switch (i)
		{
		case -1:
			system("cls");
			break;
		case 0:
			system("cls");
			break;
		case 1:
			this->allDogs();
			break;
		case 2:
			this->allBreed();
			break;
		case 3:
			this->printAdoptionList();
			break;
		case 4:
			this->saveAdoptionList();
			break;
		case 5:
			this->seeAdoptionList();
			break;
		default:
			break;
		}
	}

}
void UI::selectMode()
{
	int i;
	menuMode();
	scanf("%d", &i);
	while (i != 0)
	{
		switch (i)
		{
		case 1:
			this->adminMode();
			break;
		case 2:
			this->userMode();
			break;
		default:
			printf("Give valid option: ");
			break;
		}
		menuMode();
		scanf("%d", &i);
	}
}

void UI::startUI()
{

	this->addBulk();
	this->selectMode();

}