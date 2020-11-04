#include "malfunction.h"
#include "ui_malfunction.h"


Malfunction::Malfunction(QString name, QWidget *parent) :
    QWidget(parent),
    warning("Błąd centrali", QColor(255,204,0)),
    ok("Brak błędu", QColor(204,0,0)),
    ui(new Ui::Malfunction)
{
    ui->setupUi(this);
    setName(name);
    ui->checkBox->setLayoutDirection(Qt::RightToLeft);
}

Malfunction::~Malfunction()
{
    delete ui;
}

void Malfunction::setName(const QString &text)
{
    ui->checkBox->setText(text);
}

bool Malfunction::getState() {
    return ui->checkBox->isChecked();
}

bool Malfunction::setState(bool state) //RETURNS true if state has changed
{
    if(state==ui->checkBox->isChecked()) return false;
    ui->checkBox->setChecked(state);
    if(state) return true;
}


