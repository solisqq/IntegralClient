#include "errorwidget.h"
#include "ui_errorwidget.h"

errorWidget::errorWidget(Error *_error, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::errorWidget)
{
    ui->setupUi(this);
    error = _error;
    ui->hintLabel->setText(error->hint);
    ui->srcLabel->setText(error->source);
    ui->errorLabel->setText(error->value);

    ui->hintLabel->setWordWrap(true);
    ui->srcLabel->setWordWrap(true);
    ui->errorLabel->setWordWrap(true);

    //this->setMinimumHeight(20);

    if(error->priority==Error::Priority::CriticalError) {
        ui->widget->setStyleSheet("QWidget#widget{font-size: 12px; background-color:#111111; color:#fcf7ff; border:3px solid rgb(193, 14, 17); border-radius: 10px;}");
        ui->typeLabel->setText("Alarm");
        ui->typeLabel->setStyleSheet("color:rgb(193, 14, 17); font-size: 17px; font-weight: 500;");
    } else {
        ui->widget->setStyleSheet("QWidget#widget{font-size: 12px; background-color:#111111; color:#fcf7ff; border:3px solid #ead637; border-radius: 10px;}");
        ui->typeLabel->setText("Ostrzeżenie");
        ui->typeLabel->setStyleSheet("color: #ead637; font-size: 17px; font-weight: 500;");
    }
}

errorWidget::~errorWidget()
{
    delete ui;
}
