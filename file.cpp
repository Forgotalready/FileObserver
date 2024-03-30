#include "file.h"

File::File(QString &name)
    : f(name)
{}

FileState File::getState()
{
    return f;
}

FileState::FileState(QString &name)
    :path (name)
{
    QFileInfo q = QFileInfo(path);
    is_Exists = q.exists();
    size = static_cast<long long>(q.size());
}

QString FileState::getPath()
{
    return path;
}

bool FileState::isExists()
{
    return is_Exists;
}

long long FileState::getSize()
{
    return size;
}

QString FileState::getFullInform()
{
    QString info = "";
    if(is_Exists) {
        info += (path + QString(" exists "));
        QString s_size;
        s_size.setNum(getSize());
        info += (QString("size " + s_size));
    }else{
        info = path + QString(" not exists ");
    }
    return info;
}
