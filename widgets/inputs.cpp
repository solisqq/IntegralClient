#include "inputs.h"
#include "ui_inputs.h"

#include <utils/converter.h>

int Inputs::getInputID() const
{
    return inputID;
}

void Inputs::setInputID(int value)
{
    inputID = value;
    updateName(name);
}

QString Inputs::getName() const
{
    return name;
}

QPointF Inputs::getPosition() const
{
    return position;
}

int Inputs::getDbID() const
{
    return dbID;
}

void Inputs::setDbID(int value)
{
    dbID = value;
}

Inputs::Inputs(const QString _name, int _id, QWidget *parent) :
    QWidget(parent),
    StateHandler(),
    alarm("Alarm", QColor(204,0,0)),
    ok("Ok", QColor(102,255,51)),
    ui(new Ui::Inputs)
{
    ui->setupUi(this);
    updateName(_name);
    setState(ok);
    setInputID(_id);
    setSensorType(Type::Common);
    offsets.setX(0);
    offsets.setY(0);
}

Inputs::Type Inputs::getSensorType() const
{
    return sensorType;
}

void Inputs::setSensorType(const Type &value)
{
    sensorType = value;
}

void Inputs::updateGui() {
    ui->indicator->setStyleSheet("font-size: 5px; padding:0; margin: 0;"
                                 "border: 3px solid rgb(31, 34, 68);"
                                 "border-radius:12px;"
                                 "background-color: "+ getCurrentStateColor().name()+ ";"
                );
}

void Inputs::updateName(const QString& newName) {
    name=newName;
    ui->nameLabel->setText(newName/*+" ("+QString::number(getInputID())+")"*/);
    setPos(position,14);
}

void Inputs::setPos(const QPointF &pos, qreal xoffset, qreal yoffset) {
    position = pos;
    if(xoffset<-0.1 || xoffset>0.1 || yoffset<-0.1 || yoffset>0.1) offsets = QPointF(xoffset,yoffset);
    QPointF point = Converter::toPointToMiddle(QPointF(position.x(),position.y()), size());
    this->move(static_cast<int>(point.x()-(name.count()+6)+offsets.x()),static_cast<int>(point.y()+6-offsets.y()));
}

bool Inputs::setState(CustomState &stateToChange, bool dualState)
{
    Q_UNUSED(dualState)
    bool resp = StateHandler::setState(stateToChange);
    if(resp) updateGui();
    return resp;
}

bool Inputs::setAlarm(bool alarmState) {
    bool resp;
    if(alarmState) resp=setState(alarm);
    else resp=setState(ok);
    if(resp && alarmState) emit(alarmEmited());
    if(resp && !alarmState) emit(noAlarmEmited());
    return resp;
}

void Inputs::setup(const QString &_name, int id, int type)
{
    updateName(_name);
    setInputID(id);
    setSensorType(static_cast<Type>(type));
    emit(saveMe(*this));
}

Inputs::~Inputs()
{
    delete ui;
}

void Inputs::on_indicator_clicked()
{
    emit(editEmited(*this));
}
