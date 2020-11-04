#ifndef ZONEEDITDIALOG_H
#define ZONEEDITDIALOG_H

#include <QDialog>

#include <widgets/zone.h>
#include "settings.h"
#include <interfaces/authorizationinterface.h>

namespace Ui {
class ZoneEditDialog;
}

class ZoneEditDialog : public QDialog, public AuthorizationInterface
{
    Q_OBJECT
    Zone *zone;
public:
    explicit ZoneEditDialog(Zone* zoneToEdit, QWidget *parent = nullptr);
    ~ZoneEditDialog();

private slots:
    void on_buttonBox_accepted();
    void alarmOffHandle();
    void armHandle();
    void unarmHandle();

    void alarmOffHandle_ok();
    void armHandle_ok();
    void unarmHandle_ok();
private:
    Ui::ZoneEditDialog *ui;

signals:
    void armEmited(QList<Zone*>& zonesToArm);
    void alarmOffEmited(QList<Zone*>& zonesToAlarmOff);
    void unarmEmited(QList<Zone*>& zonesToUnarm);
};

#endif // ZONEEDITDIALOG_H
