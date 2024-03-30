#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>

class FileState{
private:
    QString path;
    // Хранятся данные последнего опроса FileManager
    bool is_Exists;
    long long size;
public:
    FileState(QString& name);
    QString getPath();
    bool isExists();
    long long getSize();
    QString getFullInform();
};

class File
{
private:
    FileState f;
public:
    File();
    File(QString& name);
    FileState getState();
};
#endif // FILE_H
