#include "database.h"
#include <utils/converter.h>
#include <dialogs/infodialog.h>

QSqlDatabase Database::getDb() const
{
    return db;
}

Database::Database(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(settings.dbpath.get());
    db.setDatabaseName("main");
    db.setUserName("postgres");
    db.setPort(5432);
    db.setPassword("root");
    if(!db.open()){
        auto problemDialog = new InfoDialog(InfoDialog::Warning, "Baza danych", "Aplikacja napotkała na problem z połączeniem z bazą danych", nullptr, true);
        problemDialog->show();
        qDebug()<<"There is a problem with database.";
    }

}

int Database::addIntegral(const QString& name, const QString& ip, qreal posx, qreal posy, int imgId, const QStringList& zones, const QString& pass)
{
    QSqlQuery querry;
    QString zonesString = "";
    foreach(auto zone, zones) {
        zonesString+=zone+",";
    }
    zonesString.chop(1);
    querry.exec("""INSERT INTO integrals (name,ip,posx,posy,image,zones,pass) VALUES ('"""+name+"""','"""+ip+"""','"""+QString::number(posx)+"""','"""+QString::number(posy)+"""','"""+QString::number(imgId)+"""','"""+zonesString+"""', '"""+pass+"""') RETURNING id;""");
    querry.next();
    return querry.value(0).toInt();
}

void Database::updateIntegral(int id, const QString& name, const QString& ip, int imgId, const QStringList& zones, const QString& pass)
{
    QSqlQuery querry;
    QString zonesString = "";
    foreach(auto zone, zones) {
        zonesString+=zone+",";
    }
    zonesString.chop(1);
    querry.exec("""UPDATE integrals SET name='"""+name+"""', ip='"""+ip+"""', image='"""+QString::number(imgId)+"""', zones='"""+zonesString+"""', pass='"""+pass+"""' WHERE id="""+QString::number(id)+""";""");
}

void Database::updateInput(Inputs& input) {
    QSqlQuery querry;
    querry.exec("""UPDATE inputs SET name='"""+
                input.getName()+"""', inputid="""+
                QString::number(input.getInputID())+""", type="""+
                QString::number(static_cast<int>(input.getSensorType()))+""" WHERE id="""+QString::number(input.getDbID())+""";""");
}

void Database::updateSingleValueIn(const QString& dbName, const QString& valName, const QString& value, int id) {
    QSqlQuery querry;
    querry.exec("""UPDATE """+dbName+""" SET """+valName+"""="""+value+""" WHERE id="""+QString::number(id)+""";""");
}

int Database::addInput(Inputs &input, int connectionID, const QPointF& pos)
{
    QSqlQuery querry;
    querry.exec("""INSERT INTO inputs (name,inputid,connectionid,posx,posy,type) VALUES ('"""+
                input.getName()+"""','"""+
                QString::number(input.getInputID())+"""','"""+
                QString::number(connectionID)+"""','"""+
                QString::number(pos.x())+"""','"""+
                QString::number(pos.y())+"""','"""+
                QString::number(static_cast<int>(input.getSensorType()))+"""') RETURNING id;""");
    querry.next();
    return querry.value(0).toInt();
}

void Database::removeIntegral(int id)
{
    QSqlQuery querry;
    querry.exec("""DELETE FROM integrals WHERE id="""+QString::number(id)+""";""");
}

QSqlQueryModel* Database::getModelByName(const QString& name, int startsEndsWith) {
    auto toRet = new QSqlQueryModel();
    auto qry = new QSqlQuery(db);
    if(startsEndsWith==0) {
        qry->prepare("""select * from integrals WHERE value='"""+name+"""';""");
    } else if(startsEndsWith==1) {

    } else if(startsEndsWith>=2) {

    }
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

QSqlQueryModel *Database::getModel(const QString& text)
{
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("""select * from integrals WHERE"""+text);
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

QSqlQueryModel *Database::getAllIntegrals()
{
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("select * from integrals");
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

QSqlQueryModel *Database::getAllErrors()
{
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("select * from public.active_errors");
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

QSqlQueryModel *Database::getAllInputs(int id)
{
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("select * from inputs WHERE connectionid="+QString::number(id)+";");
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

QSqlQueryModel *Database::getUpdate(int id) {
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("select alarm_list, armed_list, malf_list, conn, input_states from integrals WHERE id="+QString::number(id)+";");
    qry->exec();
    toRet->setQuery(*qry);
    return toRet;
}

int Database::getVersion(int id) {
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("select ver from integrals WHERE id="+QString::number(id)+";");
    qry->exec();
    toRet->setQuery(*qry);
    return toRet->record(0).value(0).toInt();
}
