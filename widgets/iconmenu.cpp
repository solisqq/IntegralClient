#include "iconmenu.h"
#include "ui_iconmenu.h"

QList<MenuElement *> &IconMenu::getElements()
{
    return elements;
}

IconMenu::IconMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IconMenu)
{
    ui->setupUi(this);
}

IconMenu::~IconMenu()
{
    delete ui;
}

void IconMenu::addMenuElement(MenuElement* elementToAdd)
{
    elements.append(elementToAdd);
    ui->iconLayout->addWidget(elementToAdd->getIcon());
}
