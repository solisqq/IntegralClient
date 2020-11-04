#include "tinyinput.h"
#include "ui_tinyinput.h"

TinyInput::TinyInput(int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TinyInput)
{
    ui->setupUi(this);
    ui->indicatorBox->setDisabled(true);
    setID(id);
}

TinyInput::~TinyInput()
{
    delete ui;
}

void TinyInput::setID(int id)
{
    cid=id;
    ui->idLabel->setText(QString::number(id));
}

int TinyInput::getID()
{
    return cid;
}

bool TinyInput::getState()
{
    return ui->indicatorBox->isChecked();
}

void TinyInput::setState(bool toChange)
{
    ui->indicatorBox->setChecked(toChange);
}
