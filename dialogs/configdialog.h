#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

#include <QCheckBox>
#include "widgets/pinpoint/pinpoint.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog, public AuthorizationInterface
{
    Q_OBJECT
    PinPoint *point;
    Connection *connection;
    bool forceDeleted=false;
public:
    explicit ConfigDialog(PinPoint* _point, Connection *_connection, QWidget *parent = nullptr);
    ~ConfigDialog();
    void showEvent(QShowEvent *event);
private slots:
    void on_deleteButton_clicked();
    void on_buttonBox_accepted();

private:
    Ui::ConfigDialog *ui;
    void setViewSizeByMapWidget();
};

#endif // CONFIGDIALOG_H
