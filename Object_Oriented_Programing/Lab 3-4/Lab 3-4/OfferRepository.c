#include "OfferRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

OfferRepo createRepo()
{
	OfferRepo v;
	v.length = 0;

	return v;
}

int find(OfferRepo* v, char address[])
{
	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->offers[i].address, address) == 0)
			return i;
	}
	return -1;
}

	int delete(OfferRepo* v, Offer o)
	{
		if (find(v, o.address) == -1)
			return 0;
		for (int i = find(v, o.address); i < v->length; ++i) {
			v->offers[i] = v->offers[i + 1];
		}
		v->length--;
		return 1;
	}
	int update(OfferRepo* v, Offer m, Offer n)
	{
		if (find(v, m.address) == -1)
			return 0;
		v->offers[find(v, m.address)] = n;
		return 1;
	}
	int containstring(OfferRepo* v, Offer o, char tofind[])
	{
		if (strcmp(tofind, " ") == 0)
			return 1;
		if (strstr(o.address, tofind) != 0)
			return 1;
		return 0;
	}
int add(OfferRepo* v, Offer o)
{
	
	if (find(v, o.address) != -1)
		return 0;

	v->offers[v->length] = o;
	v->length++;

	return 1;
}

int checkType(OfferRepo* v, Offer o, char tofind[])
{
	if (strcmp(tofind, " ") == 0)
		return 1;
	if (strstr(o.type, tofind) != 0)
		return 1;
	return 0;
}
int getLength(OfferRepo* v) 
{
	return v->length;
}
Offer getOfferOnPos(OfferRepo* v, int pos) 
{
	if (pos < 0 || pos >= v->length)
		return createOffer("", "", 0, 0);
	return v->offers[pos];
}
