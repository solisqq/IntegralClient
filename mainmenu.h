#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <handlers/errorHandler/errorstatus.h>
#include <widgets/iconmenu.h>
#include "widgets/menuelement.h"
#include "connections.h"
#include "settingswidget.h"
#include "connection/connectioneditor.h"
#include "handlers/logger/logger.h"
#include "handlers/logger/loggerdialog.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget, public AuthorizationInterface
{
    Q_OBJECT
    IconMenu iconMenu;
    ErrorStatus errorStatusWidget;
    SettingsWidget settingsWidget;
    LoggerDialog logdialog;
    Logger logger;
    bool clicked=false;
public:
    Connections connectionsWidget;
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    void showElement(MenuElement *element);
    void hideElement(MenuElement *element);
private slots:
    void awakeErrorStatus();
    void hideErrorStatus();
    void awakeSettingsWidget();
    void hideSettingsWidget();

    void setClicked();
signals:
    void widthChanged(int width);
};

#endif // MAINMENU_H
