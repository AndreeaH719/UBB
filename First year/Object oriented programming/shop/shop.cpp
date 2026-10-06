#include "shop.h"

shop::shop(QWidget *parent)
    : QMainWindow(parent), r("ex.txt"), s(r)
{
    ui.setupUi(this);
    //s.addentities();
    auto elems = s.getAll();
    for (const auto& l : elems)
    {
        QString text = QString::fromStdString(l.getCategory()) + " " + QString::fromStdString(l.getName()) +
           " " + QString::number(l.getQuantity());
        QListWidgetItem *item = new QListWidgetItem(text);
        QFont font;
        font.setBold(true);
        if(l.getQuantity() > 1) item->setFont(font);
        else item->setBackground(Qt::red);
        ui.listSee->addItem(item);
    }
    connect(ui.btnAdd, &QPushButton::clicked, this, [this]()
        {
            std::string c = ui.lineCategory->text().toStdString();
            std::string n = ui.lineName->text().toStdString();
            int q = ui.lineQuantity->text().toInt();
            s.add(c,n,q);
            ui.listSee->clear();
            auto elems = s.getAll();
            for (const auto& l : elems)
            {
                QString text = QString::fromStdString(l.getCategory()) + " " + QString::fromStdString(l.getName()) +
                    " " + QString::number(l.getQuantity());
                QListWidgetItem* item = new QListWidgetItem(text);
                QFont font;
                font.setBold(true);
                if (l.getQuantity() > 1) item->setFont(font);
                else item->setBackground(Qt::red);
                ui.listSee->addItem(item);
            }
        });
    connect(ui.btnDelete, &QPushButton::clicked, this, [this]()
        {
            std::string n = ui.lineName->text().toStdString();
            s.remove(n);
            ui.listSee->clear();
            auto elems = s.getAll();
            for (const auto& l : elems)
            {
                QString text = QString::fromStdString(l.getCategory()) + " " + QString::fromStdString(l.getName()) +
                    " " + QString::number(l.getQuantity());
                QListWidgetItem* item = new QListWidgetItem(text);
                QFont font;
                font.setBold(true);
                if (l.getQuantity() > 1) item->setFont(font);
                else item->setBackground(Qt::red);
                ui.listSee->addItem(item);
            }
        });
    connect(ui.btnFilter, &QPushButton::clicked, this, [this]()
        {
            std::string c = ui.lineFilter->text().toStdString();
            ui.listSee->clear();
            auto elems = s.getAll();
            int sum = 0;
            for (const auto& l : elems)
            {
                if (l.getCategory() == c)
                {
                    QString text = QString::fromStdString(l.getCategory()) + " " + QString::fromStdString(l.getName()) +
                        " " + QString::number(l.getQuantity());
                    QListWidgetItem* item = new QListWidgetItem(text);
                    QFont font;
                    sum += l.getQuantity();
                    font.setBold(true);
                    if (l.getQuantity() > 1) item->setFont(font);
                    else item->setBackground(Qt::red);
                    ui.listSee->addItem(item);
                }
                
            }
            ui.labelQuantity->setText(QString::number(sum));
        });
    connect(ui.lineFilter2, &QLineEdit::textChanged, this, [this](const QString& text)
        {
               std::string c = ui.lineFilter2->text().toStdString();
               ui.listSee->clear();
               auto elems = s.getAll();
               for (const auto& l : elems)
               {
                   if (l.getCategory() == c)
                   {
                       QString text = QString::fromStdString(l.getCategory()) + " " + QString::fromStdString(l.getName()) +
                           " " + QString::number(l.getQuantity());
                       QListWidgetItem* item = new QListWidgetItem(text);
                       QFont font;
                       font.setBold(true);
                       if (l.getQuantity() > 1) item->setFont(font);
                       else item->setBackground(Qt::red);
                       ui.listSee->addItem(item);
                   }
               }
        });
}

shop::~shop()
{}

