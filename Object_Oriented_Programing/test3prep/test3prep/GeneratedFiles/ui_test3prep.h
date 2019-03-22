/********************************************************************************
** Form generated from reading UI file 'test3prep.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3PREP_H
#define UI_TEST3PREP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test3prepClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test3prepClass)
    {
        if (test3prepClass->objectName().isEmpty())
            test3prepClass->setObjectName(QStringLiteral("test3prepClass"));
        test3prepClass->resize(600, 400);
        menuBar = new QMenuBar(test3prepClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        test3prepClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test3prepClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        test3prepClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(test3prepClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        test3prepClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(test3prepClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        test3prepClass->setStatusBar(statusBar);

        retranslateUi(test3prepClass);

        QMetaObject::connectSlotsByName(test3prepClass);
    } // setupUi

    void retranslateUi(QMainWindow *test3prepClass)
    {
        test3prepClass->setWindowTitle(QApplication::translate("test3prepClass", "test3prep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test3prepClass: public Ui_test3prepClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3PREP_H
