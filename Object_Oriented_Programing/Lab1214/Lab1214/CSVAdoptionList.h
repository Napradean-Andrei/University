#pragma once

#include <string>
#include <fstream>
#include <Windows.h>
#include "Serializer1.h"
class CSVAdoptionList : public Serializer {

public:
	CSVAdoptionList() {}
	void writeToFile() override {
		ofstream f("AdoptionList.csv");
		for (int i = 0; i < this->getSize(); i++)
			f << this->dogs[i];
	}
	void viewAdoptionList() {

		ShellExecuteA(NULL, NULL, "excel.exe", "AdoptionList.csv", NULL, SW_SHOWMAXIMIZED);
	}
};