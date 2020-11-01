#include "zoneeditdialog.h"
#include "ui_zoneeditdialog.h"
#include "areyousuredialog.h"

ZoneEditDialog::ZoneEditDialog(Zone* zoneToEdit, QWidget *parent) :
    QDialog(parent),
    zone(zoneToEdit),
    ui(new Ui::ZoneEditDialog)
{
    ui->setupUi(this);
    connect(ui->alarmOffBtn, &QPushButton::clicked, this, &ZoneEditDialog::alarmOffHandle);
    connect(ui->armOnBtn, &QPushButton::clicked, this, &ZoneEditDialog::armHandle);
    connect(ui->armOffBtn, &QPushButton::clicked, this, &ZoneEditDialog::unarmHandle);

    ui->zoneNameLineEdit->setText(zone->getName());
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    Global::authorization->addInterface(this);
    AuthorizationInterface::addOnLogIn({ui->widget_3});
}

ZoneEditDialog::~ZoneEditDialog()
{
    delete ui;
}

void ZoneEditDialog::on_buttonBox_accepted()
{
    zone->setName(ui->zoneNameLineEdit->text());
}

void ZoneEditDialog::alarmOffHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz skasować alarm w tej strefie?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZoneEditDialog::alarmOffHandle_ok);
}

void ZoneEditDialog::armHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz uzbroić tę strefę?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZoneEditDialog::armHandle_ok);
}

void ZoneEditDialog::unarmHandle()
{
    auto dialog = new AreYouSureDialog("Czy na pewno chcesz rozbroić tę strefę?", this);
    dialog->show();
    connect(dialog, &AreYouSureDialog::accepted, this, &ZoneEditDialog::unarmHandle_ok);
}

void ZoneEditDialog::alarmOffHandle_ok() {
    QList<Zone*> list;
    list.append(zone);
    emit(alarmOffEmited(list));
}

void ZoneEditDialog::armHandle_ok() {
    QList<Zone*> list;
    list.append(zone);
    emit(armEmited(list));
    qDebug()<<"test";
}

void ZoneEditDialog::unarmHandle_ok() {
    QList<Zone*> list;
    list.append(zone);
    emit(unarmEmited(list));
}
