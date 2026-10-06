#include "shop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    shop window;
    window.show();
    return app.exec();
}
