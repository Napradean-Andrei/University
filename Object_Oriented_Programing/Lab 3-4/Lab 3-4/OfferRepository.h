#pragma once
#include "Offer.h"

typedef struct
{
	Offer offers[100];
	int length;
} OfferRepo;


OfferRepo createRepo();


int find(OfferRepo* v, char address[]);


int add(OfferRepo* v, Offer o);

int delete(OfferRepo* v, Offer o);

int update(OfferRepo* v, Offer m, Offer n);

int containstring(OfferRepo* v, Offer o, char tofind[]);
int checkType(OfferRepo* v, Offer o, char tofind[]);

int getLength(OfferRepo* o);


Offer getOfferOnPos(OfferRepo* v, int pos);

