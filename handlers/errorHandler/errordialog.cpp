#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(Error &error, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);
    ui->errorText->setText(error.value);
    if(error.priority==Error::Priority::Warning) {
        ui->mainLalbe->setStyleSheet("color: #ead637;"
                                     "font-size:20px;"
                                     "font-weight:500;");
        ui->mainLalbe->setText("Ostrzeżenie");
    } else {
        ui->mainLalbe->setStyleSheet("color: rgb(208, 37, 31);"
                                     "font-size:20px;"
                                     "font-weight:500;");
    }
    ui->sourceLabel->setText(error.source);
    ui->errorText->setWordWrap(true);
    ui->sourceLabel->setWordWrap(true);
    ui->widget->setStyleSheet("border-image: url(:/img/error.png) 0 0 0 0 stretch stretch;");
    err = &error;
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::on_buttonBox_rejected()
{
    //err->clicked=true;
    err->dateAccepted = QDateTime::currentDateTime();
    //Global::logger->add(*err);
}

void ErrorDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    Q_UNUSED(button)
    err->dateAccepted = QDateTime::currentDateTime();
}
