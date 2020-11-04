#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <widgets/menuelement.h>
#include "widgets/formwidget.h"
#include "settings.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget, public MenuElement
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget() override;
    QWidget * getView() override;

private:
    Ui::SettingsWidget *ui;
};

#endif // SETTINGSWIDGET_H
