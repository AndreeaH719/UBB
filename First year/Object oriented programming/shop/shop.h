#pragma once
#include "service.h"
#include "repo.h"
#include <QtWidgets/QMainWindow>
#include "ui_shop.h"

class shop : public QMainWindow
{
    Q_OBJECT

public:
    shop(QWidget *parent = nullptr);
    ~shop();

private:
    Ui::shopClass ui;
    repo r;
    service s;
};

