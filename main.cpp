#include <QCoreApplication>

#include "consolelog.h"
#include "file.h"
#include<thread>
#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ILog* l = new ConsoleLog;
    QString name = "D:\\QT\\Projects\\SoftwareDevelopmentLab1\\test.txt";
    QString name1 = "ewklrfgjlkedfljg";

    FileManager f(l);
    f.addFile(name);
    f.addFile(name1);

    while(true){
        f.updateFileState();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
