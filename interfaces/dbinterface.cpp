#include "dbinterface.h"
DBInterface::DBInterface(const QString &tableName): tname(tableName){}

void DBInterface::setDBVal(const QString &val_name, const QString &val)
{
    toCommit.append(QPair<QString,QString>(val_name,val));
}

template<typename T>
void DBInterface::setDBVal(const QString &val_name, T val)
{
    toCommit.append(QPair<QString,QString>(val_name,QString::number(val)));
}

QString DBInterface::getCommitString() {
    QString toRet="UPDATE "+tname+" SET " ;
    for(auto val : toCommit) {
        toRet+=val.first+"="+val.second+" ";
    }
    return toRet;
}
