#include "settingswidget.h"
#include "ui_settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent),
    MenuElement(":/icons/img/settings.png", nullptr, "Settings"),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
    connect(ui->saveBtn, &QPushButton::clicked, &settings, &Settings::save);
    QList<SETUP::BY_STRING_EDITABLE*>::iterator it;
    for(it=settings.getInterface().variables.begin(); it!=settings.getInterface().variables.end(); ++it) {
        FormWidget* formToAdd = new FormWidget(it.i->t()->getName(),it.i->t()->toString());
        ui->contentWidget->layout()->addWidget(formToAdd);
        formToAdd->setParent(ui->contentWidget);
        it.i->t()->addHandler(formToAdd->getField(), ui->setBtn);
    }
}

QWidget *SettingsWidget::getView() {return this;}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}
