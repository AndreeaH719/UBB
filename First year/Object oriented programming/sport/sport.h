#pragma once
#include "service.h"
#include "repo.h"
#include <QtWidgets/QMainWindow>
#include "ui_sport.h"

class sport : public QMainWindow
{
    Q_OBJECT

public:
    sport(QWidget *parent = nullptr);
    ~sport();

private:
    Ui::sportClass ui;
    repo r;
    service s;
};

