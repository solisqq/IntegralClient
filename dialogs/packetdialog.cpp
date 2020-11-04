#include "packetdialog.h"
#include "ui_packetdialog.h"

PacketDialog::PacketDialog(QWidget *parent) :
    QDialog(parent),
    getZonesViolation(new IntegralCmds::ReadZonesViolation(this), this, false),
    zonesAlarm(new IntegralCmds::ReadZoneAlarms(this), this, false),
    versionPacket(new IntegralCmds::GetVersion(this), this, false),
    getZonesViolationMem(new IntegralCmds::ReadZonesAlarmsMemory(this),this,false),
    ui(new Ui::PacketDialog)
{
    ui->setupUi(this);
}

PacketDialog::~PacketDialog()
{
    delete ui;
}
