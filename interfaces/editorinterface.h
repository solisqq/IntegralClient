#ifndef EDITORINTERFACE_H
#define EDITORINTERFACE_H

#include <QPushButton>
#include <QObject>
class EditorInterface : public QObject
{
    Q_OBJECT
public:
    bool state=false;
    QPushButton *button;
    virtual ~EditorInterface(){}
public slots:
    virtual void TurnOn(){state=true;}
    virtual void TurnOff(){state=false;}
    virtual void SwitchStateEvent(){if(state) TurnOff(); else TurnOn();}
};

#endif // EDITORINTERFACE_H
