#include "editorfunctions.h"

#include <QDebug>
void EditorFunctions::Adder::MouseOverEnter()  {

    if(state) QApplication::setOverrideCursor(Qt::CrossCursor);
}
void EditorFunctions::Adder::MouseOverLeave() {
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}

void EditorFunctions::Adder::TurnOff() {
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    EditorInterface::TurnOff();
}

//---Deleter--
void EditorFunctions::Setter::TurnOff()
{
    state=false;
    if(focusable!=nullptr)
        focusable->hide();
}

