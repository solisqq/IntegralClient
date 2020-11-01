#include "loggerdialog.h"
#include "ui_loggerdialog.h"

LoggerDialog::LoggerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggerDialog)
{
    ui->setupUi(this);
}

LoggerDialog::~LoggerDialog()
{
    delete ui;
}
