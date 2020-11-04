#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    iconMenu(this),
    errorStatusWidget(nullptr),
    settingsWidget(nullptr),
    logdialog(this),
    logger(),
    connectionsWidget(nullptr),

    ui(new Ui::MainMenu)
{
    Global::logger = &logger;
    errorStatusWidget.setDatabase(connectionsWidget.getDatabase());
    ui->setupUi(this);
    ui->menuLayout->addWidget(&iconMenu);
    iconMenu.addMenuElement(&errorStatusWidget);
    iconMenu.addMenuElement(Global::logger);
    iconMenu.addMenuElement(&settingsWidget);
    iconMenu.addMenuElement(connectionsWidget.getEditor());
    iconMenu.addMenuElement(Global::authorization);

    connect(errorStatusWidget.getIcon(), &ClickableIcon::mouseEnter, this, &MainMenu::awakeErrorStatus);
    connect(errorStatusWidget.getIcon(), &ClickableIcon::mouseLeave, this, &MainMenu::hideErrorStatus);
    connect(settingsWidget.getIcon(), &ClickableIcon::mouseEnter, this, &MainMenu::awakeSettingsWidget);
    connect(settingsWidget.getIcon(), &ClickableIcon::mouseLeave, this, &MainMenu::hideSettingsWidget);
    connect(settingsWidget.getIcon(), &ClickableIcon::clicked,this, &MainMenu::setClicked);
    connect(errorStatusWidget.getIcon(), &ClickableIcon::clicked,this, &MainMenu::setClicked);
    connect(Global::authorization->getIcon(), &ClickableIcon::clicked, Global::authorization, &AuthorizationDialog::switchState);
    connect(Global::logger->getIcon(), &ClickableIcon::clicked, &logdialog, &LoggerDialog::show);

    Global::authorization->addInterface(this); //Add this as authorization interface so members may be accessed from authorization dialog
    AuthorizationInterface::addOnLogIn({settingsWidget.getIcon(), connectionsWidget.getEditor()->getIcon()});
}

void MainMenu::showElement(MenuElement* element) {
    clicked=false;
    element->getView()->setParent(ui->contentWidget);
    ui->contentLayout->addWidget(element->getView());
    ui->contentWidget->show();
}
void MainMenu::hideElement(MenuElement* element) {
    if(clicked) return;
    element->getView()->setParent(nullptr);
    ui->contentLayout->removeWidget(element->getView());

    ui->contentWidget->hide();
}

void MainMenu::awakeErrorStatus(){showElement(&errorStatusWidget);}
void MainMenu::hideErrorStatus(){hideElement(&errorStatusWidget);}
void MainMenu::awakeSettingsWidget(){showElement(&settingsWidget);}
void MainMenu::hideSettingsWidget(){hideElement(&settingsWidget);}
void MainMenu::setClicked(){clicked=true;}

MainMenu::~MainMenu(){delete ui;}
