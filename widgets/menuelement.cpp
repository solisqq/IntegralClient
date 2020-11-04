#include "menuelement.h"

MenuElement::MenuElement(QString iconRsrc, QWidget *parent, QString text, QString colorInHexWithSlash, QString _textColor, QString _textSize):
    menuIcon(iconRsrc,parent,text,colorInHexWithSlash,_textColor,_textSize){}

MenuElement::~MenuElement(){}
ClickableIcon* MenuElement::getIcon()
{
    return &menuIcon;
}
