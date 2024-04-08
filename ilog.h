#ifndef ILOG_H
#define ILOG_H

#include <QObject>

class ILog : public QObject
{
    Q_OBJECT
public:
    virtual void log(const QString& str) const = 0;
    virtual ~ILog() = default;
public slots:
    virtual void notify(const QVector<QString>& arr) const = 0;
};

#endif // ILOG_H
