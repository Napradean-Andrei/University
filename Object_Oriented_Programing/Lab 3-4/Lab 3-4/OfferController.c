#include "OfferController.h"
#include <string.h>
#include <stdlib.h>

Controller createController(OfferRepo* r, OfferRepo* aux) {
	Controller c;
	c.repo = r;
	c.repo2 = aux;

	return c;
}

int addOffer(Controller* c, char type[], char address[], int surface, int price)
{
	Offer o = createOffer(type, address, surface, price);

	int res = add(c->repo, o);
	return res;
}
int deleteOffer(Controller* c, char type[], char address[], int surface, int price) {
	Offer o = createOffer(type, address, surface, price);
	int res = delete(c->repo, o);
	return res;
}

int updateOffer(Controller* c, char type1[], char address1[], int surface1, int price1, char type2[], char address2[], int surface2, int price2) {
	Offer m = createOffer(type1, address1, surface1, price1);
	Offer n = createOffer(type2, address2, surface2, price2);
	int res = update(c->repo, m, n);
	return res;
}

void ascending(Controller* c, char tofind[]) 
{
	int res = 0, i;
	Offer o;
	for (i = 0; i < getLength(c->repo); ++i) 
	{
		res = containstring(c->repo, getOfferOnPos(c->repo, i), tofind);
		if (res == 1)
			add(c->repo2, getOfferOnPos(c->repo, i));
	}
	for (i = 0; i < getLength(c->repo2) - 1; i++)
		for (int j = 0; j < getLength(c->repo2) - i - 1; j++) {
			if (getOfferOnPos(c->repo2, j).price > getOfferOnPos(c->repo2, j + 1).price) 
			{
				o = getOfferOnPos(c->repo2, j);
				c->repo2->offers[j] = getOfferOnPos(c->repo2, j + 1);
				c->repo2->offers[j + 1] = o;
			}
		}
}

void lab34activity(Controller* c, char tofind[])
{
	int res = 0, i;
	Offer o;
	for (i = 0; i < getLength(c->repo); ++i)
	{
		res = checkType(c->repo, getOfferOnPos(c->repo, i), tofind);
		if (res == 1)
			add(c->repo2, getOfferOnPos(c->repo, i));
	}
	for (i = 0; i < getLength(c->repo2) - 1; i++)
		for (int j = 0; j < getLength(c->repo2) - i - 1; j++) {
			if (strcmp(getOfferOnPos(c->repo2, j).address, getOfferOnPos(c->repo2, j + 1).address) > 0)
			{
				o = getOfferOnPos(c->repo2, j);
				c->repo2->offers[j] = getOfferOnPos(c->repo2, j + 1);
				c->repo2->offers[j + 1] = o;
			}
		}
}
void subpunctc(Controller* c, char tofind[], int value)
{
	int res = 0, i;
	Offer o;
	for (i = 0; i < getLength(c->repo); ++i)
	{
		res = checkType(c->repo, getOfferOnPos(c->repo, i), tofind);

		if (res == 1&&  (getOfferOnPos(c->repo, i).surface>value))
			add(c->repo2, getOfferOnPos(c->repo, i));
	}
	
}
void lab4activity(Controller* c, char tofind[],int value)
{
	int res = 0, i;
	Offer o;
	for (i = 0; i < getLength(c->repo); ++i)
	{
		res = checkType(c->repo, getOfferOnPos(c->repo, i), tofind);
		if (res == 1 && (getOfferOnPos(c->repo, i).price<value))
			add(c->repo2, getOfferOnPos(c->repo, i));
	}
	for (i = 0; i < getLength(c->repo2) - 1; i++)
		for (int j = 0; j < getLength(c->repo2) - i - 1; j++) {
			if (getOfferOnPos(c->repo2, j).price > getOfferOnPos(c->repo2, j + 1).price)
			{
				o = getOfferOnPos(c->repo2, j);
				c->repo2->offers[j] = getOfferOnPos(c->repo2, j + 1);
				c->repo2->offers[j + 1] = o;
			}
		}
}
OfferRepo* getRepo(Controller* c) {
	return c->repo;
}

OfferRepo* getRepo2(Controller* c) {
	return c->repo2;
}