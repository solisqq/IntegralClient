#ifndef CONVERTER_H
#define CONVERTER_H

#include <QPoint>
#include <QSize>
#include <QDebug>


class Converter
{
public:
    Converter();
    static QPointF toCurrent(QPoint currentRes, QPoint defaultRes, QPointF point);
    static QPointF toCurrent(QSize currentRes, QSize defaultRes, QPointF point);
    static QPointF toDefault(QSize currentRes, QSize defaultRes, QPointF point);
    static QPointF toDefault(QPoint currentRes, QPoint defaultRes, QPointF point);
    static QPoint toPointToMiddle(const QPointF &point, const QSize &size);
    static QPoint sizeToPoint(QSize size);
    //template<class T> static QString listToString(const QList<T>&, char splitter);
};

#endif // CONVERTER_H
