#ifndef ZONESLISTWIDGET_H
#define ZONESLISTWIDGET_H

#include <QTimer>
#include <QWidget>
#include <interfaces/masscontrolwidget.h>
#include "zone.h"
#include "settings.h"
namespace Ui {
class ZonesListWidget;
}

class ZonesListWidget : public QWidget, public StateHandler, public AuthorizationInterface
{
    Q_OBJECT
    int zonesCount = 8;
    QList<Zone*> zones;
    QTimer *updateTimer;
    QString infoString="Brak połączenia.";
    bool authorizationNeeded=false;
    bool connection = false;
    bool malfunction = false;
public:
    CustomState unarmed;
    CustomState partArmed;
    CustomState armed;
    CustomState silentAlarm;
    CustomState alarm;
    CustomState disconnected;
    explicit ZonesListWidget(QWidget *parent = nullptr);
    ~ZonesListWidget();
    void setupZones(const QStringList &names);
    QString getInfoString() const;
    int getZonesCount() const;
    QStringList getZonesNames();
    void setAuthorizationNeeded(bool auth);
    MassControlWidget controlls;

    QString getPassword() const;
public slots:
    void updateAlarms(const QList<int>& items);
    void updateSilentAlarms(const QList<int>& items);
    void updateArm(const QList<int>& items);

    void connectionLost(bool isLost);
signals:
    void stateChanged(CustomState *state, const QList<Zone*> source);
    void unarm(QList<Zone*>& zones);
    void dealarm(QList<Zone*>& zones);
    void arm(QList<Zone*>& zones);
    void editZoneEmited(Zone* zone);
    void updateDB();

private slots:
    void updateStates();
    void armHandle();
    void dealarmHandle();
    void unarmHandle();
    void on_addZoneBtn_clicked();

    void on_subZoneBtn_clicked();

    void on_keyLineEdit_textChanged(const QString &arg1);

    void dealarmHandle_ok();
    void unarmHandle_ok();
    void armHandle_ok();
private:
    Ui::ZonesListWidget *ui;
};

#endif // ZONESLISTWIDGET_H
