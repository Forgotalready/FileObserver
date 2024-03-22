#include <QCoreApplication>
#include "consolelog.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ILog* l = new ConsoleLog;
    l->log("Hi");

    return a.exec();
}
