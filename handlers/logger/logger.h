#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QTimer>
#include "../errorHandler/error.h"
#include <QDebug>
#include <widgets/menuelement.h>


class Logger : public QObject, public MenuElement
{
    Q_OBJECT
    void logData(const QDateTime &date, const QString &msg);
public:
    Logger();
    ~Logger() override;
    void initialize();
    void add(Error &error);
    void add(const QString &msg, const QString &source);
    QWidget * getView() override;
};

#endif // LOGGER_H
