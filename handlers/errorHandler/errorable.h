#ifndef ERRORABLE_H
#define ERRORABLE_H
#include <QObject>
#include "error.h"

class ErrorAble
{
public:
    QString sourceName = "Unknown";
    QList<Error*> errors;
    explicit ErrorAble();
    void generateError(Error &error);
    void cancelError(Error &error);
    bool errorExist(Error &error);
    void resetErrors();
private:
    bool error = false;
signals:

public slots:
};

#endif // ERRORABLE_H
