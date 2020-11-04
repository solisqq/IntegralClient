#include "error.h"

#include <qsqlrecord.h>

int Error::getDbID() const
{
    return dbID;
}

bool Error::getClicked() const
{
    return clicked;
}

Error::Error(const QString &_source, const QString &_value, Error::Priority _priority, bool _noticable, bool showInErrors, const QString &_hint, int lifeTime):
  priority(_priority), source(_source), value(_value), hint(_hint), noticable(_noticable), showInBar(showInErrors), lifetime(lifeTime), currentLifeTime(lifeTime) {

}

void Error::setSource(QString text)
{
    source = text;
}

void Error::setValue(const QString &_value)
{
    value = _value;
}

QString Error::getString()
{
    QString type;
    if(priority==Priority::Warning)
        type = "ostrzeżenie";
    else
        type = "alarm";
    if(dateAccepted.toString("dd-MM-yy hh:mm").count()<3)
        return QString("Wyświetlono ")+type+": "+value+". Źródło: "+source+".";
    else
        return QString("Odczytano ")+type+": "+value+". Źródło: "+source+".";
}

void Error::update(Error *uperror)
{
    delete uperror;
}

void Error::setClicked()
{
    clicked = true;
}

Error *Error::fromSQL(const QSqlRecord &record)
{
    Error *toRet = new Error();
    toRet->dbID = record.value(0).toInt();
    toRet->source = record.value(1).toString();
    toRet->value = record.value(2).toString();
    toRet->hint = record.value(3).toString();
    toRet->noticable = record.value(4).toBool();
    toRet->noticed = record.value(5).toBool();
    toRet->showInBar = record.value(7).toBool();
    toRet->clicked = record.value(8).toBool();
    if(record.value(9).toBool()) {
        toRet->priority = Priority::CriticalError;
    }
    return toRet;
}
