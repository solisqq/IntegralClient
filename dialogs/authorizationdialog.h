#ifndef AUTHORIZATIONDIALOG_H
#define AUTHORIZATIONDIALOG_H

#include <QDialog>
#include <interfaces/authorizationinterface.h>
#include <widgets/menuelement.h>

#define HASLO_INSTALATORA "zalfon19"

namespace Ui {
class AuthorizationDialog;
}

class AuthorizationDialog : public QDialog, public MenuElement
{
    Q_OBJECT
    QList<AuthorizationInterface*> interfaces;
    bool logged=false;
public:
    explicit AuthorizationDialog(QWidget *parent = nullptr);
    ~AuthorizationDialog();
    void addInterface(AuthorizationInterface *interface);
    void removeInterface(AuthorizationInterface *interface);


    bool isAuthorized();
protected:
    QWidget *getView();
public slots:
    void OnLogIn();
    void OnLogOut();
    void switchState();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AuthorizationDialog *ui;
};

#endif // AUTHORIZATIONDIALOG_H
