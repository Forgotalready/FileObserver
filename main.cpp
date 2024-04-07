#include <QCoreApplication>

#include "app.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    App app;
    app.start();

    return a.exec();
}
