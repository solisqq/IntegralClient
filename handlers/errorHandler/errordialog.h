#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H
#include <QAbstractButton>
#include <QDialog>
#include "error.h"
#include "settings.h"
namespace Ui {
class ErrorDialog;
}

class ErrorDialog : public QDialog
{
    Q_OBJECT
    Error *err;
public:
    explicit ErrorDialog(Error &error, QWidget *parent = nullptr);
    ~ErrorDialog();

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ErrorDialog *ui;
};

#endif // ERRORDIALOG_H
