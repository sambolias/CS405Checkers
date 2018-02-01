/********************************************************************************
** Form generated from reading UI file 'Checkers.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKERS_H
#define UI_CHECKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckersClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CheckersClass)
    {
        if (CheckersClass->objectName().isEmpty())
            CheckersClass->setObjectName(QStringLiteral("CheckersClass"));
        CheckersClass->resize(600, 400);
        menuBar = new QMenuBar(CheckersClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CheckersClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CheckersClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CheckersClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CheckersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CheckersClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CheckersClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CheckersClass->setStatusBar(statusBar);

        retranslateUi(CheckersClass);

        QMetaObject::connectSlotsByName(CheckersClass);
    } // setupUi

    void retranslateUi(QMainWindow *CheckersClass)
    {
        CheckersClass->setWindowTitle(QApplication::translate("CheckersClass", "Checkers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckersClass: public Ui_CheckersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKERS_H
