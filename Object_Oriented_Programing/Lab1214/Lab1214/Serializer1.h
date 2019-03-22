#pragma once
#include "AdoptionList1.h"


class Serializer :public AdoptionList
{
protected:
	string filename;

public:
	Serializer();
	~Serializer();

	void virtual writeToFile() = 0;
	void virtual viewAdoptionList() = 0;

};