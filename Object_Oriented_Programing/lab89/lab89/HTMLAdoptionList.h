#pragma once

#include <string>
#include <fstream>
#include <Windows.h>
#include "Serializer1.h"
using namespace std;

class HTMLAdoptionList : public Serializer {
public:
	HTMLAdoptionList() {}
	void writeToFile()  {
		ofstream g("AdoptionList.html");
		g << "<!DOCTYPE html>\n<html>\n<head>\n<title>AdoptionList</title>\n</head>\n<body>\n<table border = \"1\">\n";
		g << "<tr>\n";
		g << "<td>Breed</td>\n";
		g << "<td>Name</td>\n";
		g << "<td>Age</td>\n";
		g << "<td>Photograph</td>\n";
		g << "<td>Weigth</td>\n";
		g << "</tr>\n";
		for (int i = 0; i < this->getSize(); i++) {
			g << "<tr>\n";
			g << "<td>" << this->dogs[i].getBreed() << "</td>\n";
			g << "<td>" << this->dogs[i].getName() << "</td>\n";
			g << "<td>" << this->dogs[i].getAge() << "</td>\n";
			g << "<td><a href='" << this->dogs[i].getPhotograph() << "'>link</a></td>\n";
			g << "<td>" << this->dogs[i].getWeigth() << "</td>\n";
			g << "</tr>\n";
		}
	
		g << "</table>\n</body>\n</html>";
		g.close();
	}
	void viewAdoptionList()  {
	
		ShellExecuteA(NULL, NULL, "opera.exe","file:///C:/Users/andre/source/repos/lab89/lab89/AdoptionList.html", NULL, SW_SHOWMAXIMIZED);
	}
};