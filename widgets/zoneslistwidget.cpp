#include "zoneslistwidget.h"
#include "ui_zoneslistwidget.h"
#include "QDebug"

#include <dialogs/areyousuredialog.h>
QString ZonesListWidget::getInfoString() const
{
    return infoString;
}

int ZonesListWidget::getZonesCount() const
{
    return zonesCount;
}

ZonesListWidget::ZonesListWidget(QWidget *parent) :
    QWidget(parent),
    unarmed("Rozbrojona", QColor(142, 149, 156), 1),
    partArmed("Cz. uzbrojona", QColor(68, 115, 69), 2),
    armed("Uzbrojona", QColor(29, 153, 29), 3),
    silentAlarm("Cichy alarm", QColor(255,204,0), 4),
    alarm("Alarm", QColor(204,0,0), 5),
    disconnected("Odłączona", QColor(75, 77, 79), 0),
    controlls(this),
    ui(new Ui::ZonesListWidget)
{
    ui->setupUi(this);
    //StateHandler::enablePrioMode();
    StateHandler::addState(disconnected);
    StateHandler::addState(unarmed);
    StateHandler::addState(partArmed);
    StateHandler::addState(armed);
    StateHandler::addState(silentAlarm);
    StateHandler::addState(alarm);
    updateTimer = new QTimer();
    updateTimer->setInterval(settings.zonesUpdateTimeInMS.get());
    connect(updateTimer, &QTimer::timeout, this, &ZonesListWidget::updateStates);
    updateTimer->start();

    connect(ui->armBtn, &QPushButton::clicked, this, &ZonesListWidget::armHandle);
    connect(ui->dealarmBtn, &QPushButton::clicked, this, &ZonesListWidget::dealarmHandle);
    connect(ui->unarmBtn, &QPushButton::clicked, this, &ZonesListWidget::unarmHandle);
    setAuthorizationNeeded(false);

    controlls.addControlls({ui->armBtn,ui->unarmBtn, ui->dealarmBtn});
    ui->keyLineEdit->setEchoMode(QLineEdit::Password);
    Global::authorization->addInterface(this);
    AuthorizationInterface::addOnLogIn(ui->widget_3);

}

void ZonesListWidget::setupZones(const QStringList& names) {
    zonesCount = names.count();

    for(int i=0; i<zonesCount; i++) {
        Zone* zoneToAppend = new Zone(i+1, ui->contentWidget, names.at(i));
        zones.append(zoneToAppend);
        ui->contentLayout->addWidget(zoneToAppend);
        connect(zoneToAppend, &Zone::editZoneEmitted, this, &ZonesListWidget::editZoneEmited);
    }
}

ZonesListWidget::~ZonesListWidget()
{
    delete ui;
}

void ZonesListWidget::updateAlarms(const QList<int>& items)
{
    for(int i=0; i<zonesCount; i++) {
        bool isSet=false;
        foreach(int zoneAlarm, items) {
            if(i==zoneAlarm-1) isSet=true;
        }
        zones[i]->setAlarm(isSet);
    }
}

void ZonesListWidget::updateSilentAlarms(const QList<int>& items)
{
    for(int i=0; i<zonesCount; i++) {
        bool isSet=false;
        foreach(int zoneSilentAlarm, items) {
            if(i==zoneSilentAlarm-1) isSet=true;
        }
        zones[i]->setSilentAlarm(isSet);
    }
}

void ZonesListWidget::updateArm(const QList<int>& items)
{
    int armedCounter=0;
    for(int i=0; i<zonesCount; i++) {
        bool isSet=false;
        foreach(int zoneArm, items) {
            if(i==zoneArm-1) {
                isSet=true;
                armedCounter++;
            }
        }
        zones[i]->setArm(isSet);
    }
}

QStringList ZonesListWidget::getZonesNames() {
    QStringList toRet;
    foreach(auto zone, zones) {
        toRet.append(zone->getName());
    }
    return toRet;
}

void ZonesListWidget::setAuthorizationNeeded(bool auth)
{
    if(auth) {
        if(ui->keyLineEdit->text().isEmpty()) {
            controlls.disable();
        }
        ui->authWidget->show();
    } else {
        controlls.enable();
        ui->authWidget->hide();
    }
    authorizationNeeded=auth;
}

