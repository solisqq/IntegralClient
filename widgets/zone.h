#ifndef ZONE_H
#define ZONE_H

#include <QWidget>
#include <interfaces/statehandler.h>

namespace Ui {
class Zone;
}

class Zone : public QWidget, public StateHandler
{
    Q_OBJECT
    CustomState unarmed;
    CustomState armed;
    CustomState alarm;
    CustomState silentAlarm;
public:
    explicit Zone(int id=0, QWidget *parent = nullptr, const QString& name="");
    ~Zone() override;
    void setId(int id);

    bool isAlarm();
    bool isSilent();
    bool isArmed();
    void updateGUI();
    void setName(const QString &name);
    QString getId();
    QString getName();
private:
    Ui::Zone *ui;

signals:
    void editZoneEmitted(Zone* zone);

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    bool setAlarm(bool _state);
    bool setSilentAlarm(bool _state);
    bool setArm(bool _state);
};

#endif // ZONE_H
