#ifndef APP_H
#define APP_H

#include "consolelog.h"
#include "file.h"
#include<thread>
#include "FileManager.h"

class App
{
private:
    QVector<QString> inputFilePath(ILog*);
public:
    App() = default;

    void start();
};

#endif // APP_H
