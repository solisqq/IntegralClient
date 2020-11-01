#include "fileparser.h"

#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <settings.h>

bool FileParser::Load(const QString &name, QList<QStringList> &source)
{
    QFile file(name);
    if(!file.open(QIODevice::ReadOnly)){return false;}
    QTextStream in(&file);
    QStringList init;
    init.append(name);
    source.append(init);

    for(int i=0; !in.atEnd(); i++) {
        QString line = in.readLine();
        QStringList list;
        list.append(line.split(","));
        source.append(list);
    }
    return true;
}

bool FileParser::Save(const QString &path, const QString &toSend, bool append) {
    QFile file(path);
    bool isOpen = false;
    if(!append)
        isOpen = file.open(QIODevice::WriteOnly);
    else
        isOpen = file.open(QIODevice::WriteOnly | QIODevice::Append);

    if(!isOpen) return false;
    QTextStream stream(&file);
    stream<<toSend;
    return true;
}
