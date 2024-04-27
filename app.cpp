#include "app.h"

QVector<QString> App::inputFilePath(ILog* l)
{
    Q_ASSERT_X(l != nullptr, "App input method", "Logger not initilize");
    if(l == nullptr)
        qWarning("App input method : Logger not initilize");

    if(l)
        l->log(QString("Input number files: "));

    QTextStream cin(stdin);
    int numberOfFiles;
    cin >> numberOfFiles;

    if(numberOfFiles <= 0)
        return QVector<QString>();

    if(l)
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
    ILog* l = new ConsoleLog();
    auto paths = inputFilePath(l);
    //QString name = "D:\\QT\\Projects\\SoftwareDevelopmentLab1\\test.txt";
    //QString name1 = "ewklrfgjlkedfljg";
    FileManager::Instanse(l);

    for(auto x : paths)
        FileManager::Instanse(l).addFile(x);

    while(true){
        FileManager::Instanse(l).updateFileState();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}
