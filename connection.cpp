#include "connection.h"
#include "ui_connection.h"
#include "handlers/errorHandler/errorstatus.h"

#include <DBRequest.h>
#include <QDirIterator>

#include <dialogs/infodialog.h>

#include <widgets/malfunctionwidget.h>

Connection::Connection(QWidget *parent) :
    QWidget(parent),
    centralAddress("0.0.0.0"),
    updateTimer(this),
    getZonesViolation(new IntegralCmds::ReadZonesViolation(this), this, false),
    zonesAlarm(new IntegralCmds::ReadZoneAlarms(this), this, false),
    versionPacket(new IntegralCmds::GetVersion(this), this, false),
    getZonesViolationMem(new IntegralCmds::ReadZonesAlarmsMemory(this),this,false),
    getZonesArmed(new IntegralCmds::ReadArmedZones(this),this,false),
    getInputStates(new IntegralCmds::ReadInputStates(this),this,false),
    getMalfunctions(new IntegralCmds::ReadMalfunctions(this), this, false),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    tdialog = new TerminalDialog(this);
    socket = new QTcpSocket(this);

    ui->mapComboBox->addItems(getMapWidget().getAvailableBackgrounds());
    connect(ui->mapComboBox, SIGNAL(currentIndexChanged(int)), ui->contenttWidget, SLOT(setBackground(int)));

    //setBarStyle(false);
    updateTimer.setInterval(settings.packetSenderUpdateInMS.get());
    connect(&updateTimer, &QTimer::timeout, this, &Connection::checkState);
    //connect(&versionPacket, &Packet::getResponse, this, &Connection::setVersion);

    //Przekaż dane z odpowiedzi serwera do odpowiednich metod aktulizujących stan systemu
    /*connect(&getZonesViolationMem, &Packet::getResponse, ui->zonesListWidget, &ZonesListWidget::updateAlarms);
    connect(&getZonesArmed, &Packet::getResponse, ui->zonesListWidget, &ZonesListWidget::updateArm);
    connect(&getInputStates, &Packet::getResponse, ui->contenttWidget, &MapWidget::updateInputStatus);
    connect(&getMalfunctions, &Packet::getResponse, &getMapWidget().getMalfunctionWidget(), &MalfunctionWidget::setStates);*/

    //Obsługa zgubienia pakietu
    /*connect(&getZonesViolationMem, &Packet::timeout, this, &Connection::handlePacketLost);
    connect(&getZonesArmed, &Packet::timeout, this, &Connection::handlePacketLost);
    connect(&getInputStates, &Packet::timeout, this, &Connection::handlePacketLost);*/

    connect(this->ui->zonesListWidget, &ZonesListWidget::stateChanged, this, &Connection::currentStateUpdated);
    updateTimer.start();

    connect(ui->zonesListWidget, &ZonesListWidget::arm, this, &Connection::onArmRequest);
    connect(ui->zonesListWidget, &ZonesListWidget::unarm, this, &Connection::onUnarmRequest);
    connect(ui->zonesListWidget, &ZonesListWidget::dealarm, this, &Connection::onAlarmOffRequest);
    connect(ui->zonesListWidget, &ZonesListWidget::editZoneEmited, this, &Connection::showZoneEditDialog);

    Global::authorization->addInterface(this);
    AuthorizationInterface::addOnLogIn({ui->connectBtn, ui->ipLineEdit, ui->portLineEdit, ui->terminalBtn, ui->mapComboBox, ui->passLineEdit, ui->ipLabel, ui->kodLabel, ui->portLabel, ui->mapLabel});

    if(getPassword().isEmpty())//Niezbędna autoryzacja jeżeli hasło połączenia jest puste (instalator nie wprowadził)
        ui->zonesListWidget->setAuthorizationNeeded(true);
    ui->pushButton->hide();
}

void Connection::Send(Packet *packetToSend) {
    qDebug()<<packetToSend->getBytes();
    if(!packetsList.contains(packetToSend)) packetsList.append(packetToSend);

    /*if(socket->state()==QAbstractSocket::ConnectedState) {
        QByteArray toSend = packetToSend->getBytes();
        socket->write(toSend);
        tdialog->updateTerminal(TerminalDialog::Source::Out, toSend, packetToSend->getCmdName()); //MEMTEST
        if(!packetsList.contains(packetToSend))
            packetsList.append(packetToSend);
    }*/
}

void Connection::updateDataFromGUI() {
    if(!centralAddress.setAddress(ui->ipLineEdit->text())) return;
    centralPort = ui->portLineEdit->text().toUInt();
}

void Connection::setBackgroundID(int id)
{
    getMapWidget().setBackground(id);
    ui->mapComboBox->setCurrentIndex(id);
}

void Connection::checkState()
{
    QSqlQueryModel *model = getDatabase()->getUpdate(dbID);
    if(model->record(0).value(3).toString()!="1") handleConnectionLost();
    else ui->zonesListWidget->connectionLost(false);
    ui->zonesListWidget->updateArm(intListFromString(model->record(0).value(1).toString(), ','));
    ui->zonesListWidget->updateAlarms(intListFromString(model->record(0).value(0).toString(), ','));
    getMapWidget().getMalfunctionWidget().setStates(intListFromString(model->record(0).value(2).toString(),','));
    getMapWidget().updateInputStatus(intListFromString(model->record(0).value(3).toString(),','));

}

