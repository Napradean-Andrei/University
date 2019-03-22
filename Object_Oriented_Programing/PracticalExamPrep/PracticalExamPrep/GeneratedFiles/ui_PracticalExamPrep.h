/********************************************************************************
** Form generated from reading UI file 'PracticalExamPrep.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICALEXAMPREP_H
#define UI_PRACTICALEXAMPREP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticalExamPrepClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticalExamPrepClass)
    {
        if (PracticalExamPrepClass->objectName().isEmpty())
            PracticalExamPrepClass->setObjectName(QStringLiteral("PracticalExamPrepClass"));
        PracticalExamPrepClass->resize(600, 400);
        menuBar = new QMenuBar(PracticalExamPrepClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PracticalExamPrepClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticalExamPrepClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PracticalExamPrepClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PracticalExamPrepClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PracticalExamPrepClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PracticalExamPrepClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PracticalExamPrepClass->setStatusBar(statusBar);

        retranslateUi(PracticalExamPrepClass);

        QMetaObject::connectSlotsByName(PracticalExamPrepClass);
    } // setupUi

    void retranslateUi(QMainWindow *PracticalExamPrepClass)
    {
        PracticalExamPrepClass->setWindowTitle(QApplication::translate("PracticalExamPrepClass", "PracticalExamPrep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticalExamPrepClass: public Ui_PracticalExamPrepClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICALEXAMPREP_H