QString ZonesListWidget::getPassword() const {
    return ui->keyLineEdit->text();
}
void ZonesListWidget::updateStates()
{
    if(!connection) {
        if(setState(disconnected)) {
            infoString="Brak połączenia.";
            emit(stateChanged(&disconnected, QList<Zone*>()));
        }
        return;
    }
    QList<Zone*> armedList, unarmedList, alarmList, silentList;
    foreach(auto zone, zones) {
        if(zone->isAlarm()) alarmList.append(zone);
        if(zone->isSilent()) silentList.append(zone);
        if(zone->isArmed()) armedList.append(zone);
        else unarmedList.append(zone);
    }
    infoString="";
    //infoString+=getCurrentStateName()+"\n\n";
    if(alarmList.count()>0) {
        QString helpString="";
        foreach(auto alarmZ, alarmList) {
            helpString+=alarmZ->getId()+" ";
        }
        infoString+="Alarm w: "+helpString+"\n";
        if(setState(alarm)) {
            //NOTIFICATION INDICATING ALARM STATE
            emit(stateChanged(&alarm, alarmList));
        }
    } else if(getPrevState()==&alarm) {
        //CANCEL ALARM NOTIFICATION
    }
    if(silentList.count()>0) {
        QString helpString="";
        foreach(auto alarmZ, silentList) {
            helpString+=alarmZ->getId()+" ";
        }
        infoString+="Cichy alarm w: "+helpString+"\n";
        if(alarmList.count()==0) {
            if(setState(silentAlarm)) {
                //NOTIFICATION INDICATING SILENT STATE
                emit(stateChanged(&silentAlarm, silentList));
            }
        }
    } else if(getPrevState()==&silentAlarm) {
        //CANCEL SILENT NOTIFICATION
    }
    if(alarmList.count()==0 && silentList.count()==0) {
        if(unarmedList.count()==0) {
            infoString+="Wszystkie strefy uzbrojone.\n";
            if(setState(armed)) {
                emit(stateChanged(&armed, armedList));
            }
        }
        else if(armedList.count()>0) {
            QString helpString="";
            foreach(auto armedZone, armedList) {
                helpString+=armedZone->getId()+" ";
            }
            infoString+="Uzbrojone strefy: "+helpString+"\n";
            if(setState(partArmed)) {
                emit(stateChanged(&partArmed, armedList));
            }

        }
        else if(setState(unarmed)) {
            qDebug()<<"unarmed";
            infoString+="Wszystkie strefy są nieuzbrojone.\n";
            emit(stateChanged(&unarmed, unarmedList));
        }
    }
}

void ZonesListWidget::connectionLost(bool isLost) {connection=!isLost;}

void ZonesListWidget::armHandle_ok()
{
    emit(arm(zones));
    ui->keyLineEdit->setText("");//Resseting password
}

void ZonesListWidget::dealarmHandle_ok()
{
    emit(dealarm(zones));
    ui->keyLineEdit->setText("");//Resseting password
}

void ZonesListWidget::unarmHandle_ok()
{
    emit(unarm(zones));
    ui->keyLineEdit->setText("");//Resseting password
}

void ZonesListWidget::armHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz uzbroić wszystkie strefy?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZonesListWidget::armHandle_ok);
}

void ZonesListWidget::dealarmHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz skasować alarmy we wszystkich strefach?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZonesListWidget::dealarmHandle_ok);
}

void ZonesListWidget::unarmHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz rozbroić wszystkie strefy?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZonesListWidget::unarmHandle_ok);
}

void ZonesListWidget::on_addZoneBtn_clicked()
{
    zonesCount++;
    Zone* zoneToAppend = new Zone(zonesCount, ui->contentWidget, "Strefa "+QString::number(zones[zonesCount-2]->getId().toUInt()+1));
    zones.append(zoneToAppend);
    ui->contentLayout->addWidget(zoneToAppend);
    connect(zoneToAppend, &Zone::editZoneEmitted, this, &ZonesListWidget::editZoneEmited);
}

void ZonesListWidget::on_subZoneBtn_clicked()
{
    if(zonesCount<2) return;
    zonesCount--;
    ui->contentLayout->removeWidget(zones.last());
    auto backup = zones.last();
    zones.removeLast();
    delete backup;
    emit(updateDB());
}

void ZonesListWidget::on_keyLineEdit_textChanged(const QString &arg1)
{
    if(authorizationNeeded) {
        if(arg1.count()>0)
            controlls.enable();
        else
            controlls.disable();
    }
}
