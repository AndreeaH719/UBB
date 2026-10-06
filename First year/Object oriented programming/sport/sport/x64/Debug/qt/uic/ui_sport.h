/********************************************************************************
** Form generated from reading UI file 'sport.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPORT_H
#define UI_SPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sportClass
{
public:
    QWidget *centralWidget;
    QListWidget *listSee;
    QLineEdit *lineFilter;
    QLineEdit *lineDesc;
    QLineEdit *lineStart;
    QListWidget *listFilter;
    QLabel *labelHours;
    QPushButton *btnFilter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sportClass)
    {
        if (sportClass->objectName().isEmpty())
            sportClass->setObjectName("sportClass");
        sportClass->resize(600, 400);
        centralWidget = new QWidget(sportClass);
        centralWidget->setObjectName("centralWidget");
        listSee = new QListWidget(centralWidget);
        listSee->setObjectName("listSee");
        listSee->setGeometry(QRect(10, 10, 256, 192));
        lineFilter = new QLineEdit(centralWidget);
        lineFilter->setObjectName("lineFilter");
        lineFilter->setGeometry(QRect(10, 210, 113, 24));
        lineDesc = new QLineEdit(centralWidget);
        lineDesc->setObjectName("lineDesc");
        lineDesc->setGeometry(QRect(280, 10, 113, 24));
        lineStart = new QLineEdit(centralWidget);
        lineStart->setObjectName("lineStart");
        lineStart->setGeometry(QRect(280, 40, 113, 24));
        listFilter = new QListWidget(centralWidget);
        listFilter->setObjectName("listFilter");
        listFilter->setGeometry(QRect(285, 70, 251, 131));
        labelHours = new QLabel(centralWidget);
        labelHours->setObjectName("labelHours");
        labelHours->setGeometry(QRect(490, 40, 49, 16));
        btnFilter = new QPushButton(centralWidget);
        btnFilter->setObjectName("btnFilter");
        btnFilter->setGeometry(QRect(400, 40, 80, 24));
        sportClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sportClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        sportClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sportClass);
        mainToolBar->setObjectName("mainToolBar");
        sportClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sportClass);
        statusBar->setObjectName("statusBar");
        sportClass->setStatusBar(statusBar);

        retranslateUi(sportClass);

        QMetaObject::connectSlotsByName(sportClass);
    } // setupUi

    void retranslateUi(QMainWindow *sportClass)
    {
        sportClass->setWindowTitle(QCoreApplication::translate("sportClass", "sport", nullptr));
        labelHours->setText(QString());
        btnFilter->setText(QCoreApplication::translate("sportClass", "PRESS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sportClass: public Ui_sportClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPORT_H
