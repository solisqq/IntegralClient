#include "configdialog.h"
#include "ui_configdialog.h"

#include <QMessageBox>

ConfigDialog::ConfigDialog(PinPoint *_point, Connection *_connection, QWidget *parent):
    QDialog(parent),
    point(_point),
    connection(_connection),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    setViewSizeByMapWidget();
    ui->nameEdit->setText(point->getText());
    Global::authorization->addInterface(this);
    AuthorizationInterface::addOnLogIn({ui->label_2, ui->deleteButton, ui->nameEdit});
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setObjectName("configdialog");
    QWidget::activateWindow();
}

ConfigDialog::~ConfigDialog()
{
    Global::authorization->removeInterface(this);
    if(!forceDeleted) {
        ui->connectionLayout->removeWidget(connection);
        connection->setParent(nullptr);
    }
    delete ui;
}

void ConfigDialog::setViewSizeByMapWidget() { //set size in addition to selected map widget, so conteners are smaller
    if(connection->getMapWidget().getBackgroundId()<=settings.contenersCount.get())
        this->setMinimumSize(1100,700);
    else
        this->setMinimumSize(1600,1000);
}

void ConfigDialog::showEvent(QShowEvent *event)
{
    ui->connectionLayout->addWidget(connection);
    QDialog::showEvent(event);
}

void ConfigDialog::on_deleteButton_clicked()
{
    ui->connectionLayout->removeWidget(connection);
    connection->setParent(nullptr);
    forceDeleted = true;
    emit(point->removeMe(point));
    this->close();
}

void ConfigDialog::on_buttonBox_accepted()
{
    point->setName(ui->nameEdit->text());
    connection->updateDataFromGUI();
    emit(point->updateDatabase(*point));
}
