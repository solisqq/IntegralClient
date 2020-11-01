#include "authorizationdialog.h"
#include "infodialog.h"
#include "ui_authorizationdialog.h"

AuthorizationDialog::AuthorizationDialog(QWidget *parent) :
    QDialog(parent),
    MenuElement(":/icons/img/key.png", nullptr, "Zaloguj"),
    ui(new Ui::AuthorizationDialog)
{
    ui->setupUi(this);
    OnLogOut();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

AuthorizationDialog::~AuthorizationDialog()
{
    delete ui;
}

void AuthorizationDialog::addInterface(AuthorizationInterface *interface)
{
    if(isAuthorized()) interface->setUserLoggedOnInit();
    interfaces.append(interface);
}

void AuthorizationDialog::removeInterface(AuthorizationInterface *interface)
{
    interfaces.removeAll(interface);
}

void AuthorizationDialog::OnLogIn()
{
    logged=true;
    foreach(auto interface, interfaces) {
        interface->logIn();
    }
    MenuElement::getIcon()->setIcon(":/icons/img/lock.png");
    MenuElement::getIcon()->setText("Wyloguj");
}

void AuthorizationDialog::OnLogOut()
{
    logged=false;
    foreach(auto interface, interfaces) {
        interface->logOut();
    }
    MenuElement::getIcon()->setIcon(":/icons/img/key.png");
    MenuElement::getIcon()->setText("Zaloguj");
}

void AuthorizationDialog::switchState()
{
    if(logged) OnLogOut();
    else this->show();

}

void AuthorizationDialog::on_buttonBox_accepted()
{
    if(HASLO_INSTALATORA==ui->lineEdit->text()) {
        OnLogIn();
        auto infoDialog = new InfoDialog(InfoDialog::Type::Info, "Autoryzacja", "Poprawnie nadano uprawnienia instalatorskie.", nullptr, true);
        infoDialog->show();
    } else {
        auto infoDialog = new InfoDialog(InfoDialog::Type::Info, "Brak autoryzacji", "Podano błędne hasło do uzyskania uprawnień, nieudaną próbę logowania odnotowano w bazie danych.", nullptr, true);
        infoDialog->show();
    }
    ui->lineEdit->setText("");
}
QWidget *AuthorizationDialog::getView()
{
    return this;
}
bool AuthorizationDialog::isAuthorized() {
    return logged;
}
