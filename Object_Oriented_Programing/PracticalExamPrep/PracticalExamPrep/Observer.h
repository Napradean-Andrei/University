#pragma once
#include <vector>

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {};
};


class Subject {
private:
	std::vector<Observer*> observers;

public:
	virtual ~Subject() {};

	void addObserver(Observer* newObs);
	void removeObserver(Observer* observer);
	void notify();
};