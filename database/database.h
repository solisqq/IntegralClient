#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QFileInfo>
#include "settings.h"
#include <widgets/inputs.h>
#include <QSqlDatabase>

class Database : public QObject
{
    Q_OBJECT
    QSqlDatabase db;
public:
    explicit Database(QObject *parent = nullptr);
    QSqlQueryModel *getModelByName(const QString &name, int startsEndsWith = 0);
    QSqlQueryModel *getAllIntegrals();
    void removeIntegral(int id);
    int addIntegral(const QString &name, const QString &ip, qreal posx, qreal posy, int imgId, const QStringList &zones, const QString& pass);
    QSqlQueryModel *getModel(const QString &text);
    int addInput(Inputs &input, int connectionID, const QPointF& pos);
    QSqlQueryModel *getAllInputs(int id);
    QSqlDatabase getDb() const;
    void logData(const QDateTime &date, const QString &msg);
    QSqlQueryModel *getUpdate(int id);
    int getVersion(int id);
    QSqlQueryModel *getAllErrors();
    void updateSingleValueIn(const QString &dbName, const QString &valName, const QString &value, int id);
public slots:
    void updateIntegral(int id, const QString &name, const QString &ip, int imgId, const QStringList &zones, const QString& pass);
    void updateInput(Inputs &input);
signals:

};

//extern Database database;

#endif // DATABASE_H
