#include "file.h"

File::File() : QFile() {}

File::File(QString &name)
    : QFile(name)
{}

QString File::getSize() const
{
    int size = QFile::size();
    QString str_size;
    str_size.setNum(size);
    return (str_size + QString(" bite"));
}

QString File::isExits() const
{
    bool exits = QFile::exists();

    if(exits){
        return QString(" exist");
    }else{
        return QString(" not exist");
    }
}
