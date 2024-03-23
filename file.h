#ifndef FILE_H
#define FILE_H

#include <QFile>

class File : public QFile
{
public:
    File();
    File(QString& name);
    QString getSize() const;
    QString isExits() const;
};
#endif // FILE_H
