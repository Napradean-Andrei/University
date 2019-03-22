/********************************************************************************
** Form generated from reading UI file 'Lab1214.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1214_H
#define UI_LAB1214_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1214Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1214Class)
    {
        if (Lab1214Class->objectName().isEmpty())
            Lab1214Class->setObjectName(QStringLiteral("Lab1214Class"));
        Lab1214Class->resize(1280, 720);
        menuBar = new QMenuBar(Lab1214Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab1214Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1214Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab1214Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab1214Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab1214Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab1214Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab1214Class->setStatusBar(statusBar);

        retranslateUi(Lab1214Class);

        QMetaObject::connectSlotsByName(Lab1214Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1214Class)
    {
        Lab1214Class->setWindowTitle(QApplication::translate("Lab1214Class", "Lab1214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab1214Class: public Ui_Lab1214Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1214_H
