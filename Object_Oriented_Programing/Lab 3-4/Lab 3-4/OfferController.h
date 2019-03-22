#pragma once
#include "OfferRepository.h"

typedef struct
{
	OfferRepo* repo;
	OfferRepo* repo2;
} Controller;

Controller createController(OfferRepo* r,OfferRepo* aux);

int addOffer(Controller* c, char type[], char address[], int surface, int price);


int deleteOffer(Controller* c, char type[], char address[], int surface, int price);


int updateOffer(Controller* c, char type1[], char address1[], int surface1, int price1, char type2[], char address2[], int surface2, int price2);


void ascending(Controller*c, char tofind[]);

void lab34activity(Controller* c, char tofind[]);

void subpunctc(Controller* c, char tofind[], int value);

void lab4activity(Controller* c, char tofind[], int value);

OfferRepo* getRepo(Controller* c);

OfferRepo* getRepo2(Controller* c);





