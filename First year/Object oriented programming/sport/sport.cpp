#include "sport.h"
#include <qmessagebox.h>
sport::sport(QWidget *parent)
    : QMainWindow(parent), r("ex.txt"),s(r)
{
    ui.setupUi(this);
    //s.addentites();
    auto elems = s.getAll();
    for (const auto& s : elems)
    {
        QString text = QString::number(s.getStart()) + " " + QString::number(s.getEnd()) + " " +
            QString::fromStdString(s.getType()) + " " + QString::number(s.getLevel()) + " "+
            QString::fromStdString(s.getDescription());
        QListWidgetItem *item=new QListWidgetItem(text);
        ui.listSee->addItem(item);
    }
    connect(ui.lineFilter, &QLineEdit::textChanged, this, [this](const QString& text)
        {
              int l = ui.lineFilter->text().toInt();
              ui.listSee->clear();
              auto elems = s.getAll();
              for (const auto& s : elems)
              {
                  if (s.getLevel() > l)
                  {
                      QString text = QString::number(s.getStart()) + " " + QString::number(s.getEnd()) + " " +
                          QString::fromStdString(s.getType()) + " " + QString::number(s.getLevel()) + " " +
                          QString::fromStdString(s.getDescription());
                      QListWidgetItem* item = new QListWidgetItem(text);
                      ui.listSee->addItem(item);
                  }
                 
              }
              
        });
    connect(ui.btnFilter, &QPushButton::clicked, this, [this]()
        {
            std::string desc = ui.lineDesc->text().toStdString();
            int st = ui.lineStart->text().toInt();
            auto elems = s.getAll();
            bool found = false;
            for (const auto& s : elems)
            {
                if (s.getDescription() == desc && s.getStart() == st)
                {
                    QString text = QString::number(s.getStart()) + " " + QString::number(s.getEnd());
                    QListWidgetItem* item = new QListWidgetItem(text);
                    ui.listFilter->addItem(item);
                    int nr = s.getEnd() - s.getStart();
                    ui.labelHours->setText(QString::number(nr));
                    found  = true;
                }

            }
            if(!found)
                QMessageBox::critical(this, "Error", "Not found");

        });
}

sport::~sport()
{}

