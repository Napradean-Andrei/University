#pragma once
#include <string>
#include "AdoptionList1.h"
#include <vector>
#include "Repo1.h"

using namespace std;

class FileAdoptionList : public AdoptionList {
protected:
	string filename;
public:
	FileAdoptionList(string file) : filename(file) {};
	virtual ~FileAdoptionList() { }

	virtual void writeToFile() = 0;
	virtual void displayAdoptionList() const = 0;

};