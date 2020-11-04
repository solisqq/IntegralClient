#include "converter.h"

Converter::Converter()
{

}
QPointF Converter::toDefault(QPoint currentRes, QPoint defaultRes, QPointF point)
{
    QPointF toRet;
    toRet.setX(defaultRes.x() * (point.x() / currentRes.x()));
    toRet.setY(defaultRes.y() * (point.y() / currentRes.y()));
    return toRet;
}

QPoint Converter::toPointToMiddle(const QPointF &point, const QSize &size)
{
    //QPoint point = QPoint(static_cast<int>(position.x()+0.5)- (size().width()/2),static_cast<int>(position.y()+0.5)- size().height()+10);
    QPoint toRet = QPoint(static_cast<int>(point.x()+0.5)- (size.width()/2),static_cast<int>(point.y()+0.5)- size.height()+20);
    return toRet;
}


QPoint Converter::sizeToPoint(QSize size)
{
    return QPoint(size.width(), size.height());
}

QPointF Converter::toCurrent(QPoint currentRes, QPoint defaultRes, QPointF point)
{
    QPointF toRet;
    toRet.setX((currentRes.x() * point.x()) / defaultRes.x());
    toRet.setY((currentRes.y() * point.y()) / defaultRes.y());
    return toRet;
}

QPointF Converter::toCurrent(QSize currentRes, QSize defaultRes, QPointF point)
{
    QPoint c = QPoint(currentRes.width(),currentRes.height());
    QPoint d = QPoint(defaultRes.width(),defaultRes.height());
    return toCurrent(c, d, point);
}

QPointF Converter::toDefault(QSize currentRes, QSize defaultRes, QPointF point)
{
    QPoint c = QPoint(currentRes.width(),currentRes.height());
    QPoint d = QPoint(defaultRes.width(),defaultRes.height());
    return toDefault(c, d, point);
}
/*
template<class T>
QString Converter::listToString(const QList<T>& list, char splitter) {
    QString toRet="";
    for(auto item : list) {
        toRet+=QString::number(item);
        toRet+=splitter;
    }
    toRet.chop(1);
    return toRet;
}*/
