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
    explicit File(const QString& name);
    ~File() = default;

    QString getPath()const;
    bool isExists() const;
    long long getSize() const;
    QString getFullInform() const;

    void updateState();
signals:
    void fileChange(File*);
};
#endif // FILE_H
