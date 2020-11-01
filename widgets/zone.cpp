#include "zone.h"
#include "ui_zone.h"
#include "QDebug"

#include <QMouseEvent>
Zone::Zone(int id, QWidget *parent, const QString& name) :
    QWidget(parent),
    unarmed("Nie uzbrojona", QColor(242,242,242), 0),
    armed("Uzbrojona", QColor(102,255,51), 1),
    alarm("Alarm", QColor(204,0,0), 3),
    silentAlarm("Cichy alarm", QColor(255,204,0), 2),
    ui(new Ui::Zone)
{
    ui->setupUi(this);
    setId(id);
    if(name.count()<2) setName("Strefa "+QString::number(id));
    else setName(name);

    StateHandler::enableDualMode();
    StateHandler::addState(unarmed);
    StateHandler::addState(armed);
    StateHandler::addState(alarm);
    StateHandler::addState(silentAlarm);

    unarmed.setState(true);
    updateGUI();
}


bool Zone::setAlarm(bool _state)
{
    if(StateHandler::setState(alarm, _state)==0 && _state) {
        updateGUI();
        return true;
    }
    return false;
}

bool Zone::setSilentAlarm(bool _state)
{
    if(StateHandler::setState(silentAlarm, _state)==0 && _state) {
        updateGUI();
        return true;
    }
    return false;
}

bool Zone::setArm(bool _state)
{
    if((StateHandler::setState(armed, _state)==0 && _state) || (StateHandler::setState(unarmed, !_state)==0 && !_state)) {
        updateGUI();
        return true;
    }
    return false;
}

void Zone::updateGUI() {
    this->ui->stateWidget->setStyleSheet("border: 5px solid rgb(31, 34, 68); border-radius:8px;  background-color:"+getCurrentState()->getColor().name()+";");
    ui->stateLabel->setText(getCurrentStateName());
}


void Zone::setId(int id)
{
    ui->idLabel->setText(QString::number(id));
}

QString Zone::getId() {
    return ui->idLabel->text();
}

void Zone::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        emit(editZoneEmitted(this));

}
void Zone::setName(const QString& name) {
    ui->nameLabel->setText(name);
}

QString Zone::getName() {
    return ui->nameLabel->text();
}

bool Zone::isAlarm()
{
    return alarm.isEnabled();
}

bool Zone::isSilent()
{
    return silentAlarm.isEnabled();
}

bool Zone::isArmed()
{
    return armed.isEnabled();
}
Zone::~Zone(){delete ui;}
