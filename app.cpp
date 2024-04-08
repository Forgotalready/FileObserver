#include "app.h"

QVector<QString> App::inputFilePath(ILog* l)
{
    l->log(QString("Input number files: "));
    QTextStream cin(stdin);
    int numberOfFiles;
    cin >> numberOfFiles;
    if(numberOfFiles <= 0){
        return QVector<QString>();
    }
    l->log(QString("Input absolute file path"));
    QVector<QString> paths;
    for(int i = 0;i < numberOfFiles;i++){
        QString path;
        cin >> path;
        paths.push_back(path);
    }
    return paths;
}

void App::start()
{
    ILog* l = new ConsoleLog;
    auto paths = inputFilePath(l);
    //QString name = "D:\\QT\\Projects\\SoftwareDevelopmentLab1\\test.txt";
    //QString name1 = "ewklrfgjlkedfljg";

    FileManager f(l);
    for(auto x : paths)
        f.addFile(x);

    while(true){
        f.updateFileState();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
