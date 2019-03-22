/********************************************************************************
** Form generated from reading UI file 'quickUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKUI_H
#define UI_QUICKUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_quickUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *quickUIClass)
    {
        if (quickUIClass->objectName().isEmpty())
            quickUIClass->setObjectName(QStringLiteral("quickUIClass"));
        quickUIClass->resize(600, 400);
        menuBar = new QMenuBar(quickUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        quickUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(quickUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        quickUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(quickUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        quickUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(quickUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        quickUIClass->setStatusBar(statusBar);

        retranslateUi(quickUIClass);

        QMetaObject::connectSlotsByName(quickUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *quickUIClass)
    {
        quickUIClass->setWindowTitle(QApplication::translate("quickUIClass", "quickUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class quickUIClass: public Ui_quickUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKUI_H
