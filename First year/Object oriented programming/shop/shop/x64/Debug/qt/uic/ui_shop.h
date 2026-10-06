/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

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

class Ui_shopClass
{
public:
    QWidget *centralWidget;
    QListWidget *listSee;
    QLineEdit *lineCategory;
    QLineEdit *lineName;
    QLineEdit *lineQuantity;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnFilter;
    QLineEdit *lineFilter;
    QLabel *labelQuantity;
    QLineEdit *lineFilter2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *shopClass)
    {
        if (shopClass->objectName().isEmpty())
            shopClass->setObjectName("shopClass");
        shopClass->resize(600, 400);
        centralWidget = new QWidget(shopClass);
        centralWidget->setObjectName("centralWidget");
        listSee = new QListWidget(centralWidget);
        listSee->setObjectName("listSee");
        listSee->setGeometry(QRect(10, 10, 256, 192));
        lineCategory = new QLineEdit(centralWidget);
        lineCategory->setObjectName("lineCategory");
        lineCategory->setGeometry(QRect(280, 10, 113, 24));
        lineName = new QLineEdit(centralWidget);
        lineName->setObjectName("lineName");
        lineName->setGeometry(QRect(280, 40, 113, 24));
        lineQuantity = new QLineEdit(centralWidget);
        lineQuantity->setObjectName("lineQuantity");
        lineQuantity->setGeometry(QRect(280, 70, 113, 24));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(280, 100, 80, 24));
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(280, 130, 80, 24));
        btnFilter = new QPushButton(centralWidget);
        btnFilter->setObjectName("btnFilter");
        btnFilter->setGeometry(QRect(420, 40, 80, 24));
        lineFilter = new QLineEdit(centralWidget);
        lineFilter->setObjectName("lineFilter");
        lineFilter->setGeometry(QRect(420, 10, 113, 24));
        labelQuantity = new QLabel(centralWidget);
        labelQuantity->setObjectName("labelQuantity");
        labelQuantity->setGeometry(QRect(420, 70, 49, 16));
        lineFilter2 = new QLineEdit(centralWidget);
        lineFilter2->setObjectName("lineFilter2");
        lineFilter2->setGeometry(QRect(280, 160, 113, 24));
        shopClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(shopClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        shopClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(shopClass);
        mainToolBar->setObjectName("mainToolBar");
        shopClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(shopClass);
        statusBar->setObjectName("statusBar");
        shopClass->setStatusBar(statusBar);

        retranslateUi(shopClass);

        QMetaObject::connectSlotsByName(shopClass);
    } // setupUi

    void retranslateUi(QMainWindow *shopClass)
    {
        shopClass->setWindowTitle(QCoreApplication::translate("shopClass", "shop", nullptr));
        btnAdd->setText(QCoreApplication::translate("shopClass", "Add", nullptr));
        btnDelete->setText(QCoreApplication::translate("shopClass", "Delete", nullptr));
        btnFilter->setText(QCoreApplication::translate("shopClass", "Filter", nullptr));
        labelQuantity->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shopClass: public Ui_shopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
