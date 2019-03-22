#include "UI.h"
#include <stdio.h>
#include "OfferController.h"

UI createUI(Controller* c)
{
	UI ui;
	ui.ctrl = c;

	return ui;
}


void printMenu() 
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("1- Add an Offer\n");
	printf("2- List all Offers\n");
	printf("3- Delete an Offer\n");
	printf("4- Update an Offer\n");
	printf("5- sort all offers by price whose address containing a string\n");
	printf("6- sort all offers by address with a given type\n");
	printf("7- see all offers of a given type, having the surface greater than a given value\n");
	printf("8- Display all offers having a given type and a price less than a given value, sorted ascending by price\n");
	printf("0- Exit\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
}


int validCommand(int command)
{
	if (command >= 0 && command <= 9)
		return 1;
	return 0;
}


int deleteOfferUI(UI* ui)
{
	char type[50], address[50];
	int surface = 0;
	int price = 0;

	printf("Please input the type: ");
	scanf_s("%s", type, sizeof type);
	printf("Please input the address: ");
	scanf_s("%s", address, sizeof address);
	printf("Please input the surface: ");
	scanf_s("%d", &surface);
	printf("Please input the price: ");
	scanf_s("%d", &price);

	return deleteOffer(ui->ctrl, type, address, surface, price);
}

int updateOfferUI(UI* ui) {
	char type1[50], address1[50];
	int surface1 = 0;
	int price1 = 0;
	char type2[50], address2[50];
	int surface2 = 0;
	int price2 = 0;
	printf("Please input the type: ");
	scanf_s("%s", type1, sizeof type1);
	printf("Please input the address: ");
	scanf_s("%s", address1, sizeof address1);
	printf("Please input the surface: ");
	scanf_s("%d", &surface1);
	printf("Please input the price: ");
	scanf_s("%d", &price1);
	printf("Please input the type: ");
	printf("Please input the type: ");
	scanf_s("%s", type2, sizeof type2);
	printf("Please input the address: ");
	scanf_s("%s", address2, sizeof address2);
	printf("Please input the surface: ");
	scanf_s("%d", &surface2);
	printf("Please input the price: ");
	scanf_s("%d", &price2);

	return updateOffer(ui->ctrl, type1, address1, surface1, price1, type2, address2, surface2, price2);
}
int addOfferUI(UI* ui)
{
	
	char type[50], address[50];
	int surface = 0;
	int price = 0;

	printf("Please input the type: ");
	scanf_s("%s", type,sizeof type);
	printf("Please input the address: ");
	scanf_s("%s", address, sizeof address);
	printf("Please input the surface: ");
	scanf_s("%d", &surface);
	printf("Please input the price: ");
	scanf_s("%d", &price);
	return addOffer(ui->ctrl, type, address, surface, price);
}



void listAllOffersUI(UI* ui) 
{
	OfferRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no offers.";
		printf("%s\n", str);
	}

	for (int i = 0; i < getLength(repo); ++i) {
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listAscendingUI(UI *ui) {
	char tofind[50];
	printf("Input string to find: ");
	scanf_s("%s", tofind,sizeof tofind);
	ascending(ui->ctrl, tofind);
	OfferRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no offers.";
		printf("%s\n", str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void lab34activityUI(UI *ui) {
	char tofind[50];
	printf("Input a type: ");
	scanf_s("%s", tofind, sizeof tofind);
	lab34activity(ui->ctrl, tofind);
	OfferRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no offers.";
		printf("%s\n", str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void subpunctcUI(UI *ui) {
	char tofind[50];
	int value;
	printf(" type: ");
	scanf_s("%s", tofind, sizeof tofind);
	printf(" value: ");
	scanf_s("%d", &value);
	subpunctc(ui->ctrl, tofind,value);
	OfferRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no offers.";
		printf("%s\n", str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void lab4activityUI(UI *ui) {
	char tofind[50];
	int value;
	printf("type: ");
	scanf_s("%s", tofind, sizeof tofind);
	printf(" value: ");
	scanf_s("%d", &value);
	lab4activity(ui->ctrl, tofind, value);
	OfferRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no offers.";
		printf("%s\n", str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void startUI(UI* ui)
{
	while (1) {
		printMenu();
		int command;
		scanf_s("%d", &command);
		while (validCommand(command) == 0) 
		{
			printf(" input a valid command!\n");
			scanf_s("%d", &command);
		}
		if (command == 0)
			break;
		if (command == 1) 
		{
			int res = addOfferUI(ui);
			if (res == 1)
				printf("Offer added.\n");
			else
				printf("Offer could not be added\n");
		}
		if (command == 2)
			listAllOffersUI(ui);
		if (command == 3) 
		{
			int res = deleteOfferUI(ui);
			if (res == 1)
				printf("Offer deleted.\n");
			else
				printf("Offer was not deleted");
		}
		if (command == 4) 
		{
			int res = updateOfferUI(ui);
			if (res == 1)
				printf("offer updated\n");
			else
				printf("offer could not be updated\n");
		}


		if (command == 5)
			listAscendingUI(ui);
		if (command == 6)
			lab34activityUI(ui);
		if (command == 7)
			subpunctcUI(ui);
		if (command == 8)
			lab4activityUI(ui);
	}
}