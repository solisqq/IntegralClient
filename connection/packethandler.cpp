#include "packethandler.h"
#include "ui_packethandler.h"

PacketHandler::PacketHandler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PacketHandler)
{
    ui->setupUi(this);
}

PacketHandler::~PacketHandler()
{
    delete ui;
}
