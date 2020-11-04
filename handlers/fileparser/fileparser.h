#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QFile>

class FileParser
{
public:
    static bool Load(const QString &name, QList<QStringList> &source);
    static bool Save(const QString &path, const QString &toSend, bool append=false);
signals:

public slots:
};

#endif // FILEPARSER_H
