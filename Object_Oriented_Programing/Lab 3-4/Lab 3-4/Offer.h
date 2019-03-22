#pragma once
typedef struct
{
	char type[50];
	char address[50];
	int surface;
	int price;
} Offer;

Offer createOffer( char type[], char address[], int surface, int price);

char* getType(Offer* o);
char* getType(Offer* o);
int surface(Offer* o);
int price(Offer* o);


void toString(Offer o, char str[]);

