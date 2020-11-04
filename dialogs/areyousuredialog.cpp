#include "areyousuredialog.h"
#include "ui_areyousuredialog.h"

AreYouSureDialog::AreYouSureDialog(QString question, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AreYouSureDialog)
{
    ui->setupUi(this);
    ui->label->setText(question);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    QWidget::activateWindow();
}

AreYouSureDialog::~AreYouSureDialog()
{
    delete ui;
}
