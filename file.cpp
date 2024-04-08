#include "file.h"

File::File(const QString &name)
    : path(name)
{
    QFileInfo q = QFileInfo(path);
    exists = q.exists();
    size = static_cast<long long>(q.size());
}

QString File::getPath() const
{
    return path;
}

bool File::isExists() const
{
    return exists;
}

long long File::getSize() const
{
    return size;
}

QString File::getFullInform() const
{
    QString info = "";
    if(exists) {
        info += (path + QString(" exists "));
        QString s_size;
        s_size.setNum(getSize());
        info += (QString("size " + s_size));
    }else{
        info = path + QString(" not exists ");
    }
    return info;
}

void File::updateState()
{
    //Получение текущего состояния файла.
    QFileInfo q = QFileInfo(path);
    bool nowExitsts = q.exists();
    long long nowSize = static_cast<long long>(q.size());

    if(nowExitsts != q.exists() || nowSize != size) {
        exists = nowExitsts;
        size = nowSize;
        emit fileChange(this);
    }

}
