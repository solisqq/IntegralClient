#include "fastview.h"
#include "ui_fastview.h"

FastView::FastView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FastView)
{
    ui->setupUi(this);
}

FastView::~FastView()
{
    delete ui;
}
