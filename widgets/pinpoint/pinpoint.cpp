#include "pinpoint.h"
#include "ui_pinpoint.h"

#include <interfaces/fastproxystyle.h>


Connection& PinPoint::getConnection()
{
    return connection;
}

int PinPoint::getId() const
{
    return id;
}

void PinPoint::setId(int value)
{
    id = value;
    getConnection().setID(id);
}

PinPoint::PinPoint(QWidget *parent) :
    QWidget(parent),
    connection(nullptr),
    ui(new Ui::PinPoint)
{
    ui->setupUi(this);
    this->layout()->setAlignment(ui->label, Qt::AlignCenter);
    connect(ui->pin, &PointShape::mouseOver, this, &PinPoint::mouseOverPin);
    connect(&connection, &Connection::currentStateUpdated, this, &PinPoint::updateState);
    connect(&connection, &Connection::updateView, this, &PinPoint::updateView);
    connect(&connection.getZonesWidget(), &ZonesListWidget::updateDB, this, &PinPoint::onUpdateEmit);
    this->setStyle(new FastProxyStyle(this->style())); //Set tip style
    setupShadow(this, QPoint(3,3), 10); // Add shadow
    ui->label_2->hide(); //Hide IP on init
}

void PinPoint::fillSetup(const QString& address, const QString& name) {
    setIP(address);
    setName(name);
    connection.setConnectionData(getIP(), 7094);
}

void PinPoint::updateState(CustomState *state, QList<Zone*> source){
    if(!source.isEmpty()) {
        if(state==&connection.getZonesWidget().alarm || state==&connection.getZonesWidget().silentAlarm) {
            QString helpString="";
            foreach(auto item, source) {
                helpString+=item->getId()+" ";
            }
        }
    }

    ui->pin->setState(*state);
    refreshHint();
}

void PinPoint::updateView(const QHostAddress& address, uint16_t port)
{
    ui->label_2->setText(address.toString());
    Q_UNUSED(port)
}

void PinPoint::onUpdateEmit()
{
    emit(updateDatabase(*this));
}

void PinPoint::setPos(const QPointF &pos) {
    position = pos;
    this->move(Converter::toPointToMiddle(position, size()));
}

bool PinPoint::isFakeElement()
{
    return (getIP().toString()=="0.0.0.0");
}

void PinPoint::mouseOverPin(){
    raise();
    if(!isFakeElement())
        emit mouseOverMe();
}

void PinPoint::setName(const QString &text)
{
    ui->label->setText(text);
}
void PinPoint::refreshHint() {
    this->setToolTip("Nazwa: "+ui->label->text()+"\nIP: "+this->getIP().toString()+"\n"+connection.getZonesWidget().getInfoString());
}
void PinPoint::setIP(const QString& ip)
{
    connection.setCentralAddress(QHostAddress(ip));
    ui->label_2->setText(ip);
    refreshHint();
}
void PinPoint::enterEvent(QEvent *event)
{
    ui->label_2->show();
    QWidget::enterEvent(event);
    QWidget::adjustSize();
}

void PinPoint::leaveEvent(QEvent *event)
{
    ui->label_2->hide();
    QWidget::leaveEvent(event);
    QWidget::adjustSize();
}

void PinPoint::mouseReleaseEvent(QMouseEvent *event)
{
    emit(setupDeclared());
}

PinPoint::~PinPoint(){delete ui;}
QPointF PinPoint::getPos() {return position;}
QString PinPoint::getText() {return this->ui->label->text();}
QString PinPoint::getStateString(){return ui->pin->getStateString();}
QHostAddress PinPoint::getIP(){return connection.getCentralAddress();}
