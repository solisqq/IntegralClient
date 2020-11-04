#include "statehandler.h"

CustomState *StateHandler::getCurrentState() const{
    return currentState;
}
CustomState *StateHandler::getPrevState() const{return prevState;}
QColor StateHandler::getCurrentStateColor(){return currentState->getColor();}
QString StateHandler::getCurrentStateName(){return currentState->getName();}

void StateHandler::enableDualMode()
{
    dualMode=true;
}

void StateHandler::enablePrioMode()
{
    prioMode=true;
}

StateHandler::StateHandler(){}
StateHandler::~StateHandler(){
    foreach(CustomState* customState, availableStates) {
        availableStates.removeOne(customState);
    }
}
void StateHandler::addState(const QString& name, const QColor& color, int priority)
{
    CustomState* toAdd = new CustomState(name,color, priority);
    if(currentState==nullptr)
        currentState = toAdd;
    availableStates.append(toAdd);
}

void StateHandler::addState(CustomState &newState)
{
    if(currentState==nullptr)
        currentState = &newState;
    availableStates.append(&newState);
}

bool StateHandler::setState(CustomState &stateToChange, bool dualState)
{
    if(dualMode) {
        stateToChange.setState(dualState);
        if(stateToChange.isEnabled()) {
            if(stateToChange.getPrio()>currentState->getPrio() || currentState->isEnabled()==false) {
                prevState = currentState;
                currentState = &stateToChange;
            } else return false;
        } else return false;
    }
    if(prioMode) {
        if(stateToChange.getPrio()>currentState->getPrio()) {
            prevState = currentState;
            currentState = &stateToChange;
        } else return false;
    }
    else {
        if(&stateToChange==currentState) return false;
        prevState = currentState;
        currentState = &stateToChange;
    }
    return true;
}
