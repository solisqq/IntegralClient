#ifndef ICONMENU_H
#define ICONMENU_H

#include "clickableicon.h"
#include "menuelement.h"

#include <QWidget>

namespace Ui {
class IconMenu;
}

class IconMenu : public QWidget
{
    Q_OBJECT
    bool deleted=false;
    QList<MenuElement*> elements;
protected:
    QList<MenuElement*>& getElements();
public:
    explicit IconMenu(QWidget *parent = nullptr);
    ~IconMenu();
    void addMenuElement(MenuElement*);

private:
    Ui::IconMenu *ui;
};

#endif // ICONMENU_H