QList<int> Connection::intListFromString(const QString& str, char splitter) {
    QStringList splitted = str.split(splitter);
    QList<int> toRet;
    for(auto numberStr : splitted) {
        toRet.append(numberStr.toInt());
    }
    return toRet;
}

void Connection::handleConnectionLost() {
    //emit(currentStateUpdated(&ui->zonesListWidget->disconnected,QList<Zone*>()));//HERE
    emit(currentStateUpdated(&ui->zonesListWidget->disconnected,QList<Zone*>()));
    ui->zonesListWidget->connectionLost(true);
    //setBarStyle(false);
    ui->zonesListWidget->updateAlarms(QList<int>());
    ui->zonesListWidget->updateArm(QList<int>());
    /*makeConnection();*/
}

Connection::~Connection()
{
    delete ui;
}

void Connection::setVersion(int ver)
{
    getMapWidget().setInputsCount(ver);
    ui->versionLabel->setText(QString::number(ver));
}

void Connection::setConnectionData(const QHostAddress& address, uint16_t port) {
    setCentralAddress(address);
    setCentralPort(port);
}

Database *Connection::getDatabase() const
{
    return database;
}

void Connection::setID(int id)
{
    dbID=id;
    this->setVersion(database->getVersion(id));
}

void Connection::setDatabase(Database *value)
{
    database = value;
}

ZonesListWidget &Connection::getZonesWidget()
{
    return *ui->zonesListWidget;
}

MapWidget &Connection::getMapWidget()
{
    return *ui->contenttWidget;
}

bool Connection::isDataInitialized() {
    return (centralPort!=1313);
}

QHostAddress Connection::getCentralAddress() const
{
    return centralAddress;
}

uint16_t Connection::getCentralPort() const
{
    return centralPort;
}

void Connection::setCentralPort(const uint16_t &value)
{
    centralPort = value;
    ui->portLineEdit->setText(QString::number(value));
}

void Connection::setCentralAddress(const QHostAddress &value)
{
    centralAddress = value;
    ui->ipLineEdit->setText(value.toString());
}

void Connection::setPassword(const QString &passwordToSet)
{
    ui->passLineEdit->setText(passwordToSet);
    if(!passwordToSet.isEmpty()) ui->zonesListWidget->setAuthorizationNeeded(false);
    else ui->zonesListWidget->setAuthorizationNeeded(true);
}

QString Connection::getPassword() const {
    return ui->passLineEdit->text();
}

void Connection::onArmRequest(const QList<Zone *> &zones)
{
    QString pass = getAuthenticationPassword();
    if(pass=="") return; //Jeżeli nigdzie nie podano hasło (przez instalatora i przez użytkownika)
    QList<int> partitionsToArm;
    foreach(auto zone, zones) {
        partitionsToArm.append(zone->getId().toUInt()-1);
    }
    DBRequest::create(DBRequest::CMD::arm, dbID, partitionsToArm, pass);
}

void Connection::onAlarmOffRequest(const QList<Zone *> &zones)
{
    QString pass = getAuthenticationPassword();
    if(pass=="") return; //Jeżeli nigdzie nie podano hasło (przez instalatora i przez użytkownika)
    QList<int> partitionsToArm;
    foreach(auto zone, zones) {
        partitionsToArm.append(zone->getId().toUInt()-1);
    }
    DBRequest::create(DBRequest::CMD::alarm_off, dbID, partitionsToArm, pass);
}

void Connection::onUnarmRequest(const QList<Zone *> &zones)//Rozwiązać
{
    QString pass = getAuthenticationPassword();
    if(pass=="") return; //Jeżeli nigdzie nie podano hasło (przez instalatora i przez użytkownika)
    QList<int> partitionsToArm;
    foreach(auto zone, zones) {
        partitionsToArm.append(zone->getId().toUInt()-1);
    }
    DBRequest::create(DBRequest::CMD::disarm, dbID, partitionsToArm, pass);
}

QString Connection::getAuthenticationPassword() {
    QString password = "";
    if(isAuthorizeNeeded()) {
        if(ui->zonesListWidget->getPassword().isEmpty()) {
            auto dialog = new InfoDialog(InfoDialog::Type::Warning, "Brak autoryzacji", "Brak autoryzacji do zmiany stanu centrali. Podaj klucz dostępu w polu pod przyciskami kontrolnymi centrali (uzbrój, rozbrój, kas. alarm).", nullptr, true);
            dialog->show();
            return "";
        }else return ui->zonesListWidget->getPassword();
    } else return getPassword();
}

void Connection::showZoneEditDialog(Zone *zone)
{
    zoneDialog = new ZoneEditDialog(zone, this);
    zoneDialog->show();
    connect(zoneDialog, &ZoneEditDialog::armEmited, this, &Connection::onArmRequest);
    connect(zoneDialog, &ZoneEditDialog::unarmEmited, this, &Connection::onUnarmRequest);
    connect(zoneDialog, &ZoneEditDialog::alarmOffEmited, this, &Connection::onAlarmOffRequest);
}

bool Connection::isAuthorizeNeeded() {
    return (getPassword().count()<1);
}

void Connection::handlePacketLost(Packet *packet)
{
    Q_UNUSED(packet)
}


void Connection::on_pushButton_clicked()
{
    //generateError(testError);
    auto dial = new InfoDialog(InfoDialog::Error, "cos", "cos2");
    dial->show();
}
