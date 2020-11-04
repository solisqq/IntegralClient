#ifndef POINTSHAPE_H
#define POINTSHAPE_H

#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include <interfaces/customstate.h>
#include "settings.h"

namespace Ui {
class PointShape;
}

class PointShape : public QWidget
{
    Q_OBJECT

public:
    explicit PointShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~PointShape();
    CustomState *state=nullptr;
    void setState(CustomState& newState);
    QTimer *alarmTimer;
    void setPriority(int prio);
    QString getStateString();
    void enterEvent(QEvent *event);
    CustomState defaultState;
    void setColor(const QColor &clr);
private:
    int rectSize = 22;
    Ui::PointShape *ui;
signals:
    void mouseOver();
};

#endif // POINTSHAPE_H
