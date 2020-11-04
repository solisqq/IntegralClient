#include "authorizationmodule.h"

AuthorizationModule::AuthorizationModule(QObject *parent, QWidget *_parentWidget) :
    QObject(parent),
    parentWidget(_parentWidget)
{
    passDialog = new PasswordDialog(password, parentWidget);
}

bool AuthorizationModule::isUserAuthorized(){return logged;}
void AuthorizationModule::unauthorize() {
    logged = false;
    emit Logout();
}
void AuthorizationModule::authorizeUser()
{
    passDialog->show();
    connect(passDialog, &PasswordDialog::passAccepted, this, &AuthorizationModule::onValidPassProvided);
    connect(passDialog, &PasswordDialog::passDenied, this, &AuthorizationModule::onInvalidPassProvided);
}

void AuthorizationModule::onValidPassProvided(){logged=true; emit Login();}
void AuthorizationModule::onInvalidPassProvided(){} //change
