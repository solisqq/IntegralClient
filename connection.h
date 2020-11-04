#ifndef CONNECTIONN_H
#define CONNECTIONN_H

#include <QHostAddress>
#include <QTcpSocket>
#include <QWidget>
#include <QDateTime>
#include <QCheckBox>
#include <dialogs/zoneeditdialog.h>
#include <widgets/mapwidget.h>
#include "connection/packet.h"
#include "connection/terminaldialog.h"
#include "connection/integralcommand.h"
#include "handlers/errorHandler/errorable.h"
#include "handlers/errorHandler/error.h"
#include "settings.h"
#include "widgets/zoneslistwidget.h"

namespace Ui {
class Connection;
}

class Connection : public QWidget, public ErrorAble, public AuthorizationInterface
{
    Q_OBJECT
    QTcpSocket *socket = nullptr;
    QHostAddress centralAddress;
    uint16_t centralPort=1313;
    TerminalDialog *tdialog;
    QList<Packet*> packetsList;
    QTimer updateTimer;
    QDateTime previousIncomeDate;
    Packet getZonesViolation;
    Packet zonesAlarm;
    Packet versionPacket;
    Packet getZonesViolationMem;
    Packet getZonesArmed;
    Packet getInputStates;
    Packet getMalfunctions;
    QList<QCheckBox*> checkBoxes;
    QString bgPath="";
    ZoneEditDialog *zoneDialog=nullptr;
    int syncPacketCounter=0;
    Database *database=nullptr;
    int dbID=0;

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();
    void Send(Packet *packetToSend);
    bool isDataInitialized();
    QHostAddress getCentralAddress() const;
    uint16_t getCentralPort() const;
    void setCentralPort(const uint16_t &value);
    void setCentralAddress(const QHostAddress &value);
    void setPassword(const QString&);
    QString getPassword() const;
    ZonesListWidget& getZonesWidget();
    MapWidget &getMapWidget();
    void updateDataFromGUI();
    void setBackgroundID(int id);
    void setDatabase(Database *value);
    Database *getDatabase() const;
    void setID(int id);

signals:
    void updateView(QHostAddress ip, uint16_t port);
    void currentStateUpdated(CustomState* state, QList<Zone*> source);

public slots:
    void setConnectionData(const QHostAddress &address, uint16_t port);

private slots:
    void setVersion(int ver);
    void checkState();
    void showZoneEditDialog(Zone* zone);
    void onArmRequest(const QList<Zone*>& zones);
    void onAlarmOffRequest(const QList<Zone*>& zones);
    void onUnarmRequest(const QList<Zone*>& zones);
    void handlePacketLost(Packet* packet);

    void on_pushButton_clicked();

private:
    Ui::Connection *ui;
    bool isAuthorizeNeeded();
    QString getAuthenticationPassword();
    void handleConnectionLost();
    QList<int> intListFromString(const QString& str, char splitter);
};

#endif // CONNECTIONN_H
