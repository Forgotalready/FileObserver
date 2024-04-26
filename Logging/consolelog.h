#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include "ilog.h"
#include <QTextStream>

class ConsoleLog final : public ILog
{
    Q_OBJECT
public:
    void log(const QString&) const override;
public slots:
    void notify(const QVector<QString>&) const override;
};

#endif // CONSOLELOG_H
