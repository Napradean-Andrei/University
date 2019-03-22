#pragma once
#include "Bill.h"
#include <vector>
#include <iostream>
#include <fstream>
class Repo {
	std::vector<Bill> List;
public:

	
	int getSum(std::string name);
	std::vector<Bill>getAll();
	void readFromFile();
	void test();
	Repo();
	~Repo();
};

