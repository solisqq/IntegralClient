#include "getpassworddialog.h"
#include "ui_getpassworddialog.h"

GetPasswordDialog::GetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetPasswordDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

GetPasswordDialog::~GetPasswordDialog()
{
    delete ui;
}

void GetPasswordDialog::on_buttonBox_accepted()
{
    emit(passwordProvided(ui->lineEdit->text()));
}
