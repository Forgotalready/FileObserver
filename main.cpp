#include <QCoreApplication>

#include "consolelog.h"
#include "file.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ILog* l = new ConsoleLog;
    QString name = "C:\\qtprojects\\SoftwareDevelopmentLab1\\test.txt";
    File t(name);
    l->log(t.getSize());

    return a.exec();
}
