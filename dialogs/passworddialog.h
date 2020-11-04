#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT
    QString pass="";
public:
    explicit PasswordDialog(const QString &password, QWidget *parent = nullptr);
    ~PasswordDialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::PasswordDialog *ui;

signals:
    void passAccepted();
    void passDenied();
    void passCanceled();
};

#endif // PASSWORDDIALOG_H
