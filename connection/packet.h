#ifndef PACKET_H
#define PACKET_H

#include <QObject>
#include <QTimer>
#include "integralcommand.h"
#include "settings.h"
class Packet : public QObject
{
    Q_OBJECT
    IntegralCommand *cmd;
    QByteArray header;
    QByteArray footer;
    bool deleteAfterResponse=false;
    QTimer timeoutTimer;
    QByteArray calculateCRC(const QByteArray &arr);
    QByteArray expandForSpecialValue(QByteArray &toEdit);
public:
    explicit Packet(IntegralCommand *command, QObject *parent = nullptr, bool deleteAfter=false);
    ~Packet();
    QByteArray getBytes();
    char getCode();
    QString getCmdName();
    int getResponseLength();

public slots:
    void responseReady(QByteArray &arr);
private slots:
    void timeoutHandler();
signals:
    void getResponse(const QList<int>& resp);
    void timeout(Packet* packet);
};

#endif // PACKET_H
