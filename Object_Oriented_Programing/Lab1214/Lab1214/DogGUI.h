#pragma once
#include <qwidget.h>
#include "Dog1.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "Controller1.h"
#include <QComboBox>
using namespace std;

class GenesGUI : public QWidget
{
	Q_OBJECT

public:
	GenesGUI(QWidget *parent = 0);
	~GenesGUI();

private:
	Controller ctrl;

	

	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photographEdit;
	QLineEdit* weigthEdit;
	

	QPushButton* addDogButton;
	QPushButton* deleteDogButton;
	QPushButton* updateDogButton;
	QComboBox *comboBox;
	

	

	QListWidget* dogList;
	QPushButton* loadFile;
	QPushButton* saveFile;

	void initGUI();
	void connectSignalsAndSlots();
	void clearFields();


	void listItemChanged();

signals:

	void updateList();

	public slots:
	void displayList(); 
	void addDog();
	void updateDog();
	void deleteDog();
	void load();
	void populateRepoList2();
	void save();
	void changeText(const QString &text);
};

