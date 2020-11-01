#ifndef EDITORFUNCTIONS_H
#define EDITORFUNCTIONS_H

#include "editorinterface.h"
#include "widgets/pinpoint/pinpoint.h"
#include <QApplication>
#include <QPushButton>

class EditorFunctions
{
public:
    class Adder : public EditorInterface {
    public:
        void MouseOverEnter();
        void MouseOverLeave();
        void TurnOff() override;
    };

    class Setter : public EditorInterface {
    public:
        PinPoint *focusable=nullptr;
    public slots:
        void TurnOff() override;
        //void SetFocus(PinPoint *point);
    };
};

#endif // EDITORFUNCTIONS_H
