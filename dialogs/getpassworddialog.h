#ifndef GETPASSWORDDIALOG_H
#define GETPASSWORDDIALOG_H

#include <QDialog>

#include <interfaces/functiontemplate.h>

namespace Ui {
class GetPasswordDialog;
}

class GetPasswordDialog : public QDialog
{
    Q_OBJECT
    bool accessFunct = false;
public:
    explicit GetPasswordDialog(QWidget *parent = nullptr);
    ~GetPasswordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GetPasswordDialog *ui;
signals:
    void passwordProvided(const QString& password);

};

#endif // GETPASSWORDDIALOG_H
