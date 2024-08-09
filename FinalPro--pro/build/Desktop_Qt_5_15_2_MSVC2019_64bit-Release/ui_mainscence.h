/********************************************************************************
** Form generated from reading UI file 'mainscence.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENCE_H
#define UI_MAINSCENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScence
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuStart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScence)
    {
        if (MainScence->objectName().isEmpty())
            MainScence->setObjectName(QString::fromUtf8("MainScence"));
        MainScence->resize(800, 600);
        actionQuit = new QAction(MainScence);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainScence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainScence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuStart = new QMenu(menubar);
        menuStart->setObjectName(QString::fromUtf8("menuStart"));
        MainScence->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScence);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainScence->setStatusBar(statusbar);

        menubar->addAction(menuStart->menuAction());
        menuStart->addAction(actionQuit);

        retranslateUi(MainScence);

        QMetaObject::connectSlotsByName(MainScence);
    } // setupUi

    void retranslateUi(QMainWindow *MainScence)
    {
        MainScence->setWindowTitle(QCoreApplication::translate("MainScence", "MainScence", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainScence", "Quit", nullptr));
        menuStart->setTitle(QCoreApplication::translate("MainScence", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScence: public Ui_MainScence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENCE_H
