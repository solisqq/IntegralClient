#ifndef ERROR_H
#define ERROR_H

#include <QDateTime>
#include <QString>

#include <interfaces/dbinterface.h>
//#include <database/database.h>
#include "../printable/printable.h"

class Database;

class Error: public PrintAble
{
    int dbID=0;
    bool clicked=false;
    Error(){}
public:
    enum Priority {
        Warning=0,
        CriticalError=1
    };
    Priority priority=Priority::Warning;
    QString source="", value="", hint="";
    bool noticable = false;
    bool noticed = false;
    //bool log=true;
    bool showInBar=true;
    QDateTime dateAccepted, dateAnnouced;
    int lifetime = 0;
    int currentLifeTime = 0;
    bool log=false;

    Error(const QString &_source, const QString &_value, Error::Priority _priority, bool _noticable = false, bool showInErrors=true, const QString &_hint = "", int lifeTime=0);
    Error(const Error&)=delete;//Nie pozwól kopiować, inicjalizacja ma się odbywać raz i tylko raz w źródle
    void setSource(QString text);
    void setValue(const QString& _value);
    QString getString() override;
    void update(Error* uperror);
    void setClicked();
    // DBInterface interface
public:
    static Error* fromSQL(const QSqlRecord &record);
    int getDbID() const;
    bool getClicked() const;
};

#endif // ERROR_H
