#include "formwidget.h"
#include "ui_formwidget.h"

FormWidget::FormWidget(const QString &name, const QString &defaultVal, QWidget *parent):
QWidget(parent),
  ui(new Ui::FormWidget)
{
  ui->setupUi(this);
  ui->label->setText(name);
  ui->lineEdit->setText(defaultVal);
}

FormWidget::~FormWidget()
{
    delete ui;
}

QLineEdit *FormWidget::getField()
{
    return ui->lineEdit;
}
