#include "infodialog.h"
#include "ui_infodialog.h"
#include "settings.h"

InfoDialog::InfoDialog(Type dialogType, QString title, QString msg, QWidget *parent, bool log) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    //color: rgb(255, 53, 56);
    switch (dialogType) {
    case(Type::Info):
        ui->errlabel->setStyleSheet("color: rgb(100, 150, 255);");
        ui->errlabel->setText("Informacja");
        break;
    case(Type::Warning):
        ui->errlabel->setStyleSheet("color: rgb(220,160,20);");
        ui->errlabel->setText("Ostrzeżenie");
        break;
    case(Type::Error):break;
    }
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->titlelabel->setText(title);
    ui->contentlabel->setText(msg);
    if(log) Global::logger->add(msg,"Komunikat: "+title);
    QWidget::activateWindow();
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_accepted()
{

}
