#ifndef STATESHANDLER_H
#define STATESHANDLER_H

#include <QObject>

class StatesHandler : public QObject
{
    Q_OBJECT
public:
    explicit StatesHandler(QObject *parent = nullptr);

signals:

};

#endif // STATESHANDLER_H
