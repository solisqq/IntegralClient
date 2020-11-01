#include "copyprotection.h"
#include <QStringList>
#include <QDebug>
QString CopyProtection::unhash(QString target, bool switchMult)
{
    QString unhashed="";
    QStringList splitted = target.split('|');
    if(splitted.count()<3) return "";
    bool valid = false;
    int mult2 = splitted.at(0).toInt(&valid)/16;//7
    if(valid==false || mult2==0) return "";
    int mult1 = splitted.last().toInt(&valid)/22;//8
    if(valid==false || mult1==0) return "";
    splitted.pop_back();
    splitted.pop_front();

    if(switchMult) { int backup = mult1; mult1 = mult2; mult2=backup;}

    for(int i=splitted.count()-1; i>=0; i--) {
        int value=splitted.at(i).toInt();
        if(value%2==0) value-=2;
        if(i%2==0) value/=mult1;
        else value/=mult2;
        unhashed += QString(QChar(value));
    }
    return unhashed;
}

QString CopyProtection::hash(QString target, int& mult1, int& mult2)
{
    QString hashed="";
    mult1 = (rand()%8)+1;
    mult2 = mult1;
    while(mult2==mult1) {
        mult2 = (rand()%8)+1;
    }
    for(int i=target.count()-1; i>=0; i--) {
        int value = target.at(i).toLatin1();
        if(i%2==0)value*=mult1;
        else value*=mult2;
        if(value%2==0) value+=2;
        hashed += QString::number(value)+'|';
    }
    hashed.push_front(QString::number(mult2*16)+'|');
    hashed+=QString::number(mult1*22);
    return hashed;
}
