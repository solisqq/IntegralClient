#include "authorizationinterface.h"
#include <QDebug>
AuthorizationInterface::AuthorizationInterface()
{

}

void AuthorizationInterface::addOnLogIn(QWidget *widget)
{
    widget->hide();
    whenLoggedIn.append(widget);
}

void AuthorizationInterface::setUserLoggedOnInit()
{
    loggedOnInit=true;
}

void AuthorizationInterface::addOnLogOut(QWidget *widget)
{
    widget->show();
    whenLoggedOut.append(widget);
}

void AuthorizationInterface::addOnLogIn(std::initializer_list<QWidget*> widgetList)
{
    for(auto widget : widgetList) {
        if(!loggedOnInit) widget->hide();
        whenLoggedIn.append(widget);
    }
}

void AuthorizationInterface::addOnLogOut(std::initializer_list<QWidget*> widgetList)
{
    for(auto widget : widgetList) {
        widget->show();
        whenLoggedOut.append(widget);
    }
}

void AuthorizationInterface::logIn()
{
    foreach(auto widget, whenLoggedIn) {
        widget->show();
    }
    foreach(auto widget, whenLoggedOut) {
        widget->hide();
    }
}

void AuthorizationInterface::logOut()
{
    foreach(auto widget, whenLoggedIn) {
        widget->hide();
    }
    foreach(auto widget, whenLoggedOut) {
        widget->show();
    }
}

