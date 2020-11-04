#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include "customstate.h"
#include <QList>


class StateHandler
{
    QList<CustomState*> availableStates;
    CustomState* currentState=nullptr;
    CustomState* prevState=nullptr;
    bool dualMode=false;
    bool prioMode=false;
public:
    StateHandler();
    virtual ~StateHandler();
    void addState(const QString &name, const QColor &color, int priority=0);
    void addState(CustomState& newState);
    virtual bool setState(CustomState& stateToChange, bool dualState=false);
    CustomState *getCurrentState() const;
    CustomState *getPrevState() const;
    QColor getCurrentStateColor();
    QString getCurrentStateName();
    void enableDualMode();
    void enablePrioMode();
};

#endif // STATEHANDLER_H
