#include "Repo1.h"
#include "stdio.h"
#include <fstream>
#include "RepositoryExceptions1.h"
#include <iostream>
Repo::Repo() {}

Dog& Repo::operator[](unsigned int index)
{
	return this->database[index];
}

void Repo::addRepo(Dog& d)
{
	if (find(this->database.begin(), this->database.end(), d) != this->database.end())
	{
		throw DuplicateException();
		return;
	}
	else
	{
		this->database.push_back(d);
		this->writeToFile();
	}
}

void Repo::deleteRepo(const int position)
{

	this->database.erase(this->database.begin()+position);
	this->writeToFile();
}

string Repo::toStringRepo()
{
	char c[10];
	int x = 1;
	string print = "\n";
	print += "Dogs Database\n";
	for (std::vector<Dog>::iterator it = this->database.begin(); it != this->database.end(); ++it)
	{
		sprintf(c, "%d", x);
		x++;
		print += c;
		print += it->toString();
		print += "\n";
	}
	return print;

}
void Repo::readFromFile()
{
	ifstream file("AdoptionList.csv");

	if (!file.is_open())
		throw FileException("The file could not be opened!");
	Dog s;
	while (file >> s)
		this->database.push_back(s);

	file.close();
}

void Repo::updateRepo(const int index, Dog& d)
{

	this->database[index] = d;
	this->writeToFile();

}
vector<Dog> Repo::allBreed(const string s, const int a)
{

	if (s.empty() == true)
		return this->database;

	vector<Dog> buff;

	for (std::vector<Dog>::iterator it = this->database.begin(); it != this->database.end(); ++it)
	{
		if ((strcmp(it->getBreed().c_str(), s.c_str()) == 0) && (it->getAge()<a))
			buff.push_back(*it);
	}
	return buff;
}

vector<Dog> Repo::allDogs()
{

	return this->database;
}
void Repo::clear()
{
	this->database.clear();
}

vector<Dog> Repo::less(int value)
{
	vector<Dog> buff;
	for (std::vector<Dog>::iterator it = this->database.begin(); it != this->database.end(); ++it)
	{
		if (*it < value)
			buff.push_back(*it);
	}
	return buff;

}



void Repo::writeToFile()
{
	ofstream file("AdoptionList.csv");
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->database)
	{
		file << s;
	}

	file.close();
}