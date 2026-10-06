#include "sport.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    sport window;
    window.show();
    return app.exec();
}
