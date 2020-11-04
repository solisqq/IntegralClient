#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QSqlQueryModel>
#include <QString>

class DBInterface
{
    QString tname="";
    QList<QPair<QString, QString>> toCommit;
public:
    DBInterface(const QString& tableName);
    virtual QString toSQL()=0;
    virtual void fromSQL(QSqlQueryModel* model)=0;
    template<typename T> void setDBVal(const QString& val_name, T val);
    void setDBVal(const QString& val_name, const QString& val);
    QString getCommitString();
};

#endif // DBINTERFACE_H
