#ifndef MENUELEMENT_H
#define MENUELEMENT_H

#include "clickableicon.h"
#include <QWidget>
class MenuElement
{
protected:
    ClickableIcon menuIcon;
public:
    MenuElement(QString iconRsrc, QWidget *parent=nullptr, QString text="", QString colorInHexWithSlash="#282828", QString _textColor="#cccccc", QString _textSize="11");
    virtual ~MenuElement();
    ClickableIcon* getIcon();
    virtual QWidget* getView()=0;
};

#endif // MENUELEMENT_H
