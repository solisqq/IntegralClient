#include "inputeditdialog.h"
#include "ui_inputeditdialog.h"

InputEditDialog::InputEditDialog(Inputs &_input, int count, QWidget *parent) :
    QDialog(parent),
    input(&_input),
    itemsCount(count),
    ui(new Ui::InputEditDialog)
{
    ui->setupUi(this);
    ui->nameLineEdit->setText(input->getName());

    for(int i=1; i<count;i++)
        ui->idComboBox->addItem(QString::number(i));

    ui->idComboBox->setCurrentIndex(input->getInputID());
    ui->typeComboBox->setCurrentIndex(static_cast<int>(input->getSensorType()));
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

InputEditDialog::~InputEditDialog()
{
    delete ui;
}

void InputEditDialog::on_buttonBox_accepted()
{
    //if(ui->idLineEdit->text().toInt()>=0 && ui->idLineEdit->text().toInt()<=itemsCount)
    input->setup(ui->nameLineEdit->text(), ui->idComboBox->currentIndex()+1, ui->typeComboBox->currentIndex());
}

void InputEditDialog::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    if(!Global::authorization->isAuthorized())
        this->close();

}
