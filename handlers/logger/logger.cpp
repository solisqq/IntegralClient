#include "../fileparser/fileparser.h"
#include "logger.h"

#include <QDir>
#include <QSqlQuery>

Logger::Logger():
    MenuElement(":/icons/img/data2.png", nullptr, "Log danych")
{
}

Logger::~Logger()
{
}

void Logger::add(Error &error)
{
    logData(QDateTime::currentDateTime(), error.getString());
        //FileParser::Save(fileName, error.getString(),true);
}

void Logger::add(const QString &msg, const QString &source) {
    logData(QDateTime::currentDateTime(), "Wykryto zdarzenie w "+ source +". Treść: "+msg);
}

void Logger::logData(const QDateTime &date, const QString &msg)
{
    QSqlQuery querry;
    querry.exec("""INSERT INTO log (date,msg) VALUES ('"""+date.toString("yyyy-MM-dd hh:mm:ss")+"""','"""+msg+"""');""");
}

QWidget *Logger::getView()
{
    return nullptr;
}




