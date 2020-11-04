#include "dbrequest.h"
#include <utils/converter.h>
#include <QSqlQuery>
#include <QSqlError>
#include <dialogs/infodialog.h>

DBRequest::DBRequest(CMD _cmd, int db_id, QList<int> _vals, QString _pass):
    cmd(_cmd), dbid(db_id), vals(_vals), pass(_pass) {}

DBRequest* DBRequest::create(CMD _cmd, int db_id, QList<int> _vals, QString _pass) {
    auto request = new DBRequest(_cmd, db_id, _vals, _pass);
    QSqlQuery query;
    QString toRet="";
    for(auto item : _vals) {
        toRet+=QString::number(item);
        toRet+=",";
    }
    toRet.chop(1);
    query.exec("INSERT INTO requests (cmd,dbid,values,fulfill,pass) "
               "VALUES ("
               ""+QString::number(static_cast<int>(request->cmd))+","+QString::number(request->dbid)+","+toRet+",0,"+request->pass+") RETURNING id;");
    query.next();
    request->id = query.value(0).toInt();
    connect(&request->keepTrackTimer, &QTimer::timeout, request, &DBRequest::checkDB);
    request->keepTrackTimer.start(1000);
    return request;
}

void DBRequest::checkDB()
{
    QSqlQuery query;
    query.exec("SELECT fulfill FROM requests WHERE id="+QString::number(id)+";");
    qDebug()<<query.lastError();
    query.next();
    requestLost++;
    int returned = query.value(0).toInt();
    if(returned!=0 || requestLost>50) {
        query.exec("DELETE FROM requests WHERE id="+QString::number(id)+";");
        emit(cmdReturned(cmd, returned));

        keepTrackTimer.stop();
        InfoDialog* dial = nullptr;
        if(cmd==CMD::alarm_off) {
            if(returned==1) dial = new InfoDialog(InfoDialog::Info, "Alarm Wył.", "Poprawnie wyłączono alarmy w wybranych jednostkach.");
            else dial = new InfoDialog(InfoDialog::Warning, "Błąd", "Nie wyłączono alarmów w wybranych jednostkach. Problem z połączeniem lub podano niepoprawne hasło.");
        } else if(cmd==CMD::arm) {
            if(returned==1) dial = new InfoDialog(InfoDialog::Info, "Uzbrojono", "Poprawnie uzbrojono wybrane jednostki.");
            else dial = new InfoDialog(InfoDialog::Warning, "Błąd", "Nie uzbrojono wybranych jednostek. Problem z połączeniem lub podano niepoprawne hasło.");
        } else if(cmd==CMD::disarm) {
            if(returned==1) dial = new InfoDialog(InfoDialog::Info, "Rozbrojono", "Poprawnie rozbrojono wybrane jednostki.");
            else dial = new InfoDialog(InfoDialog::Warning, "Błąd", "Nie rozbrojono wybranych jednostek. Problem z połączeniem lub podano niepoprawne hasło.");
        }
        if(dial!=nullptr) dial->show();
        delete this;
    }
}


