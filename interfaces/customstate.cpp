#include "customstate.h"

int CustomState::getPrio() const
{
    return prio;
}

QColor CustomState::getColor() const
{
    return color;
}

void CustomState::setColor(const QColor &value)
{
    color = value;
}

QString CustomState::getName() const
{
    return name;
}

void CustomState::setName(const QString &value)
{
    name = value;
}

bool CustomState::isEnabled() const
{
    return state;
}

void CustomState::setState(bool value)
{
    state = value;
}

CustomState::CustomState(const QString& stateName, unsigned short RCol, unsigned short GCol, unsigned short BCol, int priority):
    color(RCol,GCol,BCol),
    name(stateName),
    prio(priority)
{
}

CustomState::CustomState(const QString& stateName, const QColor& stateColor, int priority):
    color(stateColor),
    name(stateName),
    prio(priority)
{
}

CustomState::CustomState(const QString& stateName, const QString& rgbColor, int priority):
    color(rgbColor),
    name(stateName),
    prio(priority)
{
}
