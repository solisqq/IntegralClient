#ifndef CUSTOMSTATE_H
#define CUSTOMSTATE_H
#include <QColor>
#include <QString>

class CustomState
{
    QColor color;
    QString name;
    bool state=false;
    int prio=0;
public:
    CustomState(const QString& stateName, unsigned short RCol, unsigned short GCol, unsigned short BCol, int priority=0);
    CustomState(const QString& stateName, const QColor& stateColor, int priority=0);
    CustomState(const QString& stateName, const QString& rgbColor, int priority=0);
    QColor getColor() const;
    void setColor(const QColor &value);
    QString getName() const;
    void setName(const QString &value);
    int getPrio() const;
    bool isEnabled() const;
    void setState(bool value);
};

#endif // CUSTOMSTATE_H
