#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(const QString &password, QWidget *parent) :
    QDialog(parent),
    pass(password),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->widget_3->setObjectName("passworddialog");
    QWidget::activateWindow();
    //setAttribute(Qt::WA_NoSystemBackground);
    //setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_PaintOnScreen);
}

PasswordDialog::~PasswordDialog(){delete ui;}
void PasswordDialog::on_pushButton_clicked()
{
    if(ui->passwordEdit->text()!=pass)
        emit passDenied();
    else
        emit passAccepted();
    this->hide();
    ui->passwordEdit->setText("");
}

void PasswordDialog::on_pushButton_2_clicked()
{
    this->hide();
    emit passCanceled();
    ui->passwordEdit->setText("");
}
