#pragma once
#include "repo.h"

class controller {

	Repo repository;
public:

	void readFromFile();
	std::vector<Bill> getAll();
	int getSum(std::string name);
	

	controller();
	~controller();
};

