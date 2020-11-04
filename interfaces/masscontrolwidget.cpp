#include "masscontrolwidget.h"

MassControlWidget::MassControlWidget(QObject *parent) : QObject(parent){}
void MassControlWidget::addControlls(std::initializer_list<QWidget*> controlls) {
    for(auto control : controlls ) {
        widgetsToControl.append(control);
    }
}

MassControlWidget::MassControlWidget(std::initializer_list<QWidget*> list, QObject *parent) : QObject(parent)
{
    for(auto widget : list) {
        widgetsToControl.append(widget);
    }
}

void MassControlWidget::show()
{
    for(auto widget : widgetsToControl) {
        widget->show();
    }
}

void MassControlWidget::hide()
{
    for(auto widget : widgetsToControl) {
        widget->hide();
    }
}

void MassControlWidget::enable()
{
    for(auto widget : widgetsToControl) {
        widget->setEnabled(true);
    }
}

void MassControlWidget::disable()
{
    for(auto widget : widgetsToControl) {
        widget->setDisabled(true);
    }
}


