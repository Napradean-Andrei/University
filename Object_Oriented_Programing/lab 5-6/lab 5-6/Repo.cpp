#include "Repo.h"
#include "stdio.h"

Repo::Repo() {}

Dog& Repo::operator[](unsigned int index)
{
	return this->database[index];
}

void Repo::addRepo(Dog& d)
{
	
	this->database.add(d);
}

void Repo::deleteRepo(const int position)
{
	
	this->database.deleteArray(position);
}
void Repo::deleteRepo1(Dog& d)
{

	this->database=this->database-d;
}

void Repo::updateRepo(const int index, Dog& d)
{

	this->database[index] =d;
	
}
DynamicVector<Dog> Repo::less(int value)
{
	DynamicVector<Dog> buff;
	for (int i = 0; i < this->database.getSize(); i++)
	{
		if (this->database[i] < value)
			buff.add(this->database[i]);
	}
	return buff;

}

string Repo::toStringRepo()
{
	char c[10];
	string print = "\n";
	print += "Dogs Database\n";
	for (int i = 0; i < this->database.getSize(); i++)
	{
		sprintf(c, "%d", i);
		print += c;
		print += this->database[i].toString();
		print += "\n";
	}
	return print;

}
DynamicVector<Dog> Repo::allBreed(const string s, const int a)
{

	if (s.empty() == true)
		return this->database;

	DynamicVector<Dog> buff;

	for (int i = 0; i < this->database.getSize(); ++i)
	{
		if ((strcmp(this->database[i].getBreed().c_str(), s.c_str()) == 0)&& (this->database[i].getAge()<a))
			buff.add(this->database[i]);
	}
	return buff;
}
DynamicVector<Dog> Repo::allDogs()
{

	DynamicVector<Dog> buff;

	for (int i = 0; i < this->database.getSize(); ++i)
	{
		
			buff.add(this->database[i]);
	}
	return buff;
}

