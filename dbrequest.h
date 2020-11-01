#ifndef DBREQUEST_H
#define DBREQUEST_H

#include <QObject>
#include <QTimer>

class DBRequest : public QObject
{
    Q_OBJECT
public:
    enum CMD {
        arm=0,
        disarm=1,
        alarm_off=2
    };
    void make(QString dbName);
    static DBRequest *create(CMD _cmd, int db_id, QList<int> _vals, QString _pass);
private:
    int requestLost=0;
    DBRequest(CMD _cmd, int db_id, QList<int> _vals, QString _pass);
    CMD cmd;
    int dbid;
    QList<int> vals;
    QString pass;
    int id=-1;
    QTimer keepTrackTimer;
    QString dbname;
private slots:
    void checkDB();
signals:
    void cmdReturned(CMD, int);
};

#endif // DBREQUEST_H
