#include "Offer.h"
#include <string.h>
#include <stdio.h>
#include <errno.h> 

Offer createOffer(char type[], char address[], int surface, int price)
{
	Offer o;
	strcpy_s(o.type,strlen(type)+1, type);
	strcpy_s(o.address, strlen(address) + 1, address);
	o.surface = surface;
	o.price = price;

	return o;
}

char* getType(Offer* o)
{
	return o->type;
}

char* getAddress(Offer* o)
{
	return o->address;
}

double getSurface(Offer* o)
{
	return o->surface;
}

double getPrice(Offer* o)
{
	return o->price;
}


void toString(Offer o, char str[])
{
	sprintf(str, " %s  %s  %d  %d.", o.type, o.address, o.surface, o.price);
}