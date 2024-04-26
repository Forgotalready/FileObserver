#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Logging\ilog.h"
#include "File\file.h"
#include <QObject>
#include <QRegExp>

class FileManager : public QObject
{
    Q_OBJECT
private:
    QVector<File*> trackFiles;
    ILog* logger;
    QVector<File*> changedFiles;

    explicit FileManager(ILog*);
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;
    ~FileManager();

public:

    static FileManager& Instanse(ILog* log){
        static FileManager f(log);
        return f;
    }

    void updateFileState();
    void addFile(const QString& path);


private:
    bool pathValid(const QString&);

signals:
    void outputSignal(QVector<QString>&);
public slots:
    void fileChange(File*);
};

#endif // FILEMANAGER_H
