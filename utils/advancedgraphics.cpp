#include "advancedgraphics.h"
#include <QWidget>

AdvancedGraphics::AdvancedGraphics() : shadow(new QGraphicsDropShadowEffect){
    fillShadow();
}
void AdvancedGraphics::fillShadow() {
    shadow->setBlurRadius(blur);
    shadow->setXOffset(offsets.x());
    shadow->setYOffset(offsets.y());
    shadow->setColor(color);
}
void AdvancedGraphics::setupShadow(QWidget *item, QPoint _offsets, qreal _blur, const QColor &_color)
{
    offsets = _offsets;
    blur = _blur;
    color = _color;
    fillShadow();
    item->setGraphicsEffect(shadow);
}
