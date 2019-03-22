#include "quickUI.h"
#include "qlineedit.h"
#include "qboxlayout.h"
#include <iostream>
#include <string>
#include "string.h"
quickUI::quickUI(QWidget *parent) : QWidget(parent) {

	this->setMinimumSize(1000, 500);
	this->initUI();

}

void quickUI::initUI() {

	this->listView = new QListWidget(this);
	this->sortButton = new QPushButton("Sort", this);
	this->calculateButton = new QPushButton("Calculate Sum", this);

	this->filterText = new QLineEdit(this);

	QHBoxLayout* temp = new QHBoxLayout(this);
	QVBoxLayout* leftColumn = new QVBoxLayout(this);

	leftColumn->addWidget(this->filterText);

	leftColumn->addWidget(this->sortButton);
	leftColumn->addWidget(this->calculateButton);

	temp->addLayout(leftColumn);
	temp->addWidget(this->listView);

	this->linkSignalsAndSlots();
	this->ctrl.readFromFile();
	emit refreshList();

}

void quickUI::linkSignalsAndSlots() {

	

	QObject::connect(this, &quickUI::refreshList, this, &quickUI::repopulateList);

	QObject::connect(this->calculateButton, &QPushButton::clicked, this, &quickUI::getSum);

}


void quickUI::getSum() {
	std::string filterText;
	
	filterText = this->filterText->text().toStdString();
	int a;
	
	a = this->ctrl.getSum(filterText);
	std::string b;
	b = std::to_string(a);
	
	this->listView->addItem(new QListWidgetItem(b.c_str()));

	
}




void quickUI::getBill() {
	this->listView->clear();
	std::string text;
	std::string filterText;

	filterText = this->filterText->text().toStdString();

	std::vector<Bill> temp = this->ctrl.getAll();
	for (int i = 0; i < temp.size(); i++) {

		text = temp[i].getName() + " - " + temp[i].getCode() + " - " + std::to_string(temp[i].getSum()) + " - " + std::to_string(temp[i].getIsPaid());

		this->listView->addItem(new QListWidgetItem(text.c_str()));
	}

}

void quickUI::repopulateList() {
	this->listView->clear();
	std::string text;
	std::vector<Bill> temp = this->ctrl.getAll();
	for (int i = 0; i < temp.size(); i++) {

		text = temp[i].getName() + " - " + temp[i].getCode() + " - " + std::to_string(temp[i].getSum())+" - " + std::to_string(temp[i].getIsPaid());

		this->listView->addItem(new QListWidgetItem(text.c_str()));
	}
}
