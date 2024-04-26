#include "consolelog.h"

void ConsoleLog::log(const QString &str) const
{
    QTextStream cout(stdout);
    cout << str << Qt::endl;
}

void ConsoleLog::notify(const QVector<QString> &arr) const
{
    QTextStream cout(stdout);
    for(const auto& x : arr)
        cout << x << Qt::endl;
}
