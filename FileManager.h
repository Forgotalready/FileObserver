#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "ilog.h"
#include "file.h"
#include <QObject>

class FileManager : public QObject
{
    Q_OBJECT
private:
    QVector<File*> trackFiles;
    ILog* logger;
    QVector<File*> changedFiles;
public:
    FileManager(ILog*);
    void updateFileState();
    void addFile(const QString& path);
    ~FileManager();
signals:
    void outputSignal(QVector<QString>&);
public slots:
    void fileChange(File*);
};

#endif // FILEMANAGER_H
