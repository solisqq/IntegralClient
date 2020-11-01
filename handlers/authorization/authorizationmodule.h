#ifndef AUTHORIZATIONMODULE_H
#define AUTHORIZATIONMODULE_H

#include <QObject>
#include <dialogs/passworddialog.h>
#include <handlers/errorHandler/errorable.h>

class AuthorizationModule : public QObject, public ErrorAble
{
    Q_OBJECT
    PasswordDialog *passDialog;
    QString password = "zalfon19";
    bool logged = true;
    QWidget *parentWidget=nullptr;
public:
    explicit AuthorizationModule(QObject *parent = nullptr, QWidget *_parentWidget = nullptr);
    bool isUserAuthorized();
    void authorizeUser();
    void unauthorize();
signals:
    void Login();
    void Logout();

private slots:
    void onValidPassProvided();
    void onInvalidPassProvided();
};

#endif // AUTHORIZATIONMODULE_H
