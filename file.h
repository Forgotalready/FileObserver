#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>
#include <QObject>

class File : public QObject
{
    Q_OBJECT
private:
    // Хранятся данные последнего опроса FileManager
    QString path;
    bool exists;
    long long size;
public:
    File();
    File(const QString& name);

    QString getPath();
    bool isExists();
    long long getSize();
    QString getFullInform();

    void updateState();
signals:
    void fileChange(File*);
};
#endif // FILE_H
