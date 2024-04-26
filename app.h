#ifndef APP_H
#define APP_H

#include "Logging\consolelog.h"
#include "File\file.h"
#include<thread>
#include "FileManager\FileManager.h"

class App
{
private:
    QVector<QString> inputFilePath(ILog*);
public:
    App() = default;

    void start();
};

#endif // APP_H
