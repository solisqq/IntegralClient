#ifndef AUTHORIZATIONINTERFACE_H
#define AUTHORIZATIONINTERFACE_H

#include <QList>
#include <QWidget>

class AuthorizationInterface
{
    QList<QWidget*> whenLoggedIn;
    QList<QWidget*> whenLoggedOut;
    bool loggedOnInit=false;
public:
    AuthorizationInterface();
    void addOnLogOut(std::initializer_list<QWidget *>);
    void logIn();
    void logOut();
    void addOnLogIn(std::initializer_list<QWidget *>);
    void addOnLogOut(QWidget *widget);
    void addOnLogIn(QWidget *widget);
    void setUserLoggedOnInit();
};

#endif // AUTHORIZATIONINTERFACE_H
