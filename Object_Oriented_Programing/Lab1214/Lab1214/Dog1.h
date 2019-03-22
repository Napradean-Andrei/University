#pragma once
#include <string>
using namespace std;

class Dog
{
protected:
	string breed;
	string name;
	int age;
	string photograph;
	int weigth;

public:

	Dog();
	Dog(const string& breed, const string& name, const int age, const string& photograph, const int weigth);

	string getBreed() const;
	string getName() const;
	string getPhotograph() const;
	int getAge() const;
	int getWeigth() const;


	void setBreed(string breed);
	void setName(string name);
	void setPhotograph(string photograph);
	void setAge(int age);
	void setWeigth(int weigth);



	bool operator==(const Dog& d);


	bool operator<(int value);

	string toString();
	friend  istream & operator>>(istream & is, Dog & s);
	friend ostream & operator<<(ostream & os, const Dog & s);
};
