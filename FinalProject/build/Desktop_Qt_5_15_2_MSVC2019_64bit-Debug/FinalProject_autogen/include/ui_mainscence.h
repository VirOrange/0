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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScence
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainScence)
    {
        if (MainScence->objectName().isEmpty())
            MainScence->setObjectName(QString::fromUtf8("MainScence"));
        MainScence->resize(800, 600);
        actionquit = new QAction(MainScence);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(MainScence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainScence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainScence->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(MainScence);

        QMetaObject::connectSlotsByName(MainScence);
    } // setupUi

    void retranslateUi(QMainWindow *MainScence)
    {
        MainScence->setWindowTitle(QCoreApplication::translate("MainScence", "MainScence", nullptr));
        actionquit->setText(QCoreApplication::translate("MainScence", "Quit", nullptr));
        menu->setTitle(QCoreApplication::translate("MainScence", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScence: public Ui_MainScence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENCE_H
