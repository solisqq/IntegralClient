#include "connectioneditor.h"
#include "ui_connectioneditor.h"

#include <dialogs/configdialog.h>

ConnectionEditor::ConnectionEditor(QWidget *parent) :
    QWidget(parent),
    MenuElement(":/icons/img/add.png", this, "Add point"),
    ui(new Ui::ConnectionEditor)
{
    ui->setupUi(this);
    connect(this->getIcon(), &ClickableIcon::clicked, &pAdder, &EditorFunctions::Adder::SwitchStateEvent);
}

ConnectionEditor::~ConnectionEditor()
{
    delete ui;
}

EditorFunctions::Adder &ConnectionEditor::getAdder()
{
    return pAdder;
}

EditorFunctions::Setter &ConnectionEditor::getSetter()
{
    return pSetter;
}

void ConnectionEditor::setupPoint()
{
    if(pAdder.state) return;
    auto *pin = qobject_cast<PinPoint*>(sender());
    auto *dialog = new ConfigDialog(pin, &pin->getConnection(), this->parentWidget());
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    dialog->show();
}

QWidget *ConnectionEditor::getView()
{
    return this;
}
