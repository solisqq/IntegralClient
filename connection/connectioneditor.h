#ifndef CONNECTIONEDITOR_H
#define CONNECTIONEDITOR_H

#include <QWidget>
#include "interfaces/editorfunctions.h"
#include "widgets/menuelement.h"

namespace Ui {
class ConnectionEditor;
}

class ConnectionEditor : public QWidget, public MenuElement
{
    Q_OBJECT
    EditorFunctions::Adder pAdder;
    EditorFunctions::Setter pSetter;

public:
    explicit ConnectionEditor(QWidget *parent = nullptr);
    ~ConnectionEditor() override;

    EditorFunctions::Adder& getAdder();
    EditorFunctions::Setter& getSetter();

public slots:
    void setupPoint();

private:
    Ui::ConnectionEditor *ui;

    // MenuElement interface
public:
    QWidget *getView() override;
};

#endif // CONNECTIONEDITOR_H
