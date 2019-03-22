#include "DogGUI.h"
#include <QDebug>
#include <QMessageBox>


GenesGUI::GenesGUI(QWidget * parent) : QWidget{ parent }
{
	this->initGUI();
}

GenesGUI::~GenesGUI()
{
}
void GenesGUI::initGUI()
{
	QHBoxLayout* colums = new QHBoxLayout(this);


	this->breedEdit = new QLineEdit(this);
	this->nameEdit = new QLineEdit(this);
	this->ageEdit = new QLineEdit(this);
	this->photographEdit = new QLineEdit(this);
	this->weigthEdit = new QLineEdit(this);


	this->breedEdit->setPlaceholderText("breed");
	this->nameEdit->setPlaceholderText("name");
	this->ageEdit->setPlaceholderText("age");
	this->photographEdit->setPlaceholderText("photograph");
	this->weigthEdit->setPlaceholderText("weigth");

	this->addDogButton = new QPushButton("Add", this);
	this->deleteDogButton = new QPushButton("Delete", this);
	this->updateDogButton = new QPushButton("Update", this);
	this->comboBox = new QComboBox{ this };
	comboBox->addItem("Detailed");
	comboBox->addItem("Short");
	comboBox->setGeometry(QRect(320, 0, 150, 40));

	QGridLayout* leftside = new QGridLayout();

	leftside->addWidget(this->breedEdit, 0, 1, 1, 2);
	leftside->addWidget(this->nameEdit, 0, 1, 3, 2);
	leftside->addWidget(this->ageEdit, 0, 1, 5, 2);
	leftside->addWidget(this->photographEdit, 0, 1, 7, 2);
	leftside->addWidget(this->weigthEdit, 0, 1, 9, 2);

	
	QHBoxLayout* buttons = new QHBoxLayout();
	buttons->addWidget(this->addDogButton);
	buttons->addWidget(this->updateDogButton);
	buttons->addWidget(this->deleteDogButton);

	leftside->addLayout(buttons, 4, 0, 4, 5);

	colums->addItem(leftside);

	this->dogList = new QListWidget(this);

	this->loadFile = new QPushButton("load from file", this);
	this->saveFile = new QPushButton("save to file", this);

	QHBoxLayout* buttons2 = new QHBoxLayout();
	buttons->addWidget(this->loadFile);
	buttons->addWidget(this->saveFile);




	QVBoxLayout* rightside = new QVBoxLayout(this);
	rightside->addWidget(this->dogList);


	rightside->addLayout(buttons2);

	colums->addItem(rightside);

	this->connectSignalsAndSlots();
}


void GenesGUI::connectSignalsAndSlots()
{
	QObject::connect(this->addDogButton, &QPushButton::clicked, this, &GenesGUI::addDog);

	QObject::connect(this, &GenesGUI::updateList, this, &GenesGUI::displayList);

	QObject::connect(this->updateDogButton, &QPushButton::clicked, this, &GenesGUI::updateDog);

	QObject::connect(this, &GenesGUI::updateList, this, &GenesGUI::displayList);

	QObject::connect(this->deleteDogButton, &QPushButton::clicked, this, &GenesGUI::deleteDog);

	QObject::connect(this, &GenesGUI::updateList, this, &GenesGUI::displayList);

	QObject::connect(this->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(changeText(const QString&)));

	QObject::connect(this->loadFile, &QPushButton::clicked, this, &GenesGUI::load);

	QObject::connect(this->saveFile, &QPushButton::clicked, this, &GenesGUI::save);


}



void GenesGUI::addDog()
{
	string breed = this->breedEdit->text().toStdString();
	string name= this->nameEdit->text().toStdString();
	int age = this->ageEdit->text().toInt();
	string photograph = this->photographEdit->text().toStdString();

	int weigth = this->weigthEdit->text().toInt();

	this->ctrl.addController(breed, name, age, photograph, weigth);

	emit updateList();
}

void GenesGUI::displayList()
{
	string text;
	this->dogList->clear();
	vector<Dog> buff = this->ctrl.allDogsController();
	for (int i = 0; i < buff.size(); i++)
	{
		text = buff[i].getBreed() + " - " + buff[i].getName() + " - " + std::to_string(buff[i].getAge()) + " - " + buff[i].getPhotograph() + " - " + std::to_string(buff[i].getWeigth());
		this->dogList->addItem(new QListWidgetItem(text.c_str()));
	}
}

void GenesGUI::updateDog()
{
	QModelIndexList index = this->dogList->selectionModel()->selectedIndexes();
	int position = index.at(0).row();

	string breed = this->breedEdit->text().toStdString();
	string name = this->nameEdit->text().toStdString();
	int age = this->ageEdit->text().toInt();
	string photograph = this->photographEdit->text().toStdString();

	int weigth = this->weigthEdit->text().toInt();

	this->ctrl.updateController(position, breed, name, age, photograph, weigth);
	emit updateList();
}

void GenesGUI::deleteDog()
{
	QModelIndexList index = this->dogList->selectionModel()->selectedIndexes();


	int position = index.at(0).row();



	this->ctrl.deleteController(position);

	emit updateList();
}
void GenesGUI::load()
{
	this->ctrl.clearC();
	this->ctrl.ReadFromFile();

	emit updateList();
}

void GenesGUI::save()
{
	this->ctrl.WriteToFile();
}
void GenesGUI::changeText(const QString &text) {
	if (text == "Detailed")
		this->displayList();
	else
		this->populateRepoList2();
}

void GenesGUI::populateRepoList2() {
	this->dogList->clear();
	vector<Dog> buff = this->ctrl.allDogsController();
	for (int i = 0; i < buff.size(); i++)
		this->dogList->addItem(new QListWidgetItem(buff[i].getBreed().c_str()));
}