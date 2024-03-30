#include <QCoreApplication>

#include "consolelog.h"
#include "file.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ILog* l = new ConsoleLog;
    QString name = "D:\\QT\\Projects\\SoftwareDevelopmentLab1\\test.txt";
    QString name1 = "ewklrfgjlkedfljg";
    File t(name);
    QString output; output.setNum(t.getState().getSize());
    l->log(t.getState().getFullInform());

    return a.exec();
}
