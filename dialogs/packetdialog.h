#ifndef PACKETDIALOG_H
#define PACKETDIALOG_H

#include <QDialog>

#include <connection/packet.h>

namespace Ui {
class PacketDialog;
}

class PacketDialog : public QDialog
{
    Q_OBJECT
    Packet getZonesViolation;
    Packet zonesAlarm;
    Packet versionPacket;
    Packet getZonesViolationMem;
    QList<Packet*> staticDialogs;
public:
    explicit PacketDialog(QWidget *parent = nullptr);
    ~PacketDialog();

private:
    Ui::PacketDialog *ui;

signals:
    //void violationDetected(QList<int>&, Packet* violationPacket, )
};

#endif // PACKETDIALOG_H
