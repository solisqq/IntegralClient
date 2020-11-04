#include "pointshape.h"
#include "settings.h"
#include "ui_pointshape.h"
#include <QPainter>
#include <QDebug>
#include "utils/converter.h"


PointShape::PointShape(QWidget *parent) :
    QWidget(parent),
    defaultState("Unknown state", QColor(0,0,0)),
    ui(new Ui::PointShape)
{
    ui->setupUi(this);
    state=&defaultState;
    alarmTimer = new QTimer(this);

}

void PointShape::paintEvent(QPaintEvent *event)
{

    QWidget::paintEvent(event);
    /*QPainter painter(this);
    painter.setBrush(QBrush(state->getColor(), Qt::BrushStyle::SolidPattern));
    QRectF rectangle(3,1.5,rectSize,rectSize);//5.2
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(13,10,11));
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawEllipse(rectangle);*/
}
PointShape::~PointShape()
{
    delete alarmTimer;
    delete ui;
}
void PointShape::setPriority(int prio) {
    rectSize = prio;
    update();
}

QString PointShape::getStateString()
{
    return state->getName();
}

void PointShape::enterEvent(QEvent *event){QWidget::enterEvent(event); emit mouseOver();}

void PointShape::setState(CustomState& newState)
{
    state = &newState;
    setColor(state->getColor());
    update();
}

void PointShape::setColor(const QColor& clr) {
    ui->widgetCon->setStyleSheet("#statusWidget{background-color: "+clr.name(QColor::HexRgb)+";}");
    QColor textClr = clr;
    short sign = 1;
    if(clr.blue()+clr.red()+clr.green()<350) sign=-1;
    textClr.setBlue(minCompare(255,clr.blue()-(120*sign)));
    textClr.setRed(minCompare(255,clr.red()-(120*sign)));
    textClr.setGreen(minCompare(255,clr.green()-(120*sign)));
    ui->label->setStyleSheet("color: "+textClr.name(QColor::HexRgb)+";padding-left: 3px; padding-right: 3px;");
    ui->label->setText(state->getName());
}
