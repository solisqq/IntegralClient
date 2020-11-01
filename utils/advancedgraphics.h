#ifndef ADVANCEDGRAPHICS_H
#define ADVANCEDGRAPHICS_H
#include <QGraphicsDropShadowEffect>

class AdvancedGraphics
{
    QGraphicsDropShadowEffect *shadow;
    QColor color =  Qt::black;
    QPoint offsets = QPoint(5,5);
    qreal blur=5;
    void fillShadow();
public:
    AdvancedGraphics();
    void setupShadow(QWidget *item, QPoint _offsets = QPoint(5,5), qreal _blur=5, const QColor &_color = Qt::black);
signals:

public slots:
};

#endif // ADVANCEDGRAPHICS_H
